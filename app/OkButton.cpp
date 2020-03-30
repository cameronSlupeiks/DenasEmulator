#include <QDebug>
#include "OkButton.h"

/*
 * Constructor: OkButton
 * Purpose: initialize a copy of the parent class, Button.
 */
OkButton::OkButton(const Button &button) : Button(button), processor(Button::processor)
{
    qDebug() << "Constructing OkButton copy of Button...";
}

/*
 * Function: confirm
 * Purpose: to confirm the selection of a menu item or option.
 *
 * return: success (0); otherwise, error (-1)
 */
int OkButton::confirm()
{
    stack = device->findChild<QStackedWidget*>("stackedWidget");

    int widgetIndex = stack->currentIndex();

    QWidget *widget = stack->widget(widgetIndex);

    if (!widget) { return -1; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return -1; }

    QLayout *layout = layouts.at(0);

    packet.layout = layout;

    for (int i = 0; i < layout->count(); i++)
    {
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return -1; }

        if (currSelected == true)
        {
            packet.index = i;

            QVariant currEnableDisable = currMenuItem->property("enableDisable");

            if (currEnableDisable.isValid() && currEnableDisable.type() == QMetaType::Bool)
            {
                qDebug() << "Change mode request...";

                if (processor->request(UPDATE_CHANGE_MODE, packet) == 0)
                {
                    return 0;
                }
            }
            else
            {
                qDebug() << "Change menu request...";

                if (processor->request(UPDATE_CHANGE_MENU, packet) == 0)
                {
                    return 0;
                }
            }
        }
    }

    return -1;
}
