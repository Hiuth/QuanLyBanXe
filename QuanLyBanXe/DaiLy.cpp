#include "DaiLy.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <string>
#include <iostream>

KetNoi* Check_DaiLy = new KetNoi();
Connection* Check_DLy = Check_DaiLy->CheckDatabase();
NodeDaiLy* N_DL;
DaiLy* DAILY = new DaiLy();
CheckDuLieu* DL_DaiLy = new CheckDuLieu();
DaiLy::DaiLy()

{
    this->head = NULL;
    this->tail = NULL;
}

DaiLy::~DaiLy()
{
    
}
void DaiLy::NhapDuLieuThongTinDaiLy()
{
    string TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho;
    cout << "Nhap Thong tin Dai Ly: " << endl;
    cout << "Nhap Ten Dai Ly: "; cin >> TenDaiLy;
    cout << "Nhap Dia Chi: "; cin >> DiaChi;
    cout << "Nhap So Dien Thoai Dai Ly: "; cin >> SDTDaiLy;
    cout << "Nhap Quan: "; cin >> Quan;
    cout << "Nhap Thanh Pho: "; cin >> ThanhPho;

    N_DL = new NodeDaiLy(TenDaiLy, ThanhPho, Quan, DiaChi, SDTDaiLy);
    DAILY->ThemThongTinDaiLy(N_DL);
}
void DaiLy::ThemThongTinDaiLy(NodeDaiLy* p)
{
    try {

        Statement* stmt;
        stmt = Check_DLy->createStatement();
        string TenBang = "DaiLy";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { 
            string TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho;
            TenDaiLy = p->LayTenDaiLy();
            DiaChi = p->LayDiaChi();
            SDTDaiLy = p->LaySDTDaiLy();
            Quan = p->LayQuan();
            ThanhPho = p->LayThanhPho();
            string UpdateTableAccount = "insert into DaiLy(storename, city,distric,address,phonenumber)  Values ('" + TenDaiLy + "','" + DiaChi + "','" + SDTDaiLy + "','" + Quan + "','" + ThanhPho + "');";
            stmt->execute(UpdateTableAccount);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Vui long kiem tra lai du lieu. " << endl;
        }

        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
vector<NodeDaiLy> DaiLy::TimKiemThongTinDaiLy(string ThanhPho,string Quan)
{
    try {
        vector<NodeDaiLy> DaiLyInfoSearch;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM Store WHERE City = '" + ThanhPho + "' and distric = '"+Quan+"'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeDaiLy info(
                to_string(res->getInt("StoreID")),
                res->getString("StoreName"),
                res->getString("City"),
                res->getString("distric"),
                res->getString("Address"),
                res->getString("Phonenumber")
            );
            DaiLyInfoSearch.push_back(info);
        }
        delete stmt;
        delete res;
        return DaiLyInfoSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
        return vector<NodeDaiLy>();
    }
}

