#include "QuanLyXe.h"

KetNoi* Check_Xe = new KetNoi();
Connection* Check_QLX = Check_Xe->CheckDatabase();
QuanLyXe* QL = new QuanLyXe();
NodeXe* Xe;
NodeCauHinhXe* CauHinh;
CheckDuLieu* DL_QLX = new CheckDuLieu();

QuanLyXe::QuanLyXe()
{
	this->head = NULL;
	this->headCH = NULL;
	this->tail = NULL;
	this->tailCH = NULL;
}

QuanLyXe::~QuanLyXe()
{

}

void QuanLyXe::ThemThongTinXe()//có thể sử dụng hàm này cho front end, chỉ cần thêm tham số vào hàm rồi sau đó ở front end cho người dùng nhập hết xong đưa dữ liệu vào hàm này.
{
    string MaXe, TenXe, GiaTien, DongCo,HopSo,DanDong,NamSanXuat,TuiKhi,HangXe,TocDoToiDa,KichThuoc,KhoangSangGam,ChieuDaiCoSo,TonKho,PhanCapXe,CongSuatToiDa;
    cout << "Nhap ma xe: "; cin >> MaXe;
    if (DL_QLX->Check_CarID(MaXe)==false) {
        cin.ignore();
        cout << "Nhap ten xe: "; getline(cin, TenXe);
        if (DL_QLX->Check_CarName(TenXe) == false) {
            cout << "Nhap gia tien chua bao gom pin cua xe: "; cin >> GiaTien;
            if (DL_QLX->check10number(GiaTien) || DL_QLX->check11number(GiaTien) || DL_QLX->check9number(GiaTien)) {
                cin.ignore();
                cout << "Nhap loai dong co cua xe: "; getline(cin, DongCo);
                cout << "Nhap loai hop so; "; getline(cin, HopSo);
                cout << "Nhap kieu dan dong: "; getline(cin, DanDong);
                cout << "Nhap nam san xuat: "; cin >> NamSanXuat;
                if (DL_QLX->Check_Year(NamSanXuat)) {
                    cout << "Nhap so luong tui khi: "; cin >> TuiKhi;
                    if (DL_QLX->Check_Number(TuiKhi)) {
                        cout << "Nhap hang xe: "; cin >> HangXe;
                        cout << "Toc Do toi da cua xe: "; cin >> TocDoToiDa;
                        if (DL_QLX->Check_Number(TocDoToiDa)) {
                            cin.ignore();
                            cout << "Nhap vao kich thuoc tong the cua xe: "; getline(cin, KichThuoc);
                            cout << "Nhap vao khoang sang gam: "; cin >> KhoangSangGam;
                            if (DL_QLX->Check_Number(KhoangSangGam)) {
                                cout << "Nhap vao chieu dai truc co so: "; cin >> ChieuDaiCoSo;
                                if (DL_QLX->Check_Number(ChieuDaiCoSo)) {
                                    cout << "Nhap vao phan cap xe: "; cin >> PhanCapXe;
                                    cout << "Nhap vao cong suat dong co: "; cin >> CongSuatToiDa;
                                    cout << "Nhap vao so luong ton kho: "; cin >> TonKho;
                                    if (DL_QLX->Check_Number(TonKho)) {
                                        Xe = new  NodeXe(MaXe, TenXe, GiaTien, DongCo, HopSo, DanDong, NamSanXuat, TuiKhi, HangXe, TocDoToiDa, KichThuoc, KhoangSangGam, ChieuDaiCoSo, TonKho, PhanCapXe, CongSuatToiDa);
                                        QL->NhapThongTinXeMoi(Xe);
                                    }
                                    else {
                                        cout << "Du lieu nhap vao phai la so!!!!" << endl;
                                    }
                                }
                                else {
                                    cout << "Du lieu nhap vao phai la so!!!!" << endl;
                                }
                            }
                            else {
                                cout << "Du lieu nhap vao phai la so!!!!" << endl;
                            }
                        }
                        else {
                            cout << "Du lieu nhap vao phai la so!!!!" << endl;
                        }
                    }
                    else {
                        cout << "Du lieu nhap vao phai la so!!!!" << endl;
                    }
                }
                else {
                    cout << "Nam khong hop le! Vui long kiem tra lai!" << endl;
                }
            }
            else {
                cout << "Gia tien khong hop le vui long nhap lai! " << endl;
            }
        }
        else {
            cout << "Ten xe da ton tai! Vui long kiem tra lai." << endl;
        }
    }
    else {
        cout << "Ma xe da ton tai! vui long kiem tra lai." << endl;
    }
}

