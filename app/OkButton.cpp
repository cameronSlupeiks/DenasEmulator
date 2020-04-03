
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
    int widgetIndex = stack->currentIndex();

    QWidget *widget = stack->widget(widgetIndex);

    if (!widget) { return -1; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return -1; }

    QLayout *layout = layouts.at(0);

    packet.layout = layout;

    if (widget->objectName() == "power" && widget->findChild<QProgressBar *>("powerLevel")->value() != 0)
    {
        if (processor->request(UPDATE_TIMER, packet) == 0) { return 0; }
    }

    for (int i = 0; i < layout->count(); i++)
    {
        QLabel *currMenuItem  = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());
        QVariant currSelected = currMenuItem->property("selected");

        if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return -1; }

        if (currSelected == true)
        {
            packet.index = i;

            QVariant currEnableDisable = currMenuItem->property("enableDisable");

            if (widget->objectName() == "frequency")
            {
                packet.frequency = currMenuItem->text();

                if (processor->request(UPDATE_FREQUENCY, packet) == 0)
                {
                    return 0;
                }

            }

            if (currEnableDisable.isValid() && currEnableDisable.type() == QMetaType::Bool)
            {
                packet.childName = currMenuItem->objectName();

                if (processor->request(UPDATE_CHANGE_MODE, packet) == 0)
                {
                    return 0;
                }
            }
            else
            {
                if (processor->request(UPDATE_CHANGE_MENU, packet) == 0)
                {
                    return 0;
                }
            }
        }
    }

    return -1;
}
