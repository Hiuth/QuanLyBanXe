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

bool CheckDuLieu::checkSytax(string Pass)
{
    for (char c : Pass) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}


