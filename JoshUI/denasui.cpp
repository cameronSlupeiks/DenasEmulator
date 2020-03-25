#include "denasui.h"
#include "ui_denasui.h"
#include <QDebug>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
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

    // Each QWidget (stack) has only one layout with QLabel objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = widget->findChildren<QLayout *>().at(0);

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

            if (nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

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

    // Each QWidget (stack) has only one layout with QLabel objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = widget->findChildren<QLayout *>().at(0);

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

            if (nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

            // Set the next menu item as selected.
            currMenuItem->setProperty("selected", false);
            currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
            nextMenuItem->setProperty("selected", true);
            nextMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

            break;
        }
    }
}
