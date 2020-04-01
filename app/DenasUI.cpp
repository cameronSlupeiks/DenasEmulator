#include "DenasUI.h"
#include "battery.h"
#include "ui_denasui.h"
#include "Button.h"
#include "NavButton.h"
#include <QDebug>
#include <QCommonStyle>
#include <QtMath>
#include <QFrame>
#include <QTime>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    ui->setupUi(this);

    QCommonStyle style;

    // Give the buttons some flair with standard icons from the QStyle class.
    ui->backButton->setIcon(style.standardIcon(QStyle::SP_DialogCancelButton));
    ui->mainMenuButton->setIcon(style.standardIcon(QStyle::SP_FileDialogDetailedView));
    ui->okButton->setIcon(style.standardIcon(QStyle::SP_DialogOkButton));
    ui->leftButton->setIcon(style.standardIcon(QStyle::SP_ArrowBack));
    ui->rightButton->setIcon(style.standardIcon(QStyle::SP_ArrowForward));
    ui->upButton->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    ui->downButton->setIcon(style.standardIcon(QStyle::SP_ArrowDown));

    // Initialize the device processor.
    QWidget *device = ui->centralwidget;
    microProcessor = new Microprocessor(device);
    //==================timer for the batery drain plz dont touch=================RAUL/start(2)
    timer = new QTimer(this);
    packet.time = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_exec()));
    //Currently set at: 1/2 min.
    timer->start(1000);//<------sets the intervas(in milisec) at which the function 'battery_darin()' gets called.
    //======================================================================RAUL/end(2)


}
void DenasUI::timer_exec(){
   QWidget *device = ui->centralwidget;
   QCheckBox* temp = device->findChild<QCheckBox*>("checkBox");
   QProgressBar *theBar = device->findChild<QProgressBar*>("progressBar");
   QFrame *screen = device->findChild<QFrame*>("screen");
   if(theBar->value()<=0)
   {
       screen->setVisible(false);
   }
   else if(temp->checkState()==2)
   {
       packet.useCase = "boost";
       packet.unit=10;
   }
   else
   {
        packet.useCase ="";

   }
   microProcessor->request("BATTERY_DRAIN",packet);
}
DenasUI::~DenasUI()
{
    delete ui;
}

void DenasUI::on_upButton_clicked()
{
    QString buttonType = ui->upButton->property("type").toString(); // BUTTON_UP
    microProcessor->request(buttonType);
}

void DenasUI::on_downButton_clicked()
{
    QString buttonType = ui->downButton->property("type").toString(); // BUTTON_DOWN
    microProcessor->request(buttonType);
}

void DenasUI::on_leftButton_clicked()
{
    QString buttonType = ui->leftButton->property("type").toString(); // BUTTON_LEFT
    microProcessor->request(buttonType);
}
void DenasUI::on_rightButton_clicked()
{
    qDebug() << ui->stackedWidget->currentIndex();
    QString buttonType = ui->rightButton->property("type").toString(); // BUTTON_RIGHT
    microProcessor->request(buttonType);
}

void DenasUI::on_okButton_clicked()
{
    QString buttonType = ui->okButton->property("type").toString(); // BUTTON_OK
    microProcessor->request(buttonType);
}

void DenasUI::on_powerButton_clicked()
{
    QString buttonType = ui->powerButton->property("type").toString(); // BUTTON_POWER
    microProcessor->request(buttonType,packet);
}

void DenasUI::on_mainMenuButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    ui->stackedWidget->setCurrentIndex(0);
}

void DenasUI::on_backButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    switch(currStack){
     case 1 :
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 2 :
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 3 :
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 4 :
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 5 :
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 6 :
       ui->stackedWidget->setCurrentIndex(0);
        break;
    case 8 :
       ui->stackedWidget->setCurrentIndex(6);
        break;
    case 9 :
       ui->stackedWidget->setCurrentIndex(6);
        break;
    case 10 :
       ui->stackedWidget->setCurrentIndex(6);
        break;
    case 11 :
       ui->stackedWidget->setCurrentIndex(1);

    }
}
