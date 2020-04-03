#ifndef MACROS_H
#define MACROS_H

#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QProgressBar>
#include <QStackedWidget>

struct request
{
    int step;
    int index;


    QLayout *layout;
    QString childName;
};

extern bool childOn;
extern int childRange;

#define BUTTON             "BUTTON"
#define BUTTON_OK          "BUTTON_OK"
#define BUTTON_UP          "BUTTON_UP"
#define BUTTON_DOWN        "BUTTON_DOWN"
#define BUTTON_LEFT        "BUTTON_LEFT"
#define BUTTON_RIGHT       "BUTTON_RIGHT"
#define BUTTON_POWER       "BUTTON_POWER"
#define UPDATE_SELECT_ITEM "UPDATE_SELECT_ITEM"
#define UPDATE_CHANGE_MODE "UPDATE_CHANGE_MODE"
#define UPDATE_CHANGE_MENU "UPDATE_CHANGE_MENU"
#define UPDATE_POWER_LEVEL "UPDATE_POWER_LEVEL"
#define UPDATE_BRIGHTNESS_LEVEL "UPDATE_BRIGHTNESS_LEVEL"

#endif // MACROS_H
