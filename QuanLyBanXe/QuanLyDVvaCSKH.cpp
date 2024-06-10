#include "QuanLyDVvaCSKH.h"
KetNoi* Check_DVandCSKH = new KetNoi();
Connection* Check_DV = Check_DVandCSKH->CheckDatabase();
QuanLyXe* QL_DV = new QuanLyXe();
CheckDuLieu* DL_DV = new CheckDuLieu();
NodeDaiLy* DaiLy;
NodeHoTro* HoTro;
NodeLHBaoDuong* BD;

QuanLyDVvaCSKH::QuanLyDVvaCSKH()
{
    this->head = NULL;
    this->tail = NULL;
    this->headBD = NULL;
    this->tailBD = NULL;
    this->headHT = NULL;
    this->tailHT = NULL;
}

QuanLyDVvaCSKH::~QuanLyDVvaCSKH()
{

}

void QuanLyDVvaCSKH::NhapThongTinYeuCauHoTro()
{

}

void QuanLyDVvaCSKH::XemTrangThaiYeuCauHoTro()
{
}

void QuanLyDVvaCSKH::PhanHoiYeuCauHoTro()
{
}

void QuanLyDVvaCSKH::YeuCauDichVuHoTro(NodeHoTro* p)
{
    try {

        Statement* stmt;
        stmt = Check_DV->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "YeuCauHoTro";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string Email;
            string SDT;
            string MoTa;
            string TrangThai;
            Email = p->LayTaiKhoanKhachHang();
            SDT = p->LaySoDienThoai();
            MoTa = p->LayMoTa();
            TrangThai= p->LayTrangThai();
            string UpdateTableAccount = "insert into YeuCauHoTro(UserEmail,SoDienThoai,MoTa,TrangThai) Values ('" + Email + "','" +SDT + "','" + MoTa + "','" + TrangThai + "');";
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

void QuanLyDVvaCSKH::NhapThongTinLichHen()
{
}

void QuanLyDVvaCSKH::DatLichHenBaoDuong(NodeLHBaoDuong* p)
{
    try {

        Statement* stmt;
        stmt = Check_DV->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "LICHHENBAODUONG";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string NgayHen;
            string ThoiGianHen;
            string LoaiDichVu;
            string BienSo;
            string MaXe;
            string SDT;
            string MaDaiLy;
            string email;
            NgayHen = p->LayNgayHen();
            ThoiGianHen = p->LayThoiGianHen();
            LoaiDichVu = p->LayLoaiDichVu();
            BienSo = p->LayBienSo();
            MaXe = p->LayMaXe();
            SDT = p->LaySoDienThoai();
            MaDaiLy = p->LayMaCuaHang();
            email = p->LayTaiKhoanKhachHang();
            string UpdateTableAccount = "insert into CauHinhXe Values ('" + NgayHen + "','" + ThoiGianHen + "','" + LoaiDichVu + "','" +BienSo + "','" + MaXe + "','" + SDT + "','" + MaDaiLy + "','" + email + "');";
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

vector<NodeLHBaoDuong> QuanLyDVvaCSKH::XemLichSuBaoDuong(string email)
{
    vector<NodeLHBaoDuong> LichSu;
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Select *from LICHHENBAODUONG where UserEmail = '"+email+"'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeLHBaoDuong BD(res->getString("NgayHen"), res->getString("ThoiGianHen"), res->getString("LoaiDichVu"), res->getString("BienSo"), res->getString("MaXe"), res->getString("SDT"), res->getString("StoreID"), res->getString("UserEmail"));
        LichSu.push_back(BD);
    }
    delete stmt;
    delete res;
    return LichSu;
}

vector<NodeHoTro> QuanLyDVvaCSKH::XemLichSuYeuCauHoTro(string email)
{
    vector<NodeHoTro> LichSu;
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Select *from YeuCauHoTro where UserEmail = '" + email + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeHoTro HT(res->getString("UserEmail"), res->getString("SoDienThoai"), res->getString("MoTa"), res->getString("TrangThai"));
        LichSu.push_back(HT);
    }
    delete stmt;
    delete res;
    return LichSu;
}



void QuanLyDVvaCSKH::SuaLichHenTheoSDT(string ChoCanSua, string MuonDoiThanh, string SDT)
{
    try {
        Statement* stmt;
        stmt = Check_DV->createStatement();
        string SelectData = "UPDATE YeuCauHoTro SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE SoDienThoai = '" + SDT + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void QuanLyDVvaCSKH::SuaLichHenTheoEmail(string ChoCanSua, string MuonDoiThanh, string email)
{
    try {
        Statement* stmt;
        stmt = Check_DV->createStatement();
        string SelectData = "UPDATE YeuCauHoTro SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void QuanLyDVvaCSKH::SuaThongTinYeuCauHoTro(string ChoCanSua, string MuonDoiThanh, string email)
{
    try {
        Statement* stmt;
        stmt = Check_DV->createStatement();
        string SelectData = "UPDATE YeuCauHoTro SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void QuanLyDVvaCSKH::XoaYeuCauHoTro(string xoa)
{
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Delete from YeuCauHoTro where UserEmail = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void QuanLyDVvaCSKH::XoaLichHenTheoEmail(string xoa)
{
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Delete from LICHHENBAODUONG where UserEmail = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void QuanLyDVvaCSKH::XoaLichHenTheoSDT(string xoa)
{
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Delete from LICHHENBAODUONG where SDT = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}
