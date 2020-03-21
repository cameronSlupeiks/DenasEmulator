#include "denasui.h"
#include "ui_denasui.h"

DenasUI::DenasUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DenasUI)
{
    ui->setupUi(this);
}

DenasUI::~DenasUI()
{
    delete ui;
}

