﻿#pragma once
#include"NodeDaiLy.h"
#include"NodeLHBaoDuong.h"
#include"NodeHoTro.h"
#include"QuanLyXe.h"
#include"NodeDonHang.h"
class QuanLyDVvaCSKH
{
private:
	NodeDaiLy* head;
	NodeDaiLy* tail;
	NodeLHBaoDuong* headBD;
	NodeLHBaoDuong* tailBD;
	NodeHoTro* headHT;
	NodeHoTro* tailHT;
public:
	QuanLyDVvaCSKH();
	virtual ~QuanLyDVvaCSKH();

	void NhapThongTinYeuCauHoTro();// dành cho người dùng
	void PhanHoi();
	vector<NodeHoTro> XemTrangThaiYeuCauHoTro(string);//dành cho quản trị
	void PhanHoiYeuCauHoTro(string); //dành cho quản trị
	void YeuCauDichVuHoTro(NodeHoTro*);

	void NhapThongTinLichHen();
	void DatLichHenBaoDuong(NodeLHBaoDuong*);
	vector<NodeLHBaoDuong> XemLichSuBaoDuong(string);// cho nguoi dung
	vector<NodeHoTro> XemLichSuYeuCauHoTro(string);
	vector<NodeDonHang> XemLichSuDonDatHangTheoSDT(string);
	vector<NodeDonHang> XemLichSuDonDatHangTheoEmail(string);

	void SuaLichHenTheoSDT(string, string, string); // dành do quản trị được khách hàng yêu cầu sửa 
	void SuaLichHenTheoEmail(string,string,string); //sửa online dành do khách hàng tự sửa
	void SuaThongTinYeuCauHoTro(string,string,string);

	void XoaYeuCauHoTro(string);// áp dụng cho yêu cầu ở trạng thái chưa được xử lý?
	void XoaLichHenTheoEmail(string);//áp dụng cho khách hàng tự xóa online
	void XoaLichHenTheoSDT(string); // áp dụng cho quản trị tự xóa

};

