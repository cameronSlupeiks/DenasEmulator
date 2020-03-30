#include <QDebug>
#include "PowerButton.h"

/*
 * Constructor: PowerButton (copy)
 * Purpose: initialize a copy of the parent class, Button.
 *
 * in: a Button reference (const Button)
 */
PowerButton::PowerButton(const Button &button) : Button(button)
{
    qDebug() << "Constructing PowerButton copy of Button...";
}

/*
 * Function: toggle
 * Purpose: to turn on or off the device display.
 *
 * return: success of toggling display power (0).
 */
int PowerButton::toggle()
{
    QFrame *screen = device->findChild<QFrame*>("screen");

    screen->setHidden(*on);
    *on = !(*on);

    return 0;
}
