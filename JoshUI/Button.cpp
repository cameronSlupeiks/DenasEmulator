
#include <QDebug>
#include "Macros.h"
#include "Button.h"
#include "OkButton.h"
#include "NavButtons.h"
#include "PowerButton.h"
#include "ControlButton.h"

/*
 * Constructor: Button (override)
 * Purpose: initialize an instance of this class
 *
 * in: the display stack (QStackedWidget*)
 */
Button::Button(Microprocessor *processor, QWidget *device) : device(device), on(new bool(true)), processor(processor)
{
    qDebug() << "Constructing button...";
}

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
    else if (type == BUTTON_LEFT)
    {
        return ControlButton(*this).increment_decrement(-1);
    }
    else if (type == BUTTON_RIGHT)
    {
        return ControlButton(*this).increment_decrement(1);
    }
    else if (type == BUTTON_POWER)
    {
        return PowerButton(*this).toggle();
    }
    else if (type == BUTTON_OK)
    {
        return OkButton(*this).confirm();
    }

    return -1;
}
