#pragma once
#include"NodeTaiKhoanQuanTri.h"
class TaiKhoanQuanTri
{
private:
	NodeTaiKhoanQuanTri* head;
	NodeTaiKhoanQuanTri* tail;
public:
	TaiKhoanQuanTri();
	virtual ~TaiKhoanQuanTri();

	void NhapDuLieuTaiKhoan(int);
	void TaoTaiKhoanQuanTri(NodeTaiKhoanQuanTri*);
	void TaoTaiKhoanKhachHang();

	void InputDelete();
	void XoaTaiKhoanQuanTri(string);
	void XoaTaiKhoanKhachHang(string);
	
	void InputEdit();
	void SuaTaiKhoanQuanTri(string, string, string);
	void SuaTaiKhoanKhachHang(string,string,string);
	void SuaThongTinKhachHang(string,string,string);

	void InputSearch();
	vector<NodeTaiKhoanQuanTri>TimKiemTaiKhoanQuanTri(string);
	vector<NodeTaiKhoanQuanTri> TimKiemTaiKhoanKhachHang(string);
	vector<NodeTaiKhoanQuanTri> TimKiemThongTinKhachHang();

	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanQuanTri();
	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanKhachHang();
	vector<NodeTaiKhoanQuanTri> XemTatCaThongTinKhachHang();
};

