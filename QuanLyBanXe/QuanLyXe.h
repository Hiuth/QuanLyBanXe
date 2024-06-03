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

	void NhapThongTinXeMoi(NodeXe*);
	void NhapCauHinhXe(NodeCauHinhXe*);

	void SuaThongTinXe(NodeXe*);
	void SuaCauHinhXe(NodeCauHinhXe*);

	vector<NodeXe> XemThongTinXe();// Xem toàn bộ thông tin xe
	vector<NodeCauHinhXe> XemCauHinhXe();// dành cho quản trị viên, chức năng dùng để kiểm tra các loại cấu hình còn trong kho 

	vector<NodeXe> TimKiemThongTinXe();// tìm theo tên xe, số túi khí, ...
	vector<NodeCauHinhXe> TimKiemCauHinhXe();//tìm kiếm theo nhu cầu như là theo màu sắc, loại pin.

	void InThongtinTimKiem(vector<NodeXe>);
	void InThongTinTimKiemCauHinh(vector<NodeCauHinhXe>);

	vector<NodeXe> SapXepTheoYeuCau();// theo giá tiền tăng dần hoặc giảm dần 
};

