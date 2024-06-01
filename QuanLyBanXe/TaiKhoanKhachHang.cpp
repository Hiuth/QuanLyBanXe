#include "TaiKhoanKhachHang.h"
#include "KetNoi.h"
#include<fstream>
#include<sstream>
KetNoi* Check_TaiKhoanKhachHang = new KetNoi();
Connection* Check_tk = Check_TaiKhoanKhachHang->CheckDatabase();
NodeTaiKhoanKhachHang* TKKH;
TaiKhoanKhachHang* KH = new TaiKhoanKhachHang();

TaiKhoanKhachHang::TaiKhoanKhachHang() {
    this->head = nullptr;
    this->tail = nullptr;
}

TaiKhoanKhachHang::~TaiKhoanKhachHang() {
}

void TaiKhoanKhachHang::DangNhap() {
    string email, pass;
    cout << "Nhap Email Tai Khoan: "; cin >> email;
    cout << "Nhap Mat Khau: "; cin >> pass;
    if (KH->CheckUserAccount(email, pass)) {
        cout << "Chao mung tro lai!" << endl;
    }
    else {
        cout << "Email hoac mat khau sai! Vui long kiem tra lai." << endl;
    }
}
void TaiKhoanKhachHang::NhapDuLieuTaiKhoanKhachHang()
{
    int n;
    cout << "So luong tai khoan muon nhap vao: "; cin >> n;
    for (int i = 0; i < n; i++) {
        string Email, TenTaiKhoan, MatKhau;
        cout << "Nhap Email: "; cin >> Email;
        if (KH->CheckTKKH(Email)) {
            cout << "Email da ton tai!. Vui long nhap lai Email khac" << endl;
        }
        else {
            cin.ignore();
            cout << "Nhap Ten Tai Khoan: ";getline(cin, TenTaiKhoan);
            cout << "Nhap Mat Khau: "; cin >> MatKhau;
            TKKH = new NodeTaiKhoanKhachHang(Email, TenTaiKhoan, MatKhau);
            KH->TaoTaiKhoanKhachHang(TKKH);
            cout << endl;
        }
    }
}
void TaiKhoanKhachHang::TaoTaiKhoanKhachHang(NodeTaiKhoanKhachHang* p)
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

void TaiKhoanKhachHang::XoaTaiKhoanKhachHang(string xoa)
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
void TaiKhoanKhachHang::InputEditUser()
{
    int chon;
    string ChoCanSua, MuonDoiThanh, Email;
    cout << "Nhap Email tai khoan muon sua: "; cin >> Email;
    if (KH->CheckTKKH(Email)) {
        cout << "Chon che do sua " << endl;
        cout << "1.Sua Email" << endl;
        cout << "2.Sua Ten Tai Khoan" << endl;
        cout << "3.Sua mat khau" << endl;
        cout << " Moi chon: "; cin >> chon;
        if (chon == 1) {
            cout << "Nhap Email moi: "; cin >> MuonDoiThanh;
            KH->SuaTaiKhoanKhachHang("UserEmail", MuonDoiThanh, Email);
        }
        else if (chon == 2) {
            cout << "Nhap Ten Tai khoan Moi: "; cin >> MuonDoiThanh;
            KH->SuaTaiKhoanKhachHang("UserAccountName", MuonDoiThanh, Email);
        }
        else if (chon == 3) {
            cout << "Nhap mat khau moi: "; cin >> MuonDoiThanh;
            KH->SuaTaiKhoanKhachHang("UserPass", MuonDoiThanh, Email);
        }
        else {
            cout << "Vui Long chon lai!" << endl;
        }
    }
    else {
        cout << "Tai khoan khong ton tai! Vui long nhap lai ";
    }
}
void TaiKhoanKhachHang::SuaTaiKhoanKhachHang(string ChoCanSua, string MuonDoiThanh, string Email)
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