void QuanLyXe::ThemCauHinhXe()
{
    string MaCauHinh,LoaiPin,MauSac,MaXe,GiaPin;
    cout << "Nhap vao Ma Xe muon tao cau hinh: "; cin >> MaXe;
    if (DL_QLX->Check_CarID(MaXe)) {
        cout << "Nhap ma cau hinh: "; cin >> MaCauHinh;
        if (DL_QLX->Check_CarConfigurationID(MaCauHinh)) {
            cout << "Ma Cau Hinh nay da ton tai !!!" << endl;
        }
        else {
            cout << "Nhap loai pin: "; cin >> LoaiPin;
            cin.ignore();
            cout << "Nhap loai mau sac: "; getline(cin,MauSac);
            cout << "Nhap gia pin:  "; cin >> GiaPin;
            if (DL_QLX->check9number(GiaPin)) {
                CauHinh = new NodeCauHinhXe(MaCauHinh, LoaiPin, MauSac, MaXe, GiaPin);
                QL->NhapCauHinhXe(CauHinh);
            }
            else {
                cout << "Du lieu nhap vao phai la so!!!!" << endl;
            }
        } 
    }
    else {
        cout << "Ma xe khong ton tai! Vui long kiem tra lai!!!" << endl;
    }
}

void QuanLyXe::NhapThongTinXeMoi(NodeXe* p )
{
    try {

        Statement* stmt;
        stmt = Check_QLX->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "XEVINFAST";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
			string MaXe;  // VFP, VF6,VF5, ...
			string TenXe;
			string GiaTien;
			string DongCo;
			string HopSo;
			string DanDong;
			string NamSanXuat;
			string TuiKhi;
			string HangXe; // hạng a b c d E 
			string TocDoToiDa;
			string KichThuoc;
			string KhoangSangGam;
			string ChieuDaiCoSo;
			string TonKho;
			string PhanCapXe; // suv ,sedan, hatback, mpv,minicar
			string CongSuatToiDa;
            MaXe = p->LayMaXe();
            TenXe = p->LayTenXe();
            GiaTien = p->LayGiaTien();
            DongCo = p->LayLoaiDongCo();
            HopSo = p->LayLoaiHopSo();
            DanDong = p->LayLoaiDanDong();
            NamSanXuat = p->LayNamSanXuat();
            TuiKhi = p->LaySoTuiKhi();
            HangXe = p->LayHangXe();
            TocDoToiDa = p->LayTocDoToiDa();
            KichThuoc = p->LayKichThuocXe();
            KhoangSangGam = p->LayKhoangSangGam();
            ChieuDaiCoSo = p->LayChieuDaiCoSo();
            TonKho = p->LaySoLuongTonKho();
            PhanCapXe = p->LayPhanCapXe();
            CongSuatToiDa = p->LayCongSuatToiDaCuaDongCo();
            string UpdateTableAccount = "insert into XEVINFAST Values ('"+MaXe+"','"+ TenXe +  "','" +GiaTien+ "','" + DongCo + "','" + HopSo + "','" + DanDong + "','" + NamSanXuat+ "','"
				+ TuiKhi + "','" + HangXe + "','" + TocDoToiDa + "','" + KichThuoc + "','" + KhoangSangGam + "','" + ChieuDaiCoSo + "','" + TonKho + "','" + PhanCapXe + "','" + CongSuatToiDa+ "');";
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

void QuanLyXe::NhapCauHinhXe(NodeCauHinhXe* p)
{
    try {

        Statement* stmt;
        stmt = Check_QLX->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "CauHinhXe";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string MaCauHinh;
            string LoaiPin;
            string MauSac;
            string GiaPin;
            string MaXe;
            MaCauHinh = p->LayMaCauhinhXe();
            LoaiPin = p->LayLoaiPin();
            MauSac = p->LayMauSac();
            GiaPin = p->LayGiaPin();
            MaXe = p->LayMaXe();
            string UpdateTableAccount = "insert into CauHinhXe Values ('" +MaCauHinh+ "','" +LoaiPin+ "','" + MauSac+ "','" + MaXe + "','"+ GiaPin+"');";
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

void QuanLyXe::NhapThongTinSuaXe()
{
    int chon = 0;
    string maxe, chocansua, muondoithanh;
    cout << "Nhap ma xe can sua thong tin: "; cin >> maxe;
    if (DL_QLX->Check_CarID(maxe)) {
        cout << "1. Sua ten xe." << endl;
        cout << "2. Sua gia tien." << endl;
        cout << "3. Sua ma xe." << endl;
        cout << "Moi chon: "; cin >> chon;
        if (chon == 1) {
            cin.ignore();
            cout << "Nhap ten xe moi: "; getline(cin, muondoithanh);
            if (DL_QLX->Check_CarName(muondoithanh)) {
                cout << "Ten da ton tai!" << endl;
            }
            else {
                QL->SuaThongTinXe("TenXe",muondoithanh,maxe);
            }
        }
        else if (chon == 2) {
            cout << "Nhap gia tien moi: "; cin >> muondoithanh;
            if (DL_QLX->check9number(muondoithanh) ||DL_QLX->check10number(muondoithanh) || DL_QLX->check11number(muondoithanh)) {
                QL->SuaThongTinXe("GiaTien", muondoithanh, maxe);
            }
            else {
                cout << "Vui long nhap lai gia tien!!!" << endl;
            }
        }
        else if (chon == 3) {
            cout << "Nhap ma xe moi: "; cin >> maxe;
            if (DL_QLX->Check_CarID(maxe)) {
                cout << "Ma xe da ton tai! Vui long kiem tra lai!!!" << endl;
            }
            else {
                //QL->SuaMaXeCuaDonHang
                //QL->SuaMaXeCuaLichHen
              /*  QL->SuaMaXeCuaCauHinh("MaXe", muondoithanh, maxe);
                QL->SuaThongTinXe("MaXe",muondoithanh,maxe);*/
            }
        }
        else {
            cout << "Vui long chon lai." << endl;
        }
    }
    else {
        cout << "Ma xe khong ton tai! Vui long kiem tra lai" << endl;
    }
}

void QuanLyXe::NhapThongTinSuaCauHinh()
{

}

void QuanLyXe::SuaThongTinXe(string ChoCanSua,string MuonDoiThanh,string MaXe)
{ 
    try {
        Statement* stmt;
        stmt = Check_QLX->createStatement();
        string SelectData = "UPDATE XEVINFAST SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaXe = '" + MaXe + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void QuanLyXe::SuaCauHinhXe(string ChoCanSua, string MuonDoiThanh, string MaCauHinh)
{
    try {
        Statement* stmt;
        stmt = Check_QLX->createStatement();
        string SelectData = "UPDATE CauHinhXe SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaCauHinh = '" + MaCauHinh + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}


void QuanLyXe::Xoa()
{
    string maxe;
    cout << "Nhap ma xe can xoa: "; cin >> maxe;
    if (DL_QLX->Check_CarID(maxe)) {
        QL->XoaThongTinXe(maxe);
    }
    else {
        cout << "Vui long kiem tra lai du lieu." << endl;                                                                                                       
    }

}

void QuanLyXe::XoaThongTinXe(string xoa)
{
    Statement* stmt;
    stmt = Check_QLX->createStatement();
    string SelectData = "Delete from XEVINFAST where MaXe = '" + xoa + "'";
    string SelectData2 = "Delete from CauHinhXe where MaXe = '" + xoa + "'";
    stmt->executeUpdate(SelectData2);
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void QuanLyXe::XoaCauHinhXe(string xoa)
{
    Statement* stmt;
    stmt = Check_QLX->createStatement();
    string SelectData = "Delete from CauHinhXe where MaCauHinh = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

vector<NodeXe> QuanLyXe::XemThongTinXe()
{
    vector<NodeXe> VinfastCar;
    Statement* stmt;
    stmt = Check_QLX->createStatement();
    string SelectData = "Select *from XEVINFAST";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeXe account(res->getString("MaXe"), res->getString("TenXe"), res->getString("GiaTien"), res->getString("DongCo")
            , res->getString("HopSo"), res->getString("DanDong"), res->getString("NamSanXuat"), res->getString("TuiKhi")
            , res->getString("HangXe"), res->getString("TocDoToiDa"), res->getString("KichThuoc"), res->getString("KhoangSangGam")
            , res->getString("ChieuDaiCoSo"), res->getString("TonKho"), res->getString("PhanCapXe"), res->getString("CongSuatDongCo"));
        VinfastCar.push_back(account);
    }
    delete stmt;
    delete res;
    return VinfastCar;
}

vector<NodeCauHinhXe> QuanLyXe::XemCauHinhXe()
{
    vector<NodeCauHinhXe> CauHinh;
    Statement* stmt;
    stmt = Check_QLX->createStatement();
    string SelectData = "Select *from CauHinhXe";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeCauHinhXe account(res->getString("MaCauHinh"), res->getString("LoaiPin"), res->getString("MauSac"), res->getString("GiaPin"), res->getString("MaXe"));
        CauHinh.push_back(account);
    }
    delete stmt;
    delete res;
    return CauHinh;
}

void QuanLyXe::NhapThongTinXeCanTim()
{
    int chon;
    string cantim;
    cout << "1. Tim kiem thong tin theo ma xe." << endl;
    cout << "2. Tim kiem thong tin theo ten xe. " << endl;
    cout << "3. Tim kiem thong tin theo so tui khi." << endl;
    cout << "4. Tim kiem thong tin theo hang xe." << endl;
    cout << "5. Tim kiem thong tin theo phan cap xe." << endl;
    cout << "6. Tim kiem thong tin theo cong suat dong co." << endl;
    cout << "Moi chon: "; cin >> chon;
    if (chon == 1) {
        cout << "Nhap ma xe: "; cin >> cantim;
        QL->InThongtinTimKiem(TimKiemThongTinXe("MaXe", cantim));
    }
    else if (chon == 2) {
        cin.ignore();
        cout << "Nhap ten xe: "; getline(cin, cantim);
        QL->InThongtinTimKiem(TimKiemThongTinXe("TenXe", cantim));
    }
    else if (chon == 3) {
        cout << "Nhap so tui khi can tim: "; cin >> cantim;
        QL->InThongtinTimKiem(TimKiemThongTinXe("TuiKhi", cantim));
    }
    else if (chon == 4) {
        cout << "Nhap hang xe can tim: "; cin >> cantim;
        QL->InThongtinTimKiem(TimKiemThongTinXe("HangXe", cantim));
    }
    else if (chon == 5) {
        cout << "Nhap phan cap xe can tim: "; cin >> cantim;
        QL->InThongtinTimKiem(TimKiemThongTinXe("PhanCapXe", cantim));
    }
    else if (chon == 6) {
        cout << "Nhap cong suat dong co can tim: "; cin >> cantim;
        QL->InThongtinTimKiem(TimKiemThongTinXe("CongSuatDongCo", cantim));
    }
    else {
        cout << "Vui long chon lai!" << endl;
    }
}

void QuanLyXe::NhapThongTinCauHinhCanTim()
{
    int chon;
    string cantim;
    cout << "1. Tim kiem thong tin theo ma xe." << endl;
    cout << "2. Tim kiem thong tin theo loai pin. " << endl;
    cout << "3. Tim kiem thong tin theo mau sac." << endl;
    cout << "Moi chon: "; cin >> chon;
    if (chon == 1) {
        cout << "Nhap ma xe: "; cin >> cantim;
        QL->InThongTinTimKiemCauHinh(TimKiemCauHinh("MaXe", cantim));
    }
    else if (chon == 2) {
        cin.ignore();
        cout << "Nhap loai pin: "; getline(cin, cantim);
        QL->InThongTinTimKiemCauHinh(TimKiemCauHinh("LoaiPin", cantim));
    }
    else if (chon == 3) {
        cin.ignore();
        cout << "Nhap mau sac: "; getline(cin,cantim);
        QL->InThongTinTimKiemCauHinh(TimKiemCauHinh("MauSac", cantim));
    }
    else {
        cout << "Vui long chon lai!" << endl;
    }
}

void QuanLyXe::TimKiemMaXe()
{
    string mausac, loaipin, maxe;
    cin.ignore();
    cout << "Nhap mau sac: "; getline(cin, mausac);
    cout << "Nhap loai pin: "; getline(cin, loaipin);
    cout << "Nhap ma xe: "; getline(cin, maxe);
    QL->InThongTinTimKiemCauHinh(TimMaCauHinh(maxe, mausac, loaipin));
}
    

vector<NodeXe> QuanLyXe::TimKiemThongTinXe(string LoaiMuonTim, string MuonTim)
{
    vector<NodeXe> VinfastCar;
    Statement* stmt;
    stmt = Check_QLX->createStatement();
    string SelectData = "Select *from XEVINFAST where " + LoaiMuonTim + "= '" + MuonTim + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeXe account(res->getString("MaXe"), res->getString("TenXe"), res->getString("GiaTien"), res->getString("DongCo")
            , res->getString("HopSo"), res->getString("DanDong"), res->getString("NamSanXuat"), res->getString("TuiKhi")
            , res->getString("HangXe"), res->getString("TocDoToiDa"), res->getString("KichThuoc"), res->getString("KhoangSangGam")
            , res->getString("ChieuDaiCoSo"), res->getString("TonKho"), res->getString("PhanCapXe"), res->getString("CongSuatDongCo"));
        VinfastCar.push_back(account);
    }
    delete stmt;
    delete res;
    return VinfastCar;
}

vector<NodeCauHinhXe> QuanLyXe::TimKiemCauHinh(string LoaiMuonTim,string MuonTim)
{
    try {
        vector<NodeCauHinhXe> CarOp;
        Statement* stmt;
        stmt = Check_QLX->createStatement();
        string SelectData = "Select *from CauHinhXe where "+LoaiMuonTim+" = '" + MuonTim + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
           NodeCauHinhXe Car(res->getString("MaCauHinh"), res->getString("LoaiPin"), res->getString("MauSac"),res->getString("MaXe"), res->getString("GiaPin"));
           CarOp.push_back(Car );
        }
        delete stmt;
        delete res;
        return CarOp;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeCauHinhXe> QuanLyXe::TimMaCauHinh(string MaXe, string MauSac, string LoaiPin)
{
    try {
        vector<NodeCauHinhXe> CarOp;
        Statement* stmt;
        stmt = Check_QLX->createStatement();
        string SelectData = "Select *from CauHinhXe where MaXe = '" + MaXe + "' AND MauSac = '" + MauSac + "'AND  LoaiPin = '" + LoaiPin + "' ";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeCauHinhXe Car(to_string(res->getInt("MaCauHinh")), res->getString("LoaiPin"), res->getString("MauSac"), res->getString("MaXe"), res->getString("GiaPin"));
            CarOp.push_back(Car);
        }
        delete res;
        delete stmt;
        return CarOp;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void QuanLyXe::InThongtinTimKiem(vector<NodeXe> p)
{
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].LayMaXe() << " " << p[i].LayTenXe() << " " << p[i].LayGiaTien() << " " << \
            p[i].LayLoaiDongCo() << " " << p[i].LayLoaiHopSo() << " " << p[i].LayLoaiDanDong() << " " << \
            p[i].LayNamSanXuat() << " "  << p[i].LaySoTuiKhi() << " " << p[i].LayHangXe() << " "  << \
            p[i].LayTocDoToiDa() << " " << p[i].LayCongSuatToiDaCuaDongCo() << " " << p[i].LayKichThuocXe() << " " << \
            p[i].LayKhoangSangGam() << " " << p[i].LayChieuDaiCoSo() << " " << p[i].LayPhanCapXe() << " " << \
            p[i].LaySoLuongTonKho() << endl;
    }
}

void QuanLyXe::InThongTinTimKiemCauHinh(vector<NodeCauHinhXe> p)
{
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].LayMaCauhinhXe() << "\t" << p[i].LayLoaiPin() << "\t" << p[i].LayGiaPin() << "\t" << p[i].LayMauSac() <<"\t"<< p[i].LayMaXe() << endl;
    }
}



vector<NodeXe> QuanLyXe::SapXepTheoGiaTienTangDan(vector<NodeXe> p)
{
    int min = 0;
    for (int i = 0; i < p.size()-1; i++) {
        min = i;
        for (int j = i + 1; j < p.size(); j++) {
            if (stoi(p[j].LayGiaTien()) < stoi(p[min].LayGiaTien())) {
                min = j;
            }
        }
        swap(p[i],p[ min]);
    }
    return p;
}

vector<NodeXe> QuanLyXe::SapXepTheoGiaTienGiamDan(vector<NodeXe> p)
{

    int min = 0;
    for (int i = 0; i < p.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < p.size(); j++) {
            if (stoi(p[j].LayGiaTien()) > stoi(p[min].LayGiaTien())) {
                min = j;
            }
        }
        swap(p[i], p[min]);
    }
    return p;
}

vector<NodeXe> QuanLyXe::SapXepTheoTonKhoTangDan(vector<NodeXe> p)
{
    int min = 0;
    for (int i = 0; i < p.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < p.size(); j++) {
            if (stoi(p[j].LaySoLuongTonKho()) < stoi(p[min].LaySoLuongTonKho())) {
                min = j;
            }
        }
        swap(p[i], p[min]);
    }
    return p;
}

vector<NodeXe> QuanLyXe::SapXepTheoTonKhoGiamDan(vector<NodeXe> p)
{
    int min = 0;
    for (int i = 0; i < p.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < p.size(); j++) {
            if (stoi(p[j].LaySoLuongTonKho()) > stoi(p[min].LaySoLuongTonKho())) {
                min = j;
            }
        }
        swap(p[i], p[min]);
    }
    return p;
}

