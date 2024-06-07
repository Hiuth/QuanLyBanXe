#include "CheckDuLieu.h"
#include"KetNoi.h"
#include<ctime>
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

bool CheckDuLieu::Check_Number(string number)
{
    for (char c : number) {
        if (!isdigit(c)) {
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

bool CheckDuLieu::check9number(string money)
{
    if (money.size() != 9) {
        return false;
    }
    for (char c : money) {
        if (!isdigit(c)) {
            return false;
        }
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

bool CheckDuLieu::check11number(string Money)
{
    if (Money.size() != 11) {
        return false;
    }
    for (char c : Money) {
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

/*now->tm_year + 1900: Trong cấu trúc tm, tm_year lưu trữ số năm kể từ năm 1900. Vì vậy, để lấy năm hiện tại, chúng ta cần cộng thêm 1900.
now->tm_mon + 1: Trong cấu trúc tm, tm_mon lưu trữ tháng từ 0 (tháng 1) đến 11 (tháng 12). Do đó, để lấy tháng hiện tại, chúng ta cần cộng thêm 1.
now->tm_mday: Trong cấu trúc tm, tm_mday lưu trữ ngày trong tháng từ 1 đến 31. Do đó, now->tm_mday sẽ trả về ngày hiện tại.*/

bool CheckDuLieu::Check_Year(string year)
{
    time_t t = time(0);   // get time now
    struct tm* now = localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    if (stoi(year) > currentYear) {
        return false;
    }
    return true;
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

bool CheckDuLieu::Check_CarID(string carID)
{
    try {
        Statement* stmt;
        stmt = Check_DL->createStatement();
        string SelectData = "SELECT * FROM XEVINFAST WHERE MaXe = '" + carID + "'";
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

bool CheckDuLieu::Check_CarConfigurationID(string configurationID)
{
    try {
        Statement* stmt;
        stmt = Check_DL->createStatement();
        string SelectData = "SELECT * FROM CauHinhXe WHERE MaCauHinh = '" + configurationID + "'";
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

bool CheckDuLieu::Check_CarName(string TenXe)
{
    try {
        Statement* stmt;
        stmt = Check_DL->createStatement();
        string SelectData = "SELECT * FROM XEVINFAST WHERE TenXe = '" + TenXe + "'";
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


