#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuanLyBanXe.h"

class QuanLyBanXe : public QMainWindow
{
    Q_OBJECT

public:
    QuanLyBanXe(QWidget *parent = nullptr);
    ~QuanLyBanXe();

private:
    Ui::QuanLyBanXeClass ui;
};
