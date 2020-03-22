#include "denasui.h"
#include "ui_denasui.h"

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    ui->setupUi(this);
}

DenasUI::~DenasUI()
{
    delete ui;
}


void DenasUI::on_programsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void DenasUI::on_frequencyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void DenasUI::on_medButton_clicked()
{
    ui-> stackedWidget->setCurrentIndex(3);
}

void DenasUI::on_screeningButton_clicked()
{
    ui-> stackedWidget->setCurrentIndex(4);
}

void DenasUI::on_childButton_clicked()
{
    ui-> stackedWidget->setCurrentIndex(5);
}

void DenasUI::on_settingsButton_clicked()
{
     ui-> stackedWidget->setCurrentIndex(6);
}


