#include "KetNoi.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

const char* Link = "tcp://localhost:3306";
const char* Pass = "21122004";
const char* User = "root";
Connection* KetNoi::CheckDatabase() {
	//const char* User{};
	//const char* Pass{};
	//string tenfile = "MySql.txt";
	//ifstream file(tenfile);
	//if (file.is_open()) {
	//	// Đọc dữ liệu từ file và lưu vào các biến User và Pass
	//	string userStr, passStr;
	//	file >> userStr >> passStr;

	//	// Sao chép dữ liệu từ std::string sang const char*
	//	User = _strdup(userStr.c_str());
	//	Pass = _strdup(passStr.c_str());
	//	file.close();
	//}
	//else {
	//	std::cerr << "Không thể mở tệp: " << "MySql" << std::endl;
	//}
	KetNoi check{};
	MySQL_Driver* driver;
	Connection* con;
	driver = mysql::get_mysql_driver_instance();
	con = driver->connect(Link, User, Pass);
	Statement* stmt = con->createStatement();
	stmt->execute("CREATE SCHEMA IF NOT EXISTS DaiLy");

	con->setSchema("DaiLy");
	if (con) {
		return con;
	}
	else {
		return con;
	}
}
