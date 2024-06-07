#include "DonHang.h"
#include "NodeDonHang.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <iostream>
#include <string>

using namespace std;

KetNoi* Check_DonHang = new KetNoi();
Connection* Check_DH = Check_DonHang->CheckDatabase();
CheckDuLieu* DL_DH = new CheckDuLieu();
DonHang* DH = new DonHang();
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

