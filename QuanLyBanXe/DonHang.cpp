#include "DonHang.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <iostream>
#include <string>
#include"DaiLy.h"

using namespace std;

KetNoi* Check_DonHang = new KetNoi();
Connection* Check_DH = Check_DonHang->CheckDatabase();
CheckDuLieu* DL_DH = new CheckDuLieu();
DonHang* DH = new DonHang();
QuanLyXe* QLX = new QuanLyXe();
DonHang* orderManager = new DonHang();
DaiLy* Dai = new DaiLy();
KhachHang* DL_KH = new KhachHang();
DonHang::DonHang() {
    this->head = NULL;
    this->tail = NULL;
}

DonHang::~DonHang() {

}

void DonHang::NhapDuLieuThongTinDonHang() {
    string  MaDonHang, sdt, NgayDatHang, NgayGiaoHangDuKien, TrangThaiDonHang, PhuongThucThanhToan, storeID, MaXe, MaCauHinh, MauXe,LoaiPin,thanhpho, quan,email;
    long long TongGiaTriDonHang;
    vector<NodeCauHinhXe> cauhinh;
    vector<NodeDaiLy> dl;
    cout << "Nhap email: "; cin >> email;
    cin.ignore();
        cout << "Nhap So Dien Thoai: "; getline(cin, sdt);
        if (DL_DH->CheckSDT(sdt)) {
            cout << "Ngay Dat Hang: "; cin >> NgayDatHang;
            cout << "Ngay Giao Hang Du Kien: "; cin >> NgayGiaoHangDuKien;
            TrangThaiDonHang = "DangXuLy";
            cout << "Ma Xe: "; cin >> MaXe;
            cin.ignore();
            cout << "Nhap vao mau sac: "; getline(cin, MauXe);
            cout << "Nhap vao loai pin: "; cin >> LoaiPin;
            cauhinh = QLX->TimMaCauHinh(MaXe, MauXe, LoaiPin);
            MaCauHinh = cauhinh[0].LayMaCauhinhXe();
            cout << MaCauHinh << endl;
            TongGiaTriDonHang = DH->TongGiaTriDonHang(MaXe, MauXe, LoaiPin);
            cin.ignore();
            cout << "Nhap thanh pho: "; getline(cin, thanhpho);
            cout << "Nhap quan: "; getline(cin, quan);
            dl = Dai->TimKiemThongTinDaiLy(thanhpho, quan);
            storeID = dl[0].LayMaDaiLy();
            cout << "Phuong Thuc Thanh Toan: "; getline(cin, PhuongThucThanhToan);
            NodeDonHang* newDonHang = new NodeDonHang(sdt, MaCauHinh, MaXe, NgayDatHang, NgayGiaoHangDuKien, TongGiaTriDonHang, TrangThaiDonHang, PhuongThucThanhToan, storeID,email);
            ThemThongTinDonHang(newDonHang);
            cout << "Nhap don hang thanh cong!" << endl;
        }
        else {
            cout << "So Dien Thoai khong ton tai! Vui long kiem tra lai." << endl;
        }
}


