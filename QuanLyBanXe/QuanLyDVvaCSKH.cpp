#include "QuanLyDVvaCSKH.h"
#include"DaiLy.h"
KetNoi* Check_DVandCSKH = new KetNoi();
Connection* Check_DV = Check_DVandCSKH->CheckDatabase();
QuanLyXe* QL_LX = new QuanLyXe();
QuanLyDVvaCSKH* DV_CSKH = new QuanLyDVvaCSKH();
CheckDuLieu* DL_DV = new CheckDuLieu();
NodeDaiLy* Dly;
NodeHoTro* HoTro;
NodeLHBaoDuong* BD;
DaiLy* cuahang = new DaiLy();

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
    string email, sdt, mota, trangthai;
    trangthai = "Đang Xử Lý";
    cout << "Nhap email: "; getline(cin, email);
    cout << "Nhap so dien thoai: "; cin >> sdt;
    cin.ignore();
    cout << "Nhap mo ta: "; getline(cin, mota);
    HoTro = new NodeHoTro(email,sdt,mota,trangthai);
    DV_CSKH->YeuCauDichVuHoTro(HoTro);
}

void QuanLyDVvaCSKH::PhanHoi()
{
    string email,trangthai;
    cout << "Nhap tai khoan muon phan hoi: "; cin >> email;
    DV_CSKH->PhanHoiYeuCauHoTro(email);
}


/*trạng thái có 2 dạng: Đang xử lý và đã xử lý*/
vector<NodeHoTro> QuanLyDVvaCSKH::XemTrangThaiYeuCauHoTro(string trangthai)
{
    vector<NodeHoTro> HoTro;
    Statement* stmt;
    stmt = Check_DV->createStatement();
    string SelectData = "Select *from YeuCauHoTro where TrangThai = '" + trangthai + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeHoTro HT(res->getString("UserEmail"), res->getString("SoDienThoai"), res->getString("MoTa"), res->getString("TrangThai"));
        HoTro.push_back(HT);
    }
    delete stmt;
    delete res;
    return HoTro;
}


void QuanLyDVvaCSKH::PhanHoiYeuCauHoTro(string email)// sửa trạng thái yêu cầu hỗ trợ
{
    try {
        Statement* stmt;
        string capnhat = "Đã Xử Lý";
        stmt = Check_DV->createStatement();
        string SelectData = "UPDATE YeuCauHoTro SET TrangThai = '" +capnhat+ "' WHERE UserEmail = '" + email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
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
    vector<NodeDaiLy> check;
    string NgayHen,ThoiGianHen,LoaiDichVu,BienSo,MaXe,SDT,MaDaiLy,email, thanhpho,quan;
    cout << "Nhap vao ngay hen: "; cin >> NgayHen;
    cout << "Nhap thoi gian hen: "; cin >> ThoiGianHen;
    cin.ignore();
    cout << "Nhap loai dich vu: "; getline(cin, LoaiDichVu);
    cout << "Nhap bien so xe: "; getline(cin, BienSo);
    cout << "Nhap loai xe: "; cin >> MaXe;
    cout << "Nhap so dien thoai: "; cin >> SDT;
    cout << "Nhap email: "; cin >> email;
    cin.ignore();
    cout << "Nhap thanh pho: "; getline(cin, thanhpho);
    cout << "Nhap quan: "; getline(cin, quan);
    check = cuahang->TimKiemThongTinDaiLy(thanhpho,quan);
    MaDaiLy = check[0].LayMaDaiLy();
    cout << MaDaiLy << endl;
    BD = new NodeLHBaoDuong(NgayHen, ThoiGianHen, LoaiDichVu, BienSo, MaXe, SDT, MaDaiLy,email);
    DV_CSKH->DatLichHenBaoDuong(BD);
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
            string UpdateTableAccount = "insert into LICHHENBAODUONG (ngayhen, thoigianhen, loaidichvu, bienso,maxe,sdt, storeid, useremail) Values ('" + NgayHen + "','" + ThoiGianHen + "','" + LoaiDichVu + "','" +BienSo + "','" + MaXe + "','" + SDT + "','" + MaDaiLy + "','" + email + "');";
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

vector<NodeDonHang> QuanLyDVvaCSKH::XemLichSuDonDatHangTheoSDT(string SDT)
{
    try {
        vector<NodeDonHang> OrderInfoSearch;
        Statement* stmt = Check_DV->createStatement();
        string SelectData = "SELECT * FROM DonHang WHERE SDT = '" + SDT + "'";
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
    }
}

vector<NodeDonHang> QuanLyDVvaCSKH::XemLichSuDonDatHangTheoEmail(string Email)
{
    try {
        vector<NodeDonHang> OrderInfoSearch;
        Statement* stmt = Check_DV->createStatement();
        string SelectData = "SELECT * FROM DonHang WHERE Email = '" + Email + "'";
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
    }
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
