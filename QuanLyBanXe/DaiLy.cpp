#include "DaiLy.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <string>
#include <iostream>
#include <vector>
#include <io.h>
#include <fcntl.h>

using namespace std;

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
            string UpdateTableAccount = "insert into DaiLy(storename, city,distric,address,phonenumber) Values ('" + TenDaiLy + "','" + DiaChi + "','" + SDTDaiLy + "','" + Quan + "','" + ThanhPho + "');";
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

void DaiLy::XoaThongTinDaiLy(string ThanhPho,string Quan )
{
    try {
        Statement* stmt = Check_DLy->createStatement();
        string DeleteQuery = "DELETE FROM Store WHERE City = '" + ThanhPho + "' and distric = '"+Quan+"'";
        stmt->execute(DeleteQuery);
        cout << "Du lieu da duoc xoa!" << endl;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void DaiLy::InputEditDaiLyInfo()
{
    string MaDaiLy, TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho;
    cout << "Nhap Ma Dai Ly can sua: "; cin >> MaDaiLy;
    cout << "Nhap Ten Dai Ly moi: "; cin >> TenDaiLy;
    cout << "Nhap Dia Chi moi: "; cin >> DiaChi;
    cout << "Nhap So Dien Thoai Dai Ly moi: "; cin >> SDTDaiLy;
    cout << "Nhap Quan moi: "; cin >> Quan;
    cout << "Nhap Thanh Pho moi: "; cin >> ThanhPho;

   // DAILY->SuaThongTinDaiLy();
}

void DaiLy::SuaThongTinDaiLy(string ChoCanSua, string MuonDoiThanh, string Quan,string ThanhPho )
{
    try {
        Statement* stmt = Check_DLy->createStatement();
        string UpdateQuery = "UPDATE store SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE City = '" + ThanhPho + "' and distric = '"+ThanhPho+"'";
        stmt->execute(UpdateQuery);
        cout << "Du lieu da duoc cap nhat!" << endl;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void DaiLy::NhapThongTinDaiLyCanTim()
{
    string DiaChi, ThanhPho, Quan;
    cout << "Nhap Dia Chi Can Tim: "; cin >> DiaChi;
    cout << "Nhap Thanh Pho can tim: "; cin >> ThanhPho;
    cout << "Nhap Quan can tim: "; cin >> Quan;

    vector<NodeDaiLy> result = TimKiemThongTinDaiLy( ThanhPho, Quan);
    InTTDL(result);
}
vector<NodeDaiLy> DaiLy::TimKiemThongTinDaiLy( string ThanhPho, string Quan) 
{
    try {
        vector<NodeDaiLy> DaiLyInfoSearch;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM Store WHERE  City = '" + ThanhPho + "' AND distric = '" + Quan + "'";
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


vector<NodeDaiLy> DaiLy::XemTatCaThongTinDaiLy()
{
    try {
        vector<NodeDaiLy> AllDaiLyInfo;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM Store";
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
            AllDaiLyInfo.push_back(info);
        }
        delete stmt;
        delete res;
        return AllDaiLyInfo;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
        return vector<NodeDaiLy>();
    }
}

void DaiLy::InTTDL(vector<NodeDaiLy> daiLyList)
{
    for (NodeDaiLy& daiLy : daiLyList) {
        cout << "Ma Dai Ly: " << daiLy.LayMaDaiLy() << endl;
        cout << "Ten Dai Ly: " << daiLy.LayTenDaiLy() << endl;
        cout << "Dia Chi: " << daiLy.LayDiaChi() << endl;
        cout << "So Dien Thoai: " << daiLy.LaySDTDaiLy() << endl;
        cout << "Quan: " << daiLy.LayQuan() << endl;
        cout << "Thanh Pho: " << daiLy.LayThanhPho() << endl;
    }
}

void DaiLy::ThemThongTinKhuyenMai(NodeKhuyenMai* p)
{
    try {
        Statement* stmt;
        stmt = Check_DLy->createStatement();
        string TenBang = "KhuyenMai";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) {
            string NoiDung = p->LayNoiDung();
            string UpdateTableAccount = "insert into KhuyenMai(NoiDung) Values ('" + NoiDung + "');";
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

void DaiLy::XoaThongTinKhuyenMai(string KM)
{
    try {
        Statement* stmt = Check_DLy->createStatement();
        string DeleteQuery = "DELETE FROM KhuyenMai WHERE MaKM = '" + KM + "'";
        stmt->execute(DeleteQuery);
        cout << "Du lieu da duoc xoa!" << endl;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void DaiLy::SuaThongTinKhuyenMai(string ChoCanSua, string MuonDoiThanh, string MaKhuyenMai)
{
    try {
        Statement* stmt = Check_DLy->createStatement();
        string UpdateQuery = "UPDATE KhuyenMai SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaKM = '"+ MaKhuyenMai +"'";
        stmt->execute(UpdateQuery);
        cout << "Du lieu da duoc cap nhat!" << endl;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeKhuyenMai> DaiLy::TimKiemThongTinKhuyenMai(string)
{

}

vector<NodeKhuyenMai> DaiLy::XemThongtinKhuyenMai()
{
    try {
        vector<NodeKhuyenMai> KM;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM KhuyenMai";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeKhuyenMai info(
                to_string(res->getInt("MaKM")),
                res->getString("NoiDung")
            );
            KM.push_back(info);
        }
        delete stmt;
        delete res;
        return KM;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void DaiLy::InThongTinKhuyenMai(vector<NodeKhuyenMai> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].LayMaKM() << "\t" << check[i].LayNoiDung() << endl;
    }
}


