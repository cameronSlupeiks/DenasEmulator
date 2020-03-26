#include "denasui.h"
#include "ui_denasui.h"
#include <QDebug>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
   int volume = 25;        //place holder for volume setting
   //int childRange = 0;    //This code is a place holder for child range
    ui->setupUi(this);
}

DenasUI::~DenasUI()
{
    delete ui;
}

void DenasUI::on_upButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget) { return; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return; }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = layout->count() - 1; i >= 0; i--)
    {
        int prevIndex = i - 1;
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true && prevIndex >= 0)
        {
            // We found the currently selected menu item and it's not the last menu item in the list.
            QLabel *prevMenuItem = dynamic_cast<QLabel *>(layout->itemAt(prevIndex)->widget());
            QVariant nextSelected = prevMenuItem->property("selected");

            if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

            // Set the next menu item as selected.
            currMenuItem->setProperty("selected", false);
            currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
            prevMenuItem->setProperty("selected", true);
            prevMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

            break;
        }
    }
}

void DenasUI::on_downButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget) { return; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return; }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = 0; i < layout->count(); i++)
    {
        int nextIndex = i + 1;
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true && nextIndex < layout->count())
        {
            // We found the currently selected menu item and it's not the last menu item in the list.
            QLabel *nextMenuItem = dynamic_cast<QLabel *>(layout->itemAt(nextIndex)->widget());
            QVariant nextSelected = nextMenuItem->property("selected");

            if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

            // Set the next menu item as selected.
            currMenuItem->setProperty("selected", false);
            currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
            nextMenuItem->setProperty("selected", true);
            nextMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

            break;
        }
    }
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
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget)
    {
        return;
    }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty())
    {
        return;
    }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = 0; i < layout->count(); i++)
    {
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true)
        {
            QVariant currEnableDisable = currMenuItem->property("enableDisable");

            if (currEnableDisable.isValid() && currEnableDisable.type() == QMetaType::Bool)
            {
                // Menu item does not contain a submenu, therefore we know it must toggle/trigger some functionality.

                /*
                 * Add functionality (i.e., what do the child modes do).
                 */
            }
            else
            {
                // Get the QWidget with the object name that is the same as the menu item selected.
                QWidget *stack = ui->stackedWidget->findChild<QWidget *>(currMenuItem->text().toLower());

                // If there is a QWidget that exists with the same menu item name, make it the current widget.
                if (stack)
                {
                    ui->stackedWidget->setCurrentWidget(stack);

                    break;
                }
            }
        }
    }
}

void DenasUI::on_powerButton_clicked()
{
    for (int i = 0; i < ui->navButtons->count(); i++)
    {
        QPushButton *powerButton = dynamic_cast<QPushButton *>(ui->navButtons->itemAt(i)->widget());

        QVariant isOn = powerButton->property("on");

        if (isOn.isValid())
        {
            if (isOn == true)
            {
                ui->screen->setHidden(true);
                powerButton->setProperty("on", false);
            }
            else
            {
                ui->screen->setHidden(false);
                powerButton->setProperty("on", true);
            }
        }
    }
}
