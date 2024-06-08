//#include "QuanLyBanXe.h"
//#include <QtWidgets/QApplication>
//
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QuanLyBanXe w;
//    w.show();
//    return a.exec();
//}

#include<iostream>
#include"KetNoi.h"
#include"QuanLyTaiKhoan.h"
#include"CheckDuLieu.h"
#include"QuanLyXe.h"
#include"DonHang.h"
using namespace std;
int main() {
	KetNoi* KN = new KetNoi();
	TaiKhoanQuanTri* TKQT = new TaiKhoanQuanTri();
	CheckDuLieu* DL = new CheckDuLieu();
	QuanLyXe* Xe = new QuanLyXe();
	DonHang* DH = new DonHang();
	//TKQT->DangNhap();
	//TKQT->NhapDuLieuTaiKhoanQuanTri();
	//6TKQT->NhapDuLieuTaiKhoanKhachHang();
	//TKQT->NhapDuLieuThongTinKhachHang();
	//TKQT->PrintTTKH(TKQT->XemTatCaThongTinKhachHang());
	//TKQT->InputSearchUserInfo();
	cout << endl;
	//TKQT->PrintTTKH(TKQT->XemTatCaThongTinKhachHang());
	//TKQT->InputDelete();
	//TKQT->InputSearch();
	//TKQT->InputEditUser();
	//TKQT->InputSearchUser();
	//TKQT->PrintTKKH(TKQT->XemTatCaTaiKhoanKhachHang());

	//
	//Xe->ThemThongTinXe();
	//Xe->ThemCauHinhXe();
	//Xe->NhapThongTinSuaXe();
	//Xe->Xoa();
	//Xe->NhapThongTinXeCanTim();
	//Xe->NhapThongTinCauHinhCanTim();
	//Xe->TimKiemMaXe();
	//Xe->InThongtinTimKiem(Xe->SapXepTheoGiaTienTangDan(Xe->XemThongTinXe()));
	DH->check_TGT();
}