#pragma once
#include"NodeXe.h"
#include"NodeCauHinhXe.h"
class QuanLyXe
{
private:
	NodeXe* head;
	NodeXe* tail;
	NodeCauHinhXe* headCH;
	NodeCauHinhXe* tailCH;
public:
	QuanLyXe();
	virtual ~QuanLyXe();

	void ThemThongTinXe();
	void ThemCauHinhXe();
	void NhapThongTinXeMoi(NodeXe*);
	void NhapCauHinhXe(NodeCauHinhXe*);

	void NhapThongTinSuaXe();
	void NhapThongTinSuaCauHinh();
	void SuaThongTinXe(string,string,string);
	void SuaCauHinhXe(string,string,string);

	void Xoa();
	void XoaThongTinXe(string);
	void XoaCauHinhXe(string);

	vector<NodeXe> XemThongTinXe();// Xem toàn bộ thông tin xe
	//*tồn kho chỉ có quản trị được xem, người dùng không xem được 

	vector<NodeCauHinhXe> XemCauHinhXe();// dành cho quản trị viên, chức năng dùng để kiểm tra các loại cấu hình còn trong kho 

	void NhapThongTinXeCanTim();
	void NhapThongTinCauHinhCanTim();
	void TimKiemMaXe();
	vector<NodeXe> TimKiemThongTinXe(string,string);// tìm theo tên xe, số túi khí, ...
	vector<NodeCauHinhXe> TimKiemCauHinh(string,string);//tìm kiếm theo nhu cầu như là theo màu sắc, loại pin.
	vector<NodeCauHinhXe> TimMaCauHinh(string, string, string);


	void InThongtinTimKiem(vector<NodeXe>);
	void InThongTinTimKiemCauHinh(vector<NodeCauHinhXe>);

	vector<NodeXe> SapXepTheoGiaTienTangDan(vector<NodeXe>);// theo giá tiền tăng dần hoặc tăng dần 
	vector<NodeXe> SapXepTheoGiaTienGiamDan(vector<NodeXe>);// theo giá tiền tăng dần hoặc giảm dần 
	vector<NodeXe> SapXepTheoTonKhoTangDan(vector<NodeXe>);// theo tồn kho tiền tăng dần hoặc giảm dần, chỉ có quản trị được truy cập tới
	vector<NodeXe> SapXepTheoTonKhoGiamDan(vector<NodeXe>);// theo tồn kho tiền tăng dần hoặc giảm dần, chỉ có quản trị được truy cập

};

