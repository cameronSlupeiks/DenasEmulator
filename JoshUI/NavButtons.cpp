#include <QDebug>
#include "NavButtons.h"

/*
 * Constructor: NavButton (copy)
 * Purpose: initialize a copy of the parent class, Button.
 *
 * in: a Button reference (const Button)
 */
NavButton::NavButton(const Button &button) : Button(button), processor(Button::processor)
{
    qDebug() << "Constructing NavButton copy of Button...";
}

/*
 * Function: navigate
 * Purpose: to navigate the list of menu items based on the incrementing or decrementing by the step parameter amount
 *
 * in: step (integer)
 * return: the current widget is null or has no layout, function error, invalid step value parameter, or menu item out of range (-1);
 *         otherwise, function successful (0).
 */
int NavButton::navigate(int step)
{
    stack = device->findChild<QStackedWidget*>("stackedWidget");

    // Get the index of the current widget within the stack.
    int widgetIndex = stack->currentIndex();

    // Get the current widget within the stack.
    QWidget *widget = stack->widget(widgetIndex);

    if (!widget) { return -1; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return -1; }

    // There is only one layout associated with each widget within the stack.
    QLayout *layout = layouts.at(0);

    // Initialize the packet step value and layout.
    packet.step = step;
    packet.layout = layout;

    if (step == -1)
    {
        // The step value is negative, navigate up 1.
        for (int i = layout->count() - 1; i >= 0; i--)
        {
            // Initialize the packet index.
            packet.index = i;

            // Call the copy constructor for the processor associated with this button.
            // This is necessary since we want the display associated with this processor
            // to receive an instance of this packet request, not a new one with default values.
            if (processor->request(UPDATE_SELECT_ITEM, packet) == 0)
            {
                return 0;
            }
        }
    }
    else if (step == 1)
    {
        // The step is negative, navigate down 1.
        for (int i = 0; i < layout->count(); i++)
        {
            packet.index = i;

            if (processor->request(UPDATE_SELECT_ITEM, packet) == 0)
            {
                return 0;
            }
        }
    }

    // Step value not valid or next menu item out of range.
    return -1;
}
