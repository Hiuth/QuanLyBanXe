#pragma once
#include<iostream>
#include<string>
using namespace std;
class NodeThanhPho
{
private:
	string ThanhPho;
public:
	NodeThanhPho(string);
	virtual ~NodeThanhPho();

	string LayThanhPho() { return ThanhPho; }
	void CaiDatThanhPho(string val) { ThanhPho = val; }
};

