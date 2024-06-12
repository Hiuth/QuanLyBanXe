#include "GioHang.h"
#include "KetNoi.h"
#include "CheckDuLieu.h"
#include <iostream>
#include <vector>

using namespace std;

KetNoi* checkDatabaseConnection = new KetNoi();
Connection* checkDatabase = checkDatabaseConnection->CheckDatabase();
CheckDuLieu* checkData = new CheckDuLieu();

GioHang::GioHang() {
    this->head = nullptr;
    this->tail = nullptr;
    this->orderManager = new DonHang();  
}

GioHang::~GioHang() {
    
}

void GioHang::ThemVaoGioHang(NodeGioHang* p) {
    try {
        Statement* stmt = checkDatabase->createStatement();
        string insertQuery = "INSERT INTO GioHang (MaGH, MaDonHang, SoLuong, TongGia, UserEmail) VALUES ('"
            + p->GetMaGH() + "', '" + p->GetMaDonHang() + "', "
            + to_string(p->GetSoLuong()) + ", " + to_string(p->GetTongGia()) + ", '" + p->GetUserEmail() + "')";
        stmt->execute(insertQuery);
        delete stmt;

        if (tail == nullptr) {
            head = tail = p;
        }
        else {
            tail->SetPointer(p);
            tail = p;
        }
        cout << "Them vao gio hang thanh cong!" << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

long long GioHang::TinhTongGiaTriGioHang(const vector<NodeGioHang>& danhSachGioHang) {
    long long tongGiaTri = 0;
    for (const auto& gioHang : danhSachGioHang) {
        vector<NodeDonHang> orderInfo = orderManager->TimKiemThongTinDonHang(gioHang.GetMaDonHang());
        if (!orderInfo.empty()) {
            long long giaTriDonHang = orderInfo[0].GetTongGiaTriDonHang();
            tongGiaTri += gioHang.GetSoLuong() * giaTriDonHang;
        }
    }
    return tongGiaTri;
}

vector<NodeGioHang> GioHang::XemTatCaGioHang() {
    vector<NodeGioHang> danhSachGioHang;
    try {
        Statement* stmt = checkDatabase->createStatement();
        string selectQuery = "SELECT * FROM GioHang";
        ResultSet* res = stmt->executeQuery(selectQuery);

        while (res->next()) {
            NodeGioHang gioHang(
                res->getString("MaGH"),
                res->getString("MaDonHang"),
                res->getInt("SoLuong"),
                res->getInt64("TongGia"),
                res->getString("UserEmail")
            );
            danhSachGioHang.push_back(gioHang);
        }

        delete stmt;
        delete res;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return danhSachGioHang;
}

void GioHang::XoaGioHang(string maGH) {
    try {
        Statement* stmt = checkDatabase->createStatement();
        string deleteQuery = "DELETE FROM GioHang WHERE MaGH = '" + maGH + "'";
        int rows_affected = stmt->executeUpdate(deleteQuery);
        if (rows_affected > 0) {
            cout << "Xoa gio hang thanh cong!" << endl;
        }
        else {
            cout << "Khong tim thay gio hang voi ma " << maGH << "!" << endl;
        }
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

vector<NodeGioHang> GioHang::TimKiemGioHang(string maGH) {
    vector<NodeGioHang> danhSachGioHang;
    try {
        Statement* stmt = checkDatabase->createStatement();
        string selectQuery = "SELECT * FROM GioHang WHERE MaGH = '" + maGH + "'";
        ResultSet* res = stmt->executeQuery(selectQuery);

        while (res->next()) {
            NodeGioHang gioHang(
                res->getString("MaGH"),
                res->getString("MaDonHang"),
                res->getInt("SoLuong"),
                res->getInt64("TongGia"),
                res->getString("UserEmail")
            );
            danhSachGioHang.push_back(gioHang);
        }

        delete stmt;
        delete res;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return danhSachGioHang;
}

void GioHang::SuaGioHang(string maGH, int soLuong, long long tongGia, string userEmail) {
    try {
        Statement* stmt = checkDatabase->createStatement();
        string updateQuery = "UPDATE GioHang SET SoLuong = " + to_string(soLuong)
            + ", TongGia = " + to_string(tongGia)
            + ", UserEmail = '" + userEmail
            + "' WHERE MaGH = '" + maGH + "'";
        int rows_affected = stmt->executeUpdate(updateQuery);
        if (rows_affected > 0) {
            cout << "Sua gio hang thanh cong!" << endl;
        }
        else {
            cout << "Khong tim thay gio hang voi ma " << maGH << "!" << endl;
        }
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << endl;
    }
}
