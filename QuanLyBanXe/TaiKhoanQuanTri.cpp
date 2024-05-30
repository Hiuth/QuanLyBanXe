#include "TaiKhoanQuanTri.h"
#include "KetNoi.h"
#include<fstream>
#include<sstream>
KetNoi* Check_TaiKhoanQuanTri = new KetNoi();
Connection* Check_tk = Check_TaiKhoanQuanTri->CheckDatabase();
NodeTaiKhoanQuanTri* TKQT;
NodeTaiKhoanKhachHang* TKKH;
NodeKhachHang* KH;
TaiKhoanQuanTri* QT = new TaiKhoanQuanTri();
CheckDuLieu* DL = new CheckDuLieu();

TaiKhoanQuanTri::TaiKhoanQuanTri()
{
	this->head = NULL;
	this->tail = NULL;
}

TaiKhoanQuanTri::~TaiKhoanQuanTri()
{

}

void TaiKhoanQuanTri::DangNhap()
{
    string email, pass;
    cout << "Nhap Email Tai Khoan: "; cin >> email;
    cout << "Nhap Mat Khau: "; cin >> pass;
    if (DL->CheckManagerAccount(email, pass)) {
        cout << "Chao mung tro lai!" << endl;
    }
    else {
        cout << "Email hoac mat khau sai! Vui long kiem tra lai." << endl;
    }
}

void TaiKhoanQuanTri::NhapDuLieuTaiKhoanQuanTri()
{
    int n;
    cout << "So luong tai khoan muon nhap vao: "; cin >> n;
    for (int i = 0; i < n; i++) {
        string Email, TenTaiKhoan, MatKhau;
        cout << "Nhap Email: "; cin >> Email;
        if (DL->CheckTKKH(Email)) {
            cout << "Email da ton tai!. Vui long nhap lai Email khac" << endl;
        }
        else {
            cout << "Nhap Ten Tai Khoan: "; cin >> TenTaiKhoan;
            cout << "Nhap Mat Khau: "; cin >> MatKhau;
            TKQT = new NodeTaiKhoanQuanTri(Email, TenTaiKhoan, MatKhau);
            QT->TaoTaiKhoanQuanTri(TKQT);
            TKKH = new NodeTaiKhoanKhachHang(Email, TenTaiKhoan, MatKhau);
            QT->TaoTaiKhoanKhachHang(TKKH);
            cout << endl;
        }
    }
}

void TaiKhoanQuanTri::NhapDuLieuTaiKhoanKhachHang()
{
    int n;
    cout << "So luong tai khoan muon nhap vao: "; cin >> n;
    for (int i = 0; i < n; i++) {
        string Email, TenTaiKhoan, MatKhau;
        cout << "Nhap Email: "; cin >> Email;
        if (DL->CheckTKQT(Email)) {
            cout << "Email da ton tai!. Vui long nhap lai Email khac" << endl;
        }
        else {
            cout << "Nhap Ten Tai Khoan: "; cin >> TenTaiKhoan;
            cout << "Nhap Mat Khau: "; cin >> MatKhau;
            TKKH = new NodeTaiKhoanKhachHang(Email, TenTaiKhoan, MatKhau);
            QT->TaoTaiKhoanKhachHang(TKKH);
            cout << endl;
        }
    }
}

void TaiKhoanQuanTri::NhapDuLieuThongTinKhachHang()
{
    string TenKhachHang, SinhNhat, CCCD, DiaChi, GioiTinh, SoDienThoai, Email;
    cout << "Nhap Email tai khoan can them thong tin khach hang"; cin >> Email;
    if (DL->CheckTKKH(Email)) {
        cout << "Ho va ten: "; getline(cin, TenKhachHang);
        cout << "Ngay thang nam sinh: "; cin >> SinhNhat;
        cout << "Gioi Tinh: "; cin >> GioiTinh;
        cout << "So can cuoc cong dan: "; cin >> CCCD;
        cout << "So dien thoai: "; cin >> SoDienThoai;
        cout << "Dia chi: "; getline(cin, DiaChi);
        KH = new NodeKhachHang(TenKhachHang,SinhNhat,CCCD,SoDienThoai,DiaChi,GioiTinh,Email);
        QT->ThemThongTinKhachHang(KH);
    }
    else {
        cout << "Tai khoan khong ton tai! Vui long kiem tra lai." << endl;
    }
}

