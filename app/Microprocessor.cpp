
#include <QDebug>
#include "Microprocessor.h"

/*
 * Constructor: Microprocessor (default)
 * Purpose: initialize a default instance of this class.
 */
Microprocessor::Microprocessor()
{
    qDebug() << "Constructing processor default...";
}

/*
 * Constructor: Microprocessor (copy)
 * Purpose: initialize a copy of an instance of this class.
 *
 * in: a microprocessor reference (const Microprocessor)
 */
Microprocessor::Microprocessor(const Microprocessor &processor)
{
    qDebug() << "Constructing processor copy...";
}

/*
 * Constructor: Microprocessor (override)
 * Purpose: initialize an instance of this class.
 *
 * in: the display stack (QStackedWidget*)
 */
Microprocessor::Microprocessor(QWidget *device) : button(new Button(this, device)), display(new Display(device))
{
    battery = new Battery(device);
    qDebug() << "Constructing processor override...";
}

/*
 * Function: request
 * Purpose: to determine and call the necessary function with no packet request associated with the macro parameter.
 *
 * in: a macro (QString) (i.e., BUTTON_UP, BUTTON_DOWN)
 * return: not a predefined macro for this function r function error (-1); otherwise, function call successfull (0).
 */
int Microprocessor::request(QString macro)
{
    if (macro == BUTTON_UP || macro == BUTTON_DOWN || macro == BUTTON_LEFT ||
        macro == BUTTON_RIGHT || macro == BUTTON_POWER || macro == BUTTON_OK)
    {
        return button->press(macro);
    }

    return -1;
}

/*
 * Function: request
 * Purpose: to determine and call the necessary function with a packet request associated with the macro parameter.
 *
 * in: a macro (QString) (i.e., UPDATE_SELECT_ITEM), a packet request (struct request)
 * return: not a predefined macro or function error (-1); otherwise, function call successful (0).
 */
int Microprocessor::request(QString macro, struct request packet)
{
    if (macro == UPDATE_SELECT_ITEM || macro == UPDATE_CHANGE_MODE || macro == UPDATE_CHANGE_MENU || macro == UPDATE_POWER_LEVEL)
    {
        return display->update(macro, packet);
    }
    else if(macro == BUTTON_POWER)
    {
        return button->press(macro,packet);
    }
    else if(macro == BATTERY_DRAIN)
    {
        return battery->battery_darin(packet.useCase,packet.unit);
    }

    return -1;
}
