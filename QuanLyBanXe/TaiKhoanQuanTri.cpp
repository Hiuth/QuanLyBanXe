#include "TaiKhoanQuanTri.h"
#include "KetNoi.h"
KetNoi* Check_TaiKhoanQuanTri = new KetNoi();
Connection* Check_tk = Check_TaiKhoanQuanTri->CheckDatabase();

TaiKhoanQuanTri::TaiKhoanQuanTri()
{
	this->head = NULL;
	this->tail = NULL;
}

TaiKhoanQuanTri::~TaiKhoanQuanTri()
{

}

void TaiKhoanQuanTri::NhapDuLieuTaiKhoan()
{

}

void TaiKhoanQuanTri::TaoTaiKhoanQuanTri()
{
    try {
        NodeTaiKhoanQuanTri* p;
        Statement* stmt;
        stmt = Check_tk->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "TaiKhoan";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            string accountName;
            string password;
            string Email;
            accountName = p->GetManagerAccountName();
            password = p->GetManagerAccountPass();
            Email = p->ge;
            string UpdateTableAccount = "insert into TaiKhoan Values ('" + accountName + "','" + password + "','" + admin + "', '" + HRM + "','" + FM + "');";
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

void TaiKhoanQuanTri::TaoTaiKhoanKhachHang()
{

}

void TaiKhoanQuanTri::InputDelete()
{

}

void TaiKhoanQuanTri::XoaTaiKhoanQuanTri(string)
{

}

void TaiKhoanQuanTri::XoaTaiKhoanKhachHang(string)
{

}

void TaiKhoanQuanTri::InputEdit()
{

}

void TaiKhoanQuanTri::SuaTaiKhoanQuanTri(string)
{

}

void TaiKhoanQuanTri::SuaTaiKhoanKhachHang(string)
{

}

void TaiKhoanQuanTri::SuaThongTinKhachHang(string)
{

}

void TaiKhoanQuanTri::InputSearch()
{

}

void TaiKhoanQuanTri::TimKiemTaiKhoanQuanTri(string)
{

}

void TaiKhoanQuanTri::TimKiemTaiKhoanKhachHang(string)
{

}

void TaiKhoanQuanTri::TimKiemThongTinKhachHang()
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
