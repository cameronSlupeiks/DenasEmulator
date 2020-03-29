#include "denasui.h"
#include "ui_denasui.h"
#include "Button.h"
#include "NavButtons.h"
#include <QDebug>
#include <QCommonStyle>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    int volume = 25;        //place holder for volume setting
    //int childRange = 0;    //This code is a place holder for child range
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

    }

}

void DenasUI::on_volumeSlider_sliderMoved(int position)
{
    ui->volumeSlider->value();
}

void DenasUI::on_okButton_clicked()
{
    QString buttonType = ui->okButton->property("type").toString(); // BUTTON_OK
    microProcessor->request(buttonType);

//    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
//    int currStack = ui->stackedWidget->currentIndex();

//    // Get the current stack.
//    QWidget *widget = ui->stackedWidget->widget(currStack);

//    if (!widget)
//    {
//        return;
//    }

//    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

//    if (layouts.isEmpty())
//    {
//        return;
//    }

//    // Each QWidget within the stack has only one layout with other objects as menu items.
//    // Get the layout of the current QWidget.
//    QLayout *layout = layouts.at(0);

//    for (int i = 0; i < layout->count(); i++)
//    {
//        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

//        QVariant currSelected = currMenuItem->property("selected");

//        if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

//        if (currSelected == true)
//        {
//            QVariant currEnableDisable = currMenuItem->property("enableDisable");

//            if (currEnableDisable.isValid() && currEnableDisable.type() == QMetaType::Bool)
//            {
//                // Menu item does not contain a submenu, therefore we know it must toggle/trigger some functionality.

//                /*
//                 * Add functionality (i.e., what do the child modes do).
//                 */
//            }
//            else
//            {
//                // Get the QWidget with the object name that is the same as the menu item selected.
//                QWidget *stack = ui->stackedWidget->findChild<QWidget *>(currMenuItem->text().toLower());

//                // If there is a QWidget that exists with the same menu item name, make it the current widget.
//                if (stack)
//                {
//                    ui->stackedWidget->setCurrentWidget(stack);

//                    break;
//                }
//            }
//        }
//    }
}

void DenasUI::on_powerButton_clicked()
{
    QString buttonType = ui->powerButton->property("type").toString(); // BUTTON_POWER
    microProcessor->request(buttonType);
}
