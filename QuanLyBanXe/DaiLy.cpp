#include "DaiLy.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

KetNoi* Check_DaiLy = new KetNoi();
Connection* Check_DLy = Check_DaiLy->CheckDatabase();
NodeDaiLy* N_DL;
DaiLy* DAILY = new DaiLy();
CheckDuLieu* DL_DaiLy = new CheckDuLieu();
DonHang* DH_DL = new DonHang();

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
    string TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho, TrangThai;
    cout << "Nhap Thong tin Dai Ly: " << endl;
    cout << "Nhap Ten Dai Ly: "; cin >> TenDaiLy;
    cout << "Nhap Dia Chi: "; cin >> DiaChi;
    cout << "Nhap So Dien Thoai Dai Ly: "; cin >> SDTDaiLy;
    cout << "Nhap Quan: "; cin >> Quan;
    cout << "Nhap Thanh Pho: "; cin >> ThanhPho;
    TrangThai = "Dang Hoat Dong";

    N_DL = new NodeDaiLy(TenDaiLy, ThanhPho, Quan, DiaChi, SDTDaiLy,TrangThai);
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
            string TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho,TrangThai;
            TenDaiLy = p->LayTenDaiLy();
            DiaChi = p->LayDiaChi();
            SDTDaiLy = p->LaySDTDaiLy();
            Quan = p->LayQuan();
            ThanhPho = p->LayThanhPho();
            TrangThai = p->LayTrangThaiHoatDong();
            string UpdateTableAccount = "insert into Store(StoreName, City,distric,Address,PhoneNumber,TrangThai) Values ('" + TenDaiLy + "','" + DiaChi + "','" + SDTDaiLy + "','" + Quan + "','" + ThanhPho + "','"+TrangThai+"');";
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
    string MaDaiLy, TenDaiLy, DiaChi, SDTDaiLy, Quan, ThanhPho,trangthai;
    cout << "Nhap Quan: "; getline(cin,Quan);
    cout << "Nhap Thanh Pho: "; cin >> ThanhPho;
    cin.ignore();
    cout << "Nhap trang thai hoat dong: "; getline(cin,trangthai);

   DAILY->SuaThongTinDaiLy("TrangThai",trangthai,Quan,ThanhPho);
}

void DaiLy::SuaThongTinDaiLy(string ChoCanSua, string MuonDoiThanh, string Quan,string ThanhPho )
{
    try {
        Statement* stmt = Check_DLy->createStatement();
        string UpdateQuery = "UPDATE store SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE City = '" + ThanhPho + "' and distric = '"+Quan+"'";
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
                res->getString("Phonenumber"),
                res->getString("TrangThai")
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
                res->getString("Phonenumber"),
                res->getString("TrangThai")
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

std::vector<NodeDaiLy> DaiLy::XemTatCaThongTinDaiLyVaDoanhThu()
{
    try {
        vector<NodeDaiLy> AllDaiLyInfo;
        string ID;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM Store";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            ID = to_string(res->getInt("StoreID"));
            NodeDaiLy info(
                ID,
                res->getString("StoreName"),
                res->getString("City"),
                res->getString("distric"),
                res->getString("Address"),
                res->getString("Phonenumber"),
                res->getString("TrangThai"),
                DAILY->TongdoanhThuTungDaiLy(ID)
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
        cout << "Trang thai: " << daiLy.LayTrangThaiHoatDong() << endl;
    }
}

void DaiLy::InTTDLvaDT(std::vector<NodeDaiLy> daiLyList)
{
    for (NodeDaiLy& daiLy : daiLyList) {
        cout << "Ma Dai Ly: " << daiLy.LayMaDaiLy() << endl;
        cout << "Ten Dai Ly: " << daiLy.LayTenDaiLy() << endl;
        cout << "Dia Chi: " << daiLy.LayDiaChi() << endl;
        cout << "So Dien Thoai: " << daiLy.LaySDTDaiLy() << endl;
        cout << "Quan: " << daiLy.LayQuan() << endl;
        cout << "Thanh Pho: " << daiLy.LayThanhPho() << endl;
        cout << "Trang thai: " << daiLy.LayTrangThaiHoatDong() << endl;
        cout << "Doanh Thu: " << daiLy.LayTongDoanhthu() << endl;
        cout << endl;
    }
}

long long DaiLy::TongdoanhThuTungDaiLy(string ID)
{
    long long doanhthu = 0;
    vector<NodeDonHang> dh = DH_DL->TimKiemThongTinDonHangTheoDaiLy(ID);
    for (int i = 0; i < dh.size(); i++) {
        doanhthu += dh[i].GetTongGiaTriDonHang();
    }
    return doanhthu;
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
        stmt->executeUpdate(DeleteQuery);
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

vector<NodeKhuyenMai> DaiLy::TimKiemThongTinKhuyenMai(string )
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

void DaiLy::CapNhatTrangThaiDaiLy()
{

}

vector<NodeThanhPho> DaiLy::XemTatCaThanhPho()
{
    try {
        vector<NodeThanhPho> KM;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM City";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeThanhPho info(
                res->getString("ThanhPho")
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

vector<NodeQuan> DaiLy::TimKiemQuanTheoThanhPho(string ThanhPho)
{
    try {
        vector<NodeQuan> KM;
        Statement* stmt = Check_DLy->createStatement();
        string SelectData = "SELECT * FROM Quan where ThanhPho = '"+ThanhPho+"'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeQuan info(
                res->getString("Quan")
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

void DaiLy::InThanhPho(vector<NodeThanhPho> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << "Thanh Pho: " << check[i].LayThanhPho() << endl;
    }
}

void DaiLy::InQuan(vector<NodeQuan> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << "Quan: " << check[i].LayQuan() << endl;
    }
}



