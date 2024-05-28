#include "TaiKhoanQuanTri.h"
#include "KetNoi.h"
KetNoi* Check_TaiKhoanQuanTri = new KetNoi();
Connection* Check_tk = Check_TaiKhoanQuanTri->CheckDatabase();
NodeTaiKhoanQuanTri* TKQT;
TaiKhoanQuanTri* QT = new TaiKhoanQuanTri();

TaiKhoanQuanTri::TaiKhoanQuanTri()
{
	this->head = NULL;
	this->tail = NULL;
}

TaiKhoanQuanTri::~TaiKhoanQuanTri()
{

}

void TaiKhoanQuanTri::NhapDuLieuTaiKhoan(int n)
{
    for (int i = 0; i < n; i++) {
        string Email, TenTaiKhoan, MatKhau;
        cout << "Nhap Email: "; cin >> Email;
        cout << "Nhap Ten Tai Khoan: "; cin >> TenTaiKhoan;
        cout << "Nhap Mat Khau: "; cin >> MatKhau;
        TKQT = new NodeTaiKhoanQuanTri(Email, TenTaiKhoan, MatKhau);
        QT->TaoTaiKhoanQuanTri(TKQT);
        cout << endl;
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

void TaiKhoanQuanTri::TaoTaiKhoanKhachHang()
{

}

void TaiKhoanQuanTri::InputDelete()
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
    string call = "CALL UpdateManagerIDs();";
 //   stmt->execute(call);
    delete stmt;
}

void TaiKhoanQuanTri::XoaTaiKhoanKhachHang(string)
{

}

void TaiKhoanQuanTri::InputEdit()
{

}

void TaiKhoanQuanTri::SuaTaiKhoanQuanTri(string ChoCanSua,string MuonDoiThanh, string Email)
{
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData= "UPDATE ManagerAccount SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE ManagerEmail = '" + Email + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void TaiKhoanQuanTri::SuaTaiKhoanKhachHang(string ChoCanSua, string MuonDoiThanh, string Email)
{
    Statement* stmt;
    stmt = Check_tk->createStatement();
    string SelectData = "UPDATE UserAccount SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE UserEmail = '" + Email + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void TaiKhoanQuanTri::SuaThongTinKhachHang(string, string, string)
{

}

void TaiKhoanQuanTri::InputSearch()
{
    string Email;
    cout << "Nhap Email tai khoan quan tri can tim: "; cin >> Email;
    cout << Email;
    QT->PrintQT(TimKiemTaiKhoanQuanTri(Email));
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

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::TimKiemTaiKhoanKhachHang(string Email)
{
    try {
        vector<NodeTaiKhoanQuanTri> UserAccountSearch;
        Statement* stmt;
        stmt = Check_tk->createStatement();
        string SelectData = "Select *from UserAccount where UserEmail = '" + Email + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeTaiKhoanQuanTri account(res->getString("UserAccountID"), res->getString("UserEmail"), res->getString("UserAccountName"), res->getString("UserPass"));
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

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::TimKiemThongTinKhachHang()
{

}

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::XemTatCaTaiKhoanQuanTri()
{
	return vector<NodeTaiKhoanQuanTri>();
}

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::XemTatCaTaiKhoanKhachHang()
{
	return vector<NodeTaiKhoanQuanTri>();
}

vector<NodeTaiKhoanQuanTri> TaiKhoanQuanTri::XemTatCaThongTinKhachHang()
{
	return vector<NodeTaiKhoanQuanTri>();
}

void TaiKhoanQuanTri::PrintQT(vector<NodeTaiKhoanQuanTri> check)
{
    for (int i = 0; i < check.size(); i++) {
        cout << check[i].GetManagerAccountID() << "\t" << check[i].GetManagerAccountEmail() << "\t" << "\t" << check[i].GetManagerAccountName() << "\t" <<check[i].GetManagerAccountPass()<< endl;

    }
}