void DonHang::ThemThongTinDonHang(NodeDonHang* p) {
    try {
        Statement* stmt = Check_DH->createStatement();
        string TenBang = "DonHang";
        string KiemTra = "SHOW TABLES LIKE '" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next()) {
            string MaDonHang = p->GetMaDonHang();
            string sdt = p->GetSDT();
            string NgayDatHang = p->GetNgayDatHang();
            string NgayGiaoHangDuKien = p->GetNgayGiaoHangDuKien();
            long long TongGiaTriDonHang = p->GetTongGiaTriDonHang();
            string TrangThaiDonHang = p->GetTrangThaiDonHang();
            string MaXe = p->GetMaXe();
            string MaCauHinh = p->GetMaCauHinh();
            string PhuongThucThanhToan = p->GetPhuongThucThanhToan();
            string StoreID = p->LayMaCuaHang();
            string Email = p->LayTaiKhoanKhachHang();
            string UpdateTableOder = "INSERT INTO DonHang (sdt, MaCauHinh, MaXe, NgayDatHang, NgayGiaoHangDuKien, TongGiaTriDonHang, TrangThaiDonHang, PhuongThucThanhToan,storeID,UserEmail) "
                "VALUES ('" + sdt + "', '" + MaCauHinh + "', '" + MaXe + "', '"+NgayDatHang+ "', '" + NgayGiaoHangDuKien + "', '" +to_string(TongGiaTriDonHang)+ "', '" +TrangThaiDonHang+ "', '" + PhuongThucThanhToan + "','"+StoreID+"','"+Email+"')";
            stmt->execute(UpdateTableOder);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Vui long kiem tra lai du lieu." << endl;
        }

        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

void DonHang::check_TGT()
{
    string mausac, loaipin, maxe;
    cout << "Nhap mau sac: "; getline(cin, mausac);
    cout << "Nhap loai pin: "; getline(cin, loaipin);
    cout << "Nhap ma xe: "; getline(cin, maxe);
    cout << "Tong gia tri don dat hang: " << TongGiaTriDonHang(maxe, mausac, loaipin)<<endl;
}

long long DonHang::TongGiaTriDonHang(string MaXe,string MauSac,string LoaiPin)
{
    vector<NodeXe> p1; 
    vector<NodeCauHinhXe> p2;
    p1 = QLX->TimKiemThongTinXe("MaXe",MaXe);
    p2 = QLX->TimMaCauHinh(MaXe,MauSac,LoaiPin);
    long long tonggia = stoll(p1[0].LayGiaTien()) + stoll(p2[0].LayGiaPin());
    return tonggia;
}

void DonHang::Xoa()
{
    string donhang;
    cout << "Nhap ma don hang can xoa: "; cin >> donhang;
    if (DL_DH->CheckOderID(donhang)) {
        DH->XoaThongTinDonHang(donhang);
    }
    else {
        cout << "Vui long kiem tra lai du lieu." << endl;
    }

}
void DonHang::XoaThongTinDonHang(string email)
{
    Statement* stmt;
    stmt = Check_DH->createStatement();
    string deleteOrder = "DELETE FROM DonHang WHERE UserEmail = '" + email + "'";
    int rows_affected = stmt->executeUpdate(deleteOrder);
    if (rows_affected > 0) {
        cout << "Xoa don hang thanh cong!" << endl;
    }
    else {
        cout << "Khong tim thay don hang !" << endl;
    }
    delete stmt;
}
vector<NodeDonHang> DonHang::XemTatCaThongTinDonHang() {
    try {
        vector<NodeDonHang> danhSachDonHang;
        Statement* stmt;
        stmt = Check_DH->createStatement();
        string selectQuery = "SELECT * FROM DonHang";
        ResultSet* res = stmt->executeQuery(selectQuery);
        while (res->next()) {
            NodeDonHang donHang(
                to_string(res->getInt("MaDonHang")),
                res->getString("SDT"),
                to_string(res->getInt("MaCauHinh")),
                res->getString("MaXe"),
                res->getString("NgayDatHang"),
                res->getString("NgayGiaoHangDuKien"),
                static_cast<long long>(res->getDouble("TongGiaTriDonHang")),
                res->getString("TrangThaiDonHang"),
                res->getString("PhuongThucThanhToan"),
                to_string(res->getInt("storeID")),
                res->getString("UserEmail")
            );
            danhSachDonHang.push_back(donHang);
        }
        delete stmt;
        delete res;
        return danhSachDonHang;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }

}
vector<NodeDonHang> DonHang::GioHang(string email)
{
    try {
        vector<NodeDonHang> danhSachDonHang;
        Statement* stmt;
        stmt = Check_DH->createStatement();
        string selectQuery = "SELECT * FROM DonHang where UserEmail = '"+email+"'";
        ResultSet* res = stmt->executeQuery(selectQuery);
        while (res->next()) {
            NodeDonHang donHang(
                to_string(res->getInt("MaDonHang")),
                res->getString("SDT"),
                to_string(res->getInt("MaCauHinh")),
                res->getString("MaXe"),
                res->getString("NgayDatHang"),
                res->getString("NgayGiaoHangDuKien"),
                static_cast<long long>(res->getDouble("TongGiaTriDonHang")),
                res->getString("TrangThaiDonHang"),
                res->getString("PhuongThucThanhToan"),
                to_string(res->getInt("storeID")),
                res->getString("UserEmail")
            );
            danhSachDonHang.push_back(donHang);
        }
        delete stmt;
        delete res;
        return danhSachDonHang;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

long long DonHang::TinhTongGiaTriGioHang(vector<NodeDonHang> check)
{
    long long GiaTriGio= 0;
    for (int i = 0; i < check.size(); i++) {
        GiaTriGio += check[i].GetTongGiaTriDonHang();
    }
    return GiaTriGio;
}



void DonHang::PrintTTDH( vector<NodeDonHang> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetMaDonHang() << "\t" <<check[i].GetSDT()<<"\t" << check[i].GetMaXe() << "\t" << check[i].GetMaCauHinh() << "\t" << check[i].GetNgayDatHang() << "\t" << check[i].GetNgayGiaoHangDuKien() << "\t" << check[i].GetTongGiaTriDonHang() << "\t" << check[i].GetPhuongThucThanhToan() << endl;
    }
}

void DonHang::PrintGioHang()
{
    string email;
    long long GiaTri = 0;
    cout << "Nhap tai khoan can xem gio hang: "; cin >> email;
    vector<NodeDonHang> check = DH->GioHang(email);
    GiaTri = DH->TinhTongGiaTriGioHang(check);
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetMaDonHang() << "\t" << check[i].GetSDT() << "\t" << check[i].GetMaXe() << "\t" << check[i].GetMaCauHinh() << "\t" << check[i].GetNgayDatHang() << "\t" << check[i].GetNgayGiaoHangDuKien() << "\t" << check[i].GetTongGiaTriDonHang() << "\t" << check[i].GetPhuongThucThanhToan() << endl;
    }
    cout << "Tong Gia Tri Gio Hang: " << GiaTri << endl;
}

void DonHang::InputEditOrderInfo()
{
    int chon;
    string MaDonHang, NgayDatHang, NgayGiaoHangDuKien, TrangThaiDonHang, PhuongThucThanhToan, SDTMoi;
    long long TongGiaTriDonHang;
    cout << "Nhap ma don hang can sua: "; cin >> MaDonHang;
    if (DL_DH->CheckOderID(MaDonHang)) {
        cout << "Chon che do sua " << endl;
        cout << "1. Sua Ngay Dat Hang" << endl;
        cout << "2. Sua Ngay Giao Hang Du Kien" << endl;
        cout << "3. Sua Tong Gia Tri Don Hang" << endl;
        cout << "4. Sua Trang Thai Don Hang" << endl;
        cout << "5. Sua Phuong Thuc Thanh Toan" << endl;
        cout << "6. Sua So Dien Thoai" << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cout << "Ngay Dat Hang moi: "; cin >> NgayDatHang;
            SuaThongTinDonHang("NgayDatHang", NgayDatHang, MaDonHang);
        }
        else if (chon == 2) {
            cout << "Ngay Giao Hang Du Kien moi: "; cin >> NgayGiaoHangDuKien;
            SuaThongTinDonHang("NgayGiaoHangDuKien", NgayGiaoHangDuKien, MaDonHang);
        }
        else if (chon == 3) {
            cout << "Tong Gia Tri Don Hang moi: "; cin >> TongGiaTriDonHang;
            SuaThongTinDonHang("TongGiaTriDonHang", to_string(TongGiaTriDonHang), MaDonHang);
        }
        else if (chon == 4) {
            cout << "Trang Thai Don Hang moi: "; cin >> TrangThaiDonHang;
            SuaThongTinDonHang("TrangThaiDonHang", TrangThaiDonHang, MaDonHang);
        }
        else if (chon == 5) {
            cin.ignore();
            cout << "Phuong Thuc Thanh Toan moi: "; getline(cin, PhuongThucThanhToan);
            SuaThongTinDonHang("PhuongThucThanhToan", PhuongThucThanhToan, MaDonHang);
        }
        else if (chon == 6) {
            cout << "So Dien Thoai moi: "; cin >> SDTMoi;
            if (DL_DH->CheckSDT(SDTMoi)) {
                cout << "So dien thoai nay da duoc dang ki voi mot tai khoan khac" << endl;
            }
            else {
                SuaThongTinDonHang("SDT", SDTMoi, MaDonHang);
            }
        }
        else {
            cout << "Khong co so nao! Vui long nhap lai!" << endl;
        }
    }
    else {
        cout << "Don Hang khong ton tai! Vui long kiem tra lai! " << endl;
    }
}


