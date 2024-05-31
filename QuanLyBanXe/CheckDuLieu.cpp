#include "CheckDuLieu.h"
#include"KetNoi.h"
KetNoi* Check_DuLieu= new KetNoi();
Connection* Check_DL = Check_DuLieu->CheckDatabase();
bool CheckDuLieu::CheckSpacebar(string NameAcc)
{
    for (char c : NameAcc) {
        if (isspace(c)) {// nếu có khoảng cách trắng thì trả về false
            return false;
        }
    }
    return true;
}

bool CheckDuLieu::check6Number(string Pass)
{
    if (Pass.size() < 6) {
        return false;
    }
    return true;
}

bool CheckDuLieu::check10number(string SDT)
{
    if (SDT.size() != 10) {
        return false;
    }
    for (char c : SDT) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


bool CheckDuLieu::check12number(string CCCD) 
{
    if (CCCD.size() != 12) {
        return false;
    }
    for (char c : CCCD) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool CheckDuLieu::checkbirthDay(string check) { // need to fix
    for (char c : check) {
        if (!isdigit(c) && c != '/') {
            return false;
        }
    }return true;
}

bool CheckDuLieu::CheckTKQT(string Email)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from ManagerAccount where ManagerEmail = '" + Email + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::CheckTKKH(string Email)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from UserAccount where UserEmail = '" + Email + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::CheckSDT(string SDT)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from KhachHang where SDT = '" + SDT + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::Check_CCCD(string CCCD)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from KhachHang where SDT = '" + CCCD + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::CheckManagerAccount(string Email, string Pass)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from ManagerAccount where ManagerEmail = '" + Email + "' AND ManagerPass = '" + Pass + "' ";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::Check_DataUSer(string Email)
{
    try {
        Statement* stmt;
        stmt = Check_DL->createStatement();
        string SelectData = "SELECT * FROM KhachHang WHERE UserEmail = '" + Email + "'";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            return true;
        }
        return false;
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

bool CheckDuLieu::CheckUserAccount(string Email, string Pass)
{
    Statement* stmt;
    stmt = Check_DL->createStatement();
    string SelectData = "Select *from UserAccount where UserEmail = '" + Email + "' AND UserPass = '" + Pass + "' ";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool CheckDuLieu::checkSytax(string Pass)
{
    for (char c : Pass) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}


