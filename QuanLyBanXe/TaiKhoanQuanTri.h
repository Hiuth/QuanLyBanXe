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

	void NhapDuLieuTaiKhoan();
	void TaoTaiKhoanQuanTri();
	void TaoTaiKhoanKhachHang();

	void InputDelete();
	void XoaTaiKhoanQuanTri(string);
	void XoaTaiKhoanKhachHang(string);
	
	void InputEdit();
	void SuaTaiKhoanQuanTri(string);
	void SuaTaiKhoanKhachHang(string);
	void SuaThongTinKhachHang(string);

	void InputSearch();
	void TimKiemTaiKhoanQuanTri(string);
	void TimKiemTaiKhoanKhachHang(string);
	void TimKiemThongTinKhachHang();

	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanQuanTri();
	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanKhachHang();
	vector<NodeTaiKhoanQuanTri> XemTatCaThongTinKhachHang();
};

