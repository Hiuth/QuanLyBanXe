#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NodeTaiKhoanQuanTri
{
private:
	string ManagerAccountName;
	string ManagerAccountPass;
	string ManagerAccountID;
	string ManagerAccountEmail;
public:
	NodeTaiKhoanQuanTri( string, string,string);
	NodeTaiKhoanQuanTri(string, string, string,string);
	virtual ~NodeTaiKhoanQuanTri();
	string GetManagerAccountName() { return ManagerAccountName; }
	void SetMangerAccountName(string val) { ManagerAccountName = val; }
	string GetManagerAccountPass() { return ManagerAccountPass; }
	void SetManagerAccountPass(string val) { ManagerAccountPass = val; }
	string GetManagerAccountID() { return ManagerAccountID; }
	void SetManagerAccountID(string val) { ManagerAccountID = val; }
	string GetManagerAccountEmail() { return ManagerAccountEmail; }
	void SetManagerAccountEmail(string val) { ManagerAccountEmail = val; }
};

