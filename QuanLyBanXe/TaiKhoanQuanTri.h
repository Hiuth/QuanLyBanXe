#pragma once
#include"NodeTaiKhoanQuanTri.h"
#include"NodeTaiKhoanKhachHang.h"
class TaiKhoanQuanTri
{
private:
	NodeTaiKhoanQuanTri* head;
	NodeTaiKhoanQuanTri* tail;
public:
	TaiKhoanQuanTri();
	virtual ~TaiKhoanQuanTri();

	void NhapDuLieuTaiKhoanQuanTri();
	void NhapDuLieuTaiKhoanKhachHang();
	void TaoTaiKhoanQuanTri(NodeTaiKhoanQuanTri*);
	void TaoTaiKhoanKhachHang(NodeTaiKhoanKhachHang*);

	void InputDelete();
	void XoaTaiKhoanQuanTri(string);
	void XoaTaiKhoanKhachHang(string);
	
	void InputEditManager();
	void InputEditUser();
	void SuaTaiKhoanQuanTri(string, string, string);
	void SuaTaiKhoanKhachHang(string,string,string);
	void SuaThongTinKhachHang(string,string,string);

	void InputSearch();
	vector<NodeTaiKhoanQuanTri>TimKiemTaiKhoanQuanTri(string);
	vector<NodeTaiKhoanKhachHang> TimKiemTaiKhoanKhachHang(string);
	vector<NodeTaiKhoanKhachHang> TimKiemThongTinKhachHang();

	vector<NodeTaiKhoanQuanTri> XemTatCaTaiKhoanQuanTri();
	vector<NodeTaiKhoanKhachHang> XemTatCaTaiKhoanKhachHang();
	vector<NodeTaiKhoanKhachHang> XemTatCaThongTinKhachHang();

	void PrintQT(vector<NodeTaiKhoanQuanTri>);
	void PrintTKKH(vector<NodeTaiKhoanKhachHang>);
};

