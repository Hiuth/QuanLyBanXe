#include "DonHang.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <iostream>
#include <string>

using namespace std;

KetNoi* Check_DonHang = new KetNoi();
Connection* Check_DH = Check_DonHang->CheckDatabase();
CheckDuLieu* DL_DH = new CheckDuLieu();
DonHang* DH = new DonHang();
QuanLyXe* QLX = new QuanLyXe();
DonHang* orderManager = new DonHang();

DonHang::DonHang() {
    this->head = NULL;
    this->tail = NULL;
}

DonHang::~DonHang() {

}

void DonHang::NhapDuLieuThongTinDonHang() {
    int MaXe, MaCauHinh;
    string  MaDonHang, sdt, NgayDatHang, NgayGiaoHangDuKien, TrangThaiDonHang, PhuongThucThanhToan;
    long long TongGiaTriDonHang;

    cout << "Nhap Ma Don Hang: "; cin >> MaDonHang;
    if (DL_DH->CheckOderID(MaDonHang)) {
        cout << "Ma Don Hang da ton tai! Vui long kiem tra lai." << endl;
    }
    else {
        cin.ignore();
        cout << "Nhap So Dien Thoai: "; getline(cin, sdt);
        if (DL_DH->CheckSDT(sdt)) {
            cout << "So Dien Thoai da ton tai! Vui long kiem tra lai." << endl;
        }
        else {
            cout << "Ngay Dat Hang: "; cin >> NgayDatHang;
            cout << "Ngay Giao Hang Du Kien: "; cin >> NgayGiaoHangDuKien;
            cout << "Tong Gia Tri Don Hang: "; cin >> TongGiaTriDonHang;
            cout << "Trang Thai Don Hang: "; cin >> TrangThaiDonHang;
            cout << "Ma Xe: "; cin >> MaXe;
            cout << "Ma Cau Hinh: "; cin >> MaCauHinh;
            cin.ignore();
            cout << "Phuong Thuc Thanh Toan: "; getline(cin, PhuongThucThanhToan);

            NodeDonHang* newDonHang = new NodeDonHang(MaDonHang, sdt, NgayDatHang, NgayGiaoHangDuKien, TongGiaTriDonHang, TrangThaiDonHang, MaXe, MaCauHinh, PhuongThucThanhToan);
            ThemThongTinDonHang(newDonHang);
            cout << "Nhap don hang thanh cong!" << endl;
        }
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
            int MaXe = p->GetMaXe();
            int MaCauHinh = p->GetMaCauHinh();
            string PhuongThucThanhToan = p->GetPhuongThucThanhToan();
            string UpdateTableOder = "INSERT INTO DonHang (MaDonHang, sdt, NgayDatHang, NgayGiaoHangDuKien, TongGiaTriDonHang, TrangThaiDonHang, MaXe, MaCauHinh, PhuongThucThanhToan) "
                "VALUES ('" + (MaDonHang)+"', '" + sdt + "', '" + NgayDatHang + "', '" + NgayGiaoHangDuKien + "', '" + to_string(TongGiaTriDonHang) + "', '" + TrangThaiDonHang + "', '" + to_string(MaXe) + "', '" + to_string(MaCauHinh) + "', '" + PhuongThucThanhToan + "')";
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
void DonHang::XoaThongTinDonHang(string maDonHang)
{
    Statement* stmt;
    stmt = Check_DH->createStatement();
    string deleteOrder = "DELETE FROM DonHang WHERE MaDonHang = '" + maDonHang + "'";
    int rows_affected = stmt->executeUpdate(deleteOrder);
    if (rows_affected > 0) {
        cout << "Xoa don hang thanh cong!" << endl;
    }
    else {
        cout << "Khong tim thay don hang voi ma " << maDonHang << "!" << endl;
    }
    delete stmt;
}
vector<NodeDonHang> DonHang::XemTatCaThongTinDonHang() {
    vector<NodeDonHang> danhSachDonHang;
    Statement* stmt;
    stmt = Check_DH->createStatement();
    string selectQuery = "SELECT * FROM DonHang";
    ResultSet* res = stmt->executeQuery(selectQuery);
    while (res->next()) {
        NodeDonHang donHang(
            res->getString("MaDonHang"),
            res->getString("sdt"),
            res->getString("NgayDatHang"),
            res->getString("NgayGiaoHangDuKien"),
            static_cast<long long>(res->getDouble("TongGiaTriDonHang")),
            res->getString("TrangThaiDonHang"),
            res->getInt("MaXe"),
            res->getInt("MaCauHinh"),
            res->getString("PhuongThucThanhToan")
        );
        danhSachDonHang.push_back(donHang);
    }
    delete stmt;
    delete res;
    return danhSachDonHang;
}
long long TinhTongGiaTriDonHang(const vector<NodeDonHang>& danhSachDonHang) {
    long long tongGiaTri = 0;

    for (const auto& donHang : danhSachDonHang) {
        tongGiaTri += donHang.GetTongGiaTriDonHang();
    }

    return tongGiaTri;
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


void DonHang::SuaThongTinDonHang(string MaDonHang, string MuonDoiThanh, string ChoCanSua) {
    try {
        Statement* stmt = Check_DH->createStatement();
        string updateQuery = "UPDATE DonHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaDonHang = '" + MaDonHang + "'";
        int rows_affected = stmt->executeUpdate(updateQuery);
        if (rows_affected > 0) {
            cout << "Cap nhat thong tin don hang thanh cong!" << endl;
        }
        else {
            cout << "Khong tim thay don hang voi ma " << MaDonHang << "!" << endl;
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
                res->getString("MaDonHang"),
                res->getString("sdt"),
                res->getString("NgayDatHang"),
                res->getString("NgayGiaoHangDuKien"),
                static_cast<long long>(res->getDouble("TongGiaTriDonHang")),
                res->getString("TrangThaiDonHang"),
                res->getInt("MaXe"),
                res->getInt("MaCauHinh"),
                res->getString("PhuongThucThanhToan")
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


