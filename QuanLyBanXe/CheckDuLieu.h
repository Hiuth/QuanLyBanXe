#pragma once
#include<iostream>
using namespace std;
class CheckDuLieu
{
public:
	bool CheckSpacebar(string);
	bool Check_Number(string);// kiểm tra dữ liệu có phải là số không 
	bool check6Number(string); // kiểm tra mật khẩu nếu nhỏ hơn 6 thì bắt nhập lại 
	bool check9number(string);
	bool check10number(string);//kiểm tra độ dài số điện thoại, giá tiền 
	bool check11number(string);
	bool check12number(string);// kiểm tra độ dài căn cước công dân
	
	bool checkName(string, string);
	bool checkSytax(string);
	bool checkbirthDay(string); // kiểm tra cú pháp ngày tháng năm sinh * đang fix lỗi 
	bool Check_Year(string);


	bool CheckTKQT(string); // kiểm tra tài khoản quản trị có tồn tại không 
	bool CheckTKKH(string);// kiểm tra tài khoản khách hàng có tồn tại không
	bool CheckSDT(string);// kiểm tra số điện thoại có tồn tại trong database hay không
	bool Check_CCCD(string); // kiểm tra cccd có tồn tại trong database không
	bool CheckUserAccount(string,string); // kiểm tra đăng nhập tài khoản khách hàng
	bool CheckManagerAccount(string,string); // kiểm tra đăng nhập tài khoản quản trị 
	bool Check_DataUSer(string); // kiểm tra tài khoản đã có dữ liệu thông tin cá nhân hay chưa 

	bool Check_CarID(string); // kiểm tra mã xe
	bool Check_CarConfigurationID(string); // kiểm tra mã cấu hình
	bool Check_CarName(string); // kiểm tra tên xe
//	bool check_StockQuantity(string);
	bool CheckOderID(string);
	bool Check_OperatingStatus(string,string);
	bool Check_OderStatus(string,string,string);
	bool check_StoreID(string, string);

	int Count_MangerAcc();
	int Count_UserAcc();
	int Count_Store();
	int Count_Car();
	int Count_CarConfiguration();
	int Count_Customer();
	int Count_Order();
	int Count_RequestAssistance();
};

