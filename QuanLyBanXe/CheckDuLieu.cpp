﻿#include "CheckDuLieu.h"
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

bool CheckDuLieu::checkSytax(string Pass)
{
    for (char c : Pass) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
