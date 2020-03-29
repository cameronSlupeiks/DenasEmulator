#ifndef MACROS_H
#define MACROS_H

#include <QMainWindow>

struct request
{
    int step;
    int index;

    QLayout *layout;
};

#define BUTTON             "BUTTON"
#define BUTTON_OK          "BUTTON_OK"
#define BUTTON_UP          "BUTTON_UP"
#define BUTTON_DOWN        "BUTTON_DOWN"
#define BUTTON_POWER       "BUTTON_POWER"
#define UPDATE_SELECT_ITEM "UPDATE_SELECT_ITEM"
#define UPDATE_CHANGE_MODE "UPDATE_CHANGE_MODE"
#define UPDATE_CHANGE_MENU "UPDATE_CHANGE_MENU"

#endif // MACROS_H
