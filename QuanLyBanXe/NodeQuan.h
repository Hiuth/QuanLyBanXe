#pragma once
#include<iostream>
using namespace std;
class NodeQuan
{
private:
	string Quan;
	string ThanhPho;
public:
	NodeQuan(string, string);
	NodeQuan(string);
	virtual ~NodeQuan();

	string LayQuan() { return Quan; }
	void CaiDatQuan(string val) { Quan = val; }

	string LayThanhPho() { return ThanhPho; }
	void CaiDatThanhPho(string val) { ThanhPho = val; }
};

