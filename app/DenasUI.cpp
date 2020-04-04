#include "DenasUI.h"
#include "Button.h"
#include <QDebug>
#include <QCommonStyle>
#include "ui_DenasUI.h"

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

    // Initialize and start the battery timer.

    timer = new QTimer(this);
    packet.time = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_exec()));
    timer->start(9000);
}

/*
void DenasUI::timer_exec(){

   QWidget *device = ui->centralwidget;
   QProgressBar *theBar = device->findChild<QProgressBar*>("progressBar");

   if (theBar->value() <= 2)
   {
       packet.func = "dead";
       microProcessor->request("BATTERY_DEAD", packet);
   }
   else if (theBar->value() <= 20)
   {
       packet.func = "warning";
       microProcessor->request("BATTERY_WARNING",packet);
   }

   QCheckBox* temp = device->findChild<QCheckBox*>("checkBox");

   if (temp->checkState() == 2) {packet.useCase = "contact";}
   else {packet.useCase = "";}

   packet.func = "drain";
   microProcessor->request("BATTERY_DRAIN", packet);
}
*/

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
    microProcessor->request(buttonType);
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
       if (ui->stackedWidget->currentWidget()->objectName() == "med") {microProcessor->request();}
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

void DenasUI::on_externalElectrode_stateChanged(int arg1)
{
    // Get the list of programs.
    QList<QLabel *> programs = ui->programs->findChildren<QLabel *>();

    if (ui->externalElectrode->isChecked())
    {
        // The user selected the external electrode checkbox.
        // Generate a random index according to how many programs there are.
        int randomIndex = rand() % programs.size();

        if (programs.at(randomIndex)->property("selected").toBool())
        {
            // The random index happens to be the selected program.
            // If it was the last program, make the random index the first program.
            // Otherwise, set the random index to the next program.
            randomIndex = ((randomIndex + 1) % programs.size());
        }

        // Disable the program at the random index.
        programs.at(randomIndex)->setEnabled(false);
    }
    else
    {
        // Enable all programs.
        for (int i = 0; i < programs.size(); i++)
        {
            programs.at(i)->setEnabled(true);
        }
    }
}
