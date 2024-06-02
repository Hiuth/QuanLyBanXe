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
using namespace std;
int main() {
	KetNoi* KN = new KetNoi();
	TaiKhoanQuanTri* TKQT = new TaiKhoanQuanTri();
	CheckDuLieu* DL = new CheckDuLieu();
	string CCCD;
	cout << "So can cuoc cong dan: "; cin >> CCCD;
	if (DL->check12number(CCCD)) {
		if (DL->Check_CCCD(CCCD)) {
			cout << "So CCCD da ton tai! Vui long kiem tra lai";
		}
		else {
			cout << "Nhap CCCD thanh cong" << endl;
		}
	}
	else {
		cout << "SO CCCD PHAI CO 12 SO VA KHONG DUOC CO KI TU KHAC NGOAI SO!" << endl;
	}

	//TKQT->DangNhap();
	//TKQT->NhapDuLieuTaiKhoanQuanTri();
	//6TKQT->NhapDuLieuTaiKhoanKhachHang();
	TKQT->NhapDuLieuThongTinKhachHang();
	//TKQT->PrintTTKH(TKQT->XemTatCaThongTinKhachHang());
	//TKQT->InputSearchUserInfo();
	cout << endl;
	TKQT->InputEditUserinfo();
	cout << endl;
	TKQT->PrintTTKH(TKQT->XemTatCaThongTinKhachHang());
	//TKQT->InputDelete();
	//TKQT->InputSearch();
	//TKQT->InputEditUser();
	//TKQT->InputSearchUser();
	//TKQT->PrintTKKH(TKQT->XemTatCaTaiKhoanKhachHang());
}