#include "denasui.h"
#include "ui_denasui.h"
#include <iostream>


QProgressBar *progressBar;

int battery =100;

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    ui->setupUi(this);
}

DenasUI::~DenasUI()
{
    delete ui;
}


void DenasUI::on_pushButton_6_clicked(bool checked)
{
    battery = battery - 10;
    std::cout<<battery<< std::endl;
   // progressBar->setValue(bat);
}




void DenasUI::on_progressBar_valueChanged(int value)
{

}
