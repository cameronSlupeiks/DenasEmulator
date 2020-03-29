#include <QDebug>
#include "Display.h"

/*
 * Constructor: Display (default)
 * Purpose: initialize a default instance of this class.
 */
Display::Display(QWidget *device) : device(device)
{
    qDebug() << "Constructing display...";
}

/*
 * Function: update
 * Purpose: to determine and call the necessary function of this class associated with the type (macro)
 *          and unpack the packet request to be passed as input values to the respective function call.
 *
 * in: a type (QString) (i.e., UPDATE_SELECT_ITEM, UPDATE_SELECT_MENU), a packet request (struct request)
 * return: not a predefined type (macro) for this function or function error (-1); otherwise, function call successful (0).
 */
int Display::update(QString type, struct request packet)
{
    if (type == UPDATE_SELECT_ITEM)
    {
        return updateSelectMenuItem(packet.index, packet.step, packet.layout);
    }
    else if (type == UPDATE_CHANGE_MODE)
    {
        return updateMode();
    }
    else if (type == UPDATE_CHANGE_MENU)
    {
        return updateMenu(packet.index, packet.layout);
    }

    return -1;
}

int Display::updateMode()
{
    // Note: Josh and Cam S., implement what you want here.
    // This is for menu items that do not have a submenu (i.e., selecting a child mode or frequency).
    return -1;
}

/*
 * Function: updateMenu
 * Purpose: to change to the submenu within the current menu item at the index parameter within the stack
 *
 * in: an index (integer), a layout (QLayout*)
 * return: success (0); otherwise, error (-1).
 */
int Display::updateMenu(int index, QLayout *layout)
{
    stack = device->findChild<QStackedWidget *>("stackedWidget");

    QLabel *currMenu = dynamic_cast<QLabel *>(layout->itemAt(index)->widget());
    QWidget *subMenu = stack->findChild<QWidget *>(currMenu->text().toLower());

    if (subMenu)
    {
        stack->setCurrentWidget(subMenu);

        return 0;
    }

    return -1;
}

/*
 * Function: updateSelectMenuItem
 * Purpose: to update the display by selecting the next menu item in the current menu.
 *
 * in: an index (integer), a step value (integer), a layout (QLayout*)
 * return: success (0); otherwise, error (-1).
 */
int Display::updateSelectMenuItem(int index, int step, QLayout *layout)
{
    int nextIndex = index + step;

    QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(index)->widget());

    QVariant currSelected = currMenuItem->property("selected");

    // If the menu item does not have a "selected" property that is a boolean, return with error -1.
    if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return -1; }

    if (currSelected == true && nextIndex < layout->count() && nextIndex >= 0)
    {
        // We found the currently selected menu item.
        // The next menu item is within range, so get its widget for property and text manipulation.
        QLabel *nextMenuItem = dynamic_cast<QLabel *>(layout->itemAt(nextIndex)->widget());
        QVariant nextSelected = nextMenuItem->property("selected");

        // If the next menu item to select does not have a "selected" property that is a boolean, return with error -1.
        if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return -1; }

        // Set the next menu item as selected and unselect the previous menu item.
        currMenuItem->setProperty("selected", false);
        currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
        nextMenuItem->setProperty("selected", true);
        nextMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

        // Return with success 0.
        return 0;
    }

    // The current menu item is not selected or its index is out of range, return with error -1;
    return -1;
}
