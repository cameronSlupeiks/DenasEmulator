#ifndef MACROS_H
#define MACROS_H

#include <QMainWindow>

struct request
{
    int step;
    int index;
    QLayout *layout;
};

#define BUTTON_UP          "BUTTON_UP"
#define BUTTON_DOWN        "BUTTON_DOWN"
#define BUTTON_POWER       "BUTTON_POWER"
#define BATTERY_DRAIN      "BATTERY_DRAIN"
#define UPDATE_SELECT_ITEM "UPDATE_SELECT_ITEM"

#endif // MACROS_H
