#pragma once
#include"NodeTaiKhoanQuanTri.h"
#include"NodeTaiKhoanKhachHang.h"
#include"NodeKhachHang.h"
class TaiKhoanQuanTri
{
private:
	NodeTaiKhoanQuanTri* head;
	NodeTaiKhoanQuanTri* tail;
public:
	TaiKhoanQuanTri();
	virtual ~TaiKhoanQuanTri();
	void DangNhap();

	void NhapDuLieuTaiKhoanQuanTri();
	void NhapDuLieuTaiKhoanKhachHang();
	void TaoTaiKhoanQuanTri(NodeTaiKhoanQuanTri*);
	void TaoTaiKhoanKhachHang(NodeTaiKhoanKhachHang*);
	void ThemThongTinKhachHang(NodeKhachHang*);

	void InputDelete();
	void XoaTaiKhoanQuanTri(string);
	void XoaTaiKhoanKhachHang(string);
	
	void InputEditManager();
	void InputEditUser();
	void SuaTaiKhoanQuanTri(string, string, string);
	void SuaTaiKhoanKhachHang(string,string,string);
	void SuaThongTinKhachHang(string,string,string);

	void InputSearchManager();
	void InputSearchUser();
	vector<NodeTaiKhoanQuanTri>TimKiemTaiKhoanQuanTri(string);
	vector<NodeTaiKhoanKhachHang> TimKiemTaiKhoanKhachHang(string);
	vector<NodeKhachHang> TimKiemThongTinKhachHang();

	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanQuanTri();
	vector<NodeTaiKhoanKhachHang> XemTatCaTaiKhoanKhachHang();
	vector<NodeKhachHang> XemTatCaThongTinKhachHang();


	void PrintQT(vector<NodeTaiKhoanQuanTri>);
	void PrintTKKH(vector<NodeTaiKhoanKhachHang>);
	void PrintTTKH(vector<NodeKhachHang>);
};