void TaiKhoanQuanTri::TaoTaiKhoanQuanTri(NodeTaiKhoanQuanTri* p)
{
    try {
       
        Statement* stmt;
        stmt = Check_tk->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "ManagerAccount";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string accountName;
            string password;
            string Email;
            accountName = p->GetManagerAccountName();
            password = p->GetManagerAccountPass();
            Email = p->GetManagerAccountEmail();
            string UpdateTableAccount = "insert into ManagerAccount (ManagerEmail, ManagerAccountName, ManagerPass) Values ('" + Email + "','" + accountName + "','" + password + "');";
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

void TaiKhoanQuanTri::TaoTaiKhoanKhachHang(NodeTaiKhoanKhachHang* p)
{
    try {

        Statement* stmt;
        stmt = Check_tk->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "UserAccount";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string accountName;
            string password;
            string Email;
            accountName = p->GetName();
            password = p->GetPass();
            Email = p->GetEmail();
            string UpdateTableAccount = "insert into UserAccount (UserEmail, UserAccountName, UserPass) Values ('" + Email + "','" + accountName + "','" + password + "');";
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

void TaiKhoanQuanTri::ThemThongTinKhachHang(NodeKhachHang* p)
{
    try {

        Statement* stmt;
        stmt = Check_tk->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "KhachHang";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string TenKhachHang;
            string SinhNhat;
            string CCCD;
            string DiaChi;
            string GioiTinh;
            string SoDienThoai;
            string Email;
            TenKhachHang = p->GetName();
            SinhNhat = p->GetBirthday();
            CCCD = p->GetIDCard();
            DiaChi = p->GetAddress();
            GioiTinh = p->GetSex();
            SoDienThoai = p->GetPhoneNumber();
            Email = p->GetEmail();
            string UpdateTableAccount = "insert into KhachHang  Values ('" + TenKhachHang + "','" +CCCD+ "','" + SinhNhat+ "','"+SoDienThoai+"','"+DiaChi+"','"+Email+"','"+GioiTinh+"');";
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

void TaiKhoanQuanTri::InputDelete() //da check
{
    string xoa;
    cout << "Ten tai khoan can xoa: "; cin >> xoa;
    QT->XoaTaiKhoanQuanTri(xoa);
}

void TaiKhoanQuanTri::XoaTaiKhoanQuanTri(string xoa)
{
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "Delete from ManagerAccount where ManagerEmail = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
  //  string call = "CALL UpdateManagerIDs();";
 //   stmt->execute(call);
    delete stmt;
}

void TaiKhoanQuanTri::XoaTaiKhoanKhachHang(string xoa)
{
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "Delete from UserAccount where UserEmail = '" + xoa + "'";
    string SelectData2 = "Delete from KhachHang where UserEmail = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    stmt->executeUpdate(SelectData2);
   // string call = "CALL UpdateManagerIDs();";
    //   stmt->execute(call);
    delete stmt;
}

void TaiKhoanQuanTri::InputEditManager()
{
    int chon;
    string ChoCanSua, MuonDoiThanh, Email;
    cout << "Nhap Email tai khoan muon sua: "; cin >> Email;
    if (DL->CheckTKQT(Email)) {
        cout << "Chon che do sua " << endl;
        cout << "1.Sua Email" << endl;
        cout << "2.Sua Ten Tai Khoan" << endl;
        cout << "3.Sua mat khau" << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cout << "Nhap Email moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanQuanTri("ManagerEmail",MuonDoiThanh,Email);
        }
        else if (chon == 2) {
            cout << "Nhap Ten Tai khoan Moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanQuanTri("ManagerAccountName", MuonDoiThanh, Email);
        }
        else if (chon == 3) {
            cout << "Nhap mat khau moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanQuanTri("ManagerPass", MuonDoiThanh, Email);
        }
        else {
            cout << "Vui Long chon lai!" << endl;
        }
    }
    else {
        cout << "Tai khoan khong ton tai! Vui long nhap lai ";
    }
}

void TaiKhoanQuanTri::InputEditUser()
{
    int chon;
    string ChoCanSua, MuonDoiThanh, Email;
    cout << "Nhap Email tai khoan muon sua: "; cin >> Email;
    if (DL->CheckTKKH(Email)) {
        cout << "Chon che do sua " << endl;
        cout << "1.Sua Email" << endl;
        cout << "2.Sua Ten Tai Khoan" << endl;
        cout << "3.Sua mat khau" << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cout << "Nhap Email moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanKhachHang("UserEmail", MuonDoiThanh, Email);
        }
        else if (chon == 2) {
            cout << "Nhap Ten Tai khoan Moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanKhachHang("UserAccountName", MuonDoiThanh, Email);
        }
        else if (chon == 3) {
            cout << "Nhap mat khau moi: "; cin >> MuonDoiThanh;
            QT->SuaTaiKhoanKhachHang("UserPass", MuonDoiThanh, Email);
        }
        else {
            cout << "Vui Long chon lai!" << endl;
        }
    }
    else {
        cout << "Tai khoan khong ton tai! Vui long nhap lai ";
    }
}

void TaiKhoanQuanTri::InputEditUserinfo()
{
    int chon;
    string TenKhachHang, SinhNhat, CCCD, DiaChi, GioiTinh, SoDienThoai, Email,SoDienThoaiMoi;
    cout << "Nhap SDT tai khoan muon sua thong tin ca nhan : "; cin >> SoDienThoai;
    if (DL->CheckSDT(SoDienThoai)) {
        cout << "Chon che do sua " << endl;
        cout << "1.Sua Ho va ten" << endl;
        cout << "2.Sua ngay thang nam sinh" << endl;
        cout << "3.Sua so can cuoc cong dan" << endl;
        cout << "4. Sua dia chi: " << endl;
        cout << "5. Sua gioi tinh: " << endl;
        cout << "6. Sua so dien thoai: " << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cout << "Ho va Ten moi: "; getline(cin, TenKhachHang);
            QT->SuaThongTinKhachHang("TenKH",TenKhachHang,SoDienThoai);
        }
        else if (chon == 2) {
            cout << "Ngay thang nam sinh moi: "; cin >> SinhNhat;
            QT->SuaThongTinKhachHang("NgaySinh", SinhNhat, SoDienThoai);
        }
        else if (chon == 3) {
            cout << "So can cuoc cong dan moi: "; cin >> CCCD;
            QT->SuaThongTinKhachHang("SoCCCD",CCCD,SoDienThoai);
        }
        else if (chon == 4) {
            cout << "Dia chi moi: "; getline(cin, DiaChi);
            QT->SuaThongTinKhachHang("DiaChi", DiaChi, SoDienThoai);

        }
        else if (chon == 5) {
            cout << "Sua gioi tinh: "; cin >> GioiTinh;
            QT->SuaThongTinKhachHang("GioiTinh", GioiTinh, SoDienThoai);
        }
        else if (chon == 6) {
            cout << "So dien thoai moi: "; cin >> SoDienThoaiMoi;
            if (DL->CheckSDT(SoDienThoaiMoi)){
               QT->SuaThongTinKhachHang("SDT", SoDienThoaiMoi, SoDienThoai);
               //hàm sửa trong Đơn hàng ** nếu dữ liệu trong bảng rỗng thì không cần cập nhật 
               //hàm sửa trong lịch hẹn ** tương tự như trên 
            }
            else {
                cout << "So dien thoai nay da duoc dang ki voi mot tai khoan khac" << endl;
            }
        }
        else {
            cout << "Khong co so nao! Vui long nhap lai!" << endl;
        }
    }
    else {
        cout << "Tai Khoan khong ton tai! Vui long kiem tra lai! " << endl;
    }
}

void TaiKhoanQuanTri::SuaTaiKhoanQuanTri(string ChoCanSua,string MuonDoiThanh, string Email)
{
    try {
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "UPDATE ManagerAccount SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE ManagerEmail = '" + Email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void TaiKhoanQuanTri::SuaTaiKhoanKhachHang(string ChoCanSua, string MuonDoiThanh, string Email)
{
    try {
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "UPDATE UserAccount SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }

}

void TaiKhoanQuanTri::SuaThongTinKhachHang(string ChoCanSua, string MuonDoiThanh, string SDT)
{
    try {
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "UPDATE KhachHang SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE SDT = '" + SDT + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void TaiKhoanQuanTri::InputSearchManager()
{
    string Email;
    cout << "Nhap Email tai khoan quan tri can tim: "; cin >> Email;
    if (DL->CheckTKQT(Email)) {
        QT->PrintQT(TimKiemTaiKhoanQuanTri(Email));
    }
    else {
        cout << "Email khong dung hoac tai khoan khong ton tai! Vui long nhap lai." << endl;
    }

}

void TaiKhoanQuanTri::InputSearchUser()
{
    string Email;
    cout << "Nhap Email tai khoan quan tri can tim: "; cin >> Email;
    if (DL->CheckTKKH(Email)) {
        QT->PrintTKKH(TimKiemTaiKhoanKhachHang(Email));
    }
    else {
        cout << "Email khong dung hoac tai khoan khong ton tai! Vui long nhap lai." << endl;
    }
    cout << endl;
}

void TaiKhoanQuanTri::InputSearchUserInfo()
{
    string SDT;
    cout << "Nhap Email tai khoan quan tri can tim: "; cin >> SDT;
    if (DL->CheckSDT(SDT)) {
        QT->PrintTTKH(TimKiemThongTinKhachHang(SDT));
    }
    else {
        cout << "Email khong dung hoac tai khoan khong ton tai! Vui long nhap lai." << endl;
    }
    cout << endl;
}

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::TimKiemTaiKhoanQuanTri(string Email)
{
    try {
        vector<NodeTaiKhoanQuanTri> ManagerAccountSearch;
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "Select *from ManagerAccount where ManagerEmail = '" + Email + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeTaiKhoanQuanTri account(res->getString("ManagerAccountID"), res->getString("ManagerEmail"), res->getString("ManagerAccountName"), res->getString("ManagerPass"));
            ManagerAccountSearch.push_back(account);
        }
        delete stmt;
        delete res;
        return ManagerAccountSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeTaiKhoanKhachHang> TaiKhoanQuanTri::TimKiemTaiKhoanKhachHang(string Email)
{
    try {
        vector<NodeTaiKhoanKhachHang> UserAccountSearch;
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "Select *from UserAccount where UserEmail = '" + Email + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeTaiKhoanKhachHang account(res->getString("UserAccountID"), res->getString("UserEmail"), res->getString("UserAccountName"), res->getString("UserPass"));
            UserAccountSearch.push_back(account);
        }
        delete stmt;
        delete res;
        return UserAccountSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeKhachHang> TaiKhoanQuanTri::TimKiemThongTinKhachHang(string SDT)
{
    try {
        vector<NodeKhachHang> UserInfoSearch;
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "Select *from KhachHang where UserEmail = '" +SDT + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeKhachHang info(res->getString("TenKH"), res->getString("SoCCCD"), res->getString("NgaySinh"), res->getString("SDT"), res->getString("DiaChi"), res->getString("UserEmail"), res->getString("GioiTinh"));
            UserInfoSearch.push_back(info);
        }
        delete stmt;
        delete res;
        return UserInfoSearch;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::XemTatCaTaiKhoanQuanTri()
{
    vector<NodeTaiKhoanQuanTri> ManagerAccountSearch;
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "Select *from ManagerAccount";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeTaiKhoanQuanTri account(res->getString("ManagerAccountID"), res->getString("ManagerEmail"), res->getString("ManagerAccountName"), res->getString("ManagerPass"));
        ManagerAccountSearch.push_back(account);
    }
    delete stmt;
    delete res;
    return ManagerAccountSearch;
}

vector<NodeTaiKhoanKhachHang> TaiKhoanQuanTri::XemTatCaTaiKhoanKhachHang()
{
    vector<NodeTaiKhoanKhachHang> UserAccountSearch;
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "Select *from UserAccount";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeTaiKhoanKhachHang account(res->getString("UserAccountID"), res->getString("UserEmail"), res->getString("UserAccountName"), res->getString("UserPass"));
        UserAccountSearch.push_back(account);
    }
    delete stmt;
    delete res;
    return UserAccountSearch;
}

vector<NodeKhachHang> TaiKhoanQuanTri::XemTatCaThongTinKhachHang()
{
    vector<NodeKhachHang> UserInfo;
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "Select *from KhachHang";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeKhachHang account(res->getString("TenKH"), res->getString("NgaySinh"), res->getString("GioiTinh"), res->getString("SDT"), res->getString("SoCCCD"),res->getString("DiaChi"),res->getString("Email"));
        UserInfo.push_back(account);
    }
    delete stmt;
    delete res;
    return UserInfo;
}

void TaiKhoanQuanTri::PrintQT(vector<NodeTaiKhoanQuanTri> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetManagerAccountID() << "\t" << check[i].GetManagerAccountEmail() << "\t" << "\t" << check[i].GetManagerAccountName() << "\t" <<check[i].GetManagerAccountPass()<< endl;

    }
}

void TaiKhoanQuanTri::PrintTKKH(vector<NodeTaiKhoanKhachHang>check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetID() << "\t" << check[i].GetEmail() << "\t" << check[i].GetName() << "\t" << check[i].GetPass() << endl;
    }
}

void TaiKhoanQuanTri::PrintTTKH(vector<NodeKhachHang>check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetName() << "\t" << check[i].GetSex() << check[i].GetBirthday() << "\t" << check[i].GetPhoneNumber() << "\t" << check[i].GetIDCard() << "\t" << check[i].GetEmail() << "\t" << check[i].GetAddress()<<endl;
    }
}


