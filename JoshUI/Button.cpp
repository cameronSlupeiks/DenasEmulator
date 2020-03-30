#include <QDebug>
#include "Macros.h"
#include "Button.h"
#include "NavButtons.h"
#include "PowerButton.h"
#include "Microprocessor.h"

/*
 * Constructor: Button (override)
 * Purpose: initialize an instance of this class
 *
 * in: the display stack (QStackedWidget*)
 */
Button::Button(QWidget *device) : on(new bool(true)), device(device) {}

/*
 * Function: press
 * Purpose: to determine and call the necessary function associated with the type (macro) parameter.
 *
 * in: a type (QString) (i.e., BUTTON_UP, BUTTON_DOWN, BUTTON_POWER, etc.)
 * return: not a predefined type (macro) for this function or function error (-1); otherwise, function call successful (0).
 */
int Button::press(QString type)
{
    if (type == BUTTON_UP)
    {
        return NavButton(*this).navigate(-1);
    }
    else if (type == BUTTON_DOWN)
    {
        return NavButton(*this).navigate(1);
    }
    else if (type == BUTTON_POWER)
    {
        return PowerButton(*this).toggle();
    }

    return -1;
}