void DonHang::SuaThongTinDonHang(string Email, string MuonDoiThanh, string ChoCanSua) {
    try {
        Statement* stmt = Check_DH->createStatement();
        string updateQuery = "UPDATE DonHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" +Email+ "'";
        int rows_affected = stmt->executeUpdate(updateQuery);
        if (rows_affected > 0) {
            cout << "Cap nhat thong tin don hang thanh cong!" << endl;
        }
        else {
            cout << "Khong tim thay don hang voi thong tin tren! vui long kiem tra lai" << endl;
        }
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
}

}vector<NodeDonHang> DonHang::TimKiemThongTinDonHang(string MaDonHang)
{
    try {
        vector<NodeDonHang> OrderInfoSearch;
        Statement* stmt = Check_DH->createStatement();
        string SelectData = "SELECT * FROM DonHang WHERE MaDonHang = '" + MaDonHang + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeDonHang info(
                to_string(res->getInt("MaDonHang")),
                res->getString("sdt"),
                to_string(res->getInt("MaCauHinh")),
                to_string(res->getInt("MaXe")),
                res->getString("NgayDatHang"),
                res->getString("NgayGiaoHangDuKien"),
                static_cast<long long>(res->getDouble("TongGiaTriDonHang")),
                res->getString("TrangThaiDonHang"),
                res->getString("PhuongThucThanhToan"),
                to_string(res->getInt("storeID")),
                res->getString("UserEmail")
            );
            OrderInfoSearch.push_back(info);
        }
        delete stmt;
        delete res;
        return OrderInfoSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
        return vector<NodeDonHang>(); 
    }
}
void DonHang::InputSearchOrder() {
    string maDonHang;
    cout << "Nhap ma don hang can tim: ";
    cin >> maDonHang;
    vector<NodeDonHang> orderInfo = TimKiemThongTinDonHang(maDonHang);
    if (orderInfo.empty()) {
        cout << "Khong tim thay thong tin cho don hang voi ma " << maDonHang << endl;
    }
    else {
        cout << "Thong tin cho don hang voi ma " << maDonHang << ":\n";
        for (const auto& order : orderInfo) {
            cout << "Ma Don Hang: " << order.GetMaDonHang() << endl;
            cout << "So Dien Thoai: " << order.GetSDT() << endl;
            cout << "Ngay Dat Hang: " << order.GetNgayDatHang() << endl;
            cout << "Ngay Giao Hang Du Kien: " << order.GetNgayGiaoHangDuKien() << endl;
            cout << "Tong Gia Tri Don Hang: " << order.GetTongGiaTriDonHang() << endl;
            cout << "Trang Thai Don Hang: " << order.GetTrangThaiDonHang() << endl;
            cout << "Ma Xe: " << order.GetMaXe() << endl;
            cout << "Ma Cau Hinh: " << order.GetMaCauHinh() << endl;
            cout << "Phuong Thuc Thanh Toan: " << order.GetPhuongThucThanhToan() << endl;
        }
    }
}


