#pragma once
#include<iostream>
using namespace std;
class CheckDuLieu
{
public:
	bool CheckSpacebar(string);
	bool check6Number(string); // kiểm tra mật khẩu nếu nhỏ hơn 6 thì bắt nhập lại 
	bool check10number(string);//kiểm tra độ dài số điện thoại
	bool check12number(string);// kiểm tra độ dài căn cước công dân
	bool checkName(string, string);
	bool checkSytax(string);
	bool checkbirthDay(string); // kiểm tra cú pháp ngày tháng năm sinh
	bool CheckTKQT(string); // kiểm tra tài khoản quản trị có tồn tại không 
	bool CheckTKKH(string);// kiểm tra tài khoản khách hàng có tồn tại không
	bool CheckSDT(string);// kiểm tra số điện thoại có tồn tại trong database hay không
	bool Check_CCCD(string); // kiểm tra cccd có tồn tại trong database không
	bool CheckUserAccount(string,string); // kiểm tra đăng nhập tài khoản khách hàng
	bool CheckManagerAccount(string,string); // kiểm tra đăng nhập tài khoản quản trị 
	bool Check_DataUSer(string); // kiểm tra tài khoản đã có dữ liệu thông tin cá nhân hay chưa 
};

