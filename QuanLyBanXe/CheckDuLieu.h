#pragma once
#include<iostream>
using namespace std;
class CheckDuLieu
{
public:
	bool CheckSpacebar(string);
	bool check6Number(string); // kiểm tra mật khẩu nếu nhỏ hơn 6 thì bắt nhập lại 
	bool checkName(string, string);
	bool checkSytax(string);
	bool checkbirthDay(string);
	bool CheckTKQT(string);
	bool CheckTKKH(string);
	bool CheckSDT(string);
	bool CheckUserAccount(string,string);
	bool CheckManagerAccount(string,string);
};

