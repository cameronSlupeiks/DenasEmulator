#include <QDebug>
#include "ControlButton.h"

/*
 * Constructor: ControlButton (copy)
 * Purpose: initialize a copy of the parent class, Button.
 *
 * in: a Button reference (const Button)
 */
ControlButton::ControlButton(const Button &button) : Button(button), processor(Button::processor) {}

/*
 * Function: increment_decrement
 * Purpose: to increment or decrement the power level bar
 *
 * in: step (integer)
 * return: 0 if successfull, -1 otherwise.
 */
int ControlButton::increment_decrement(int step)
{
    stack = device->findChild<QStackedWidget*>("stackedWidget");

    // Get the index of the current widget within the stack.
    int widgetIndex = stack->currentIndex();

    // Get the current widget within the stack.
    QWidget *widget = stack->widget(widgetIndex);

    // Set packet step
    packet.step = step;

    if (!widget) {return -1;}
    else if (widget->objectName() == "power") {
        processor->request(UPDATE_POWER_LEVEL, packet);
        return 0;
    }

    return -1;
}
