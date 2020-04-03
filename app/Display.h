#ifndef DISPLAY_H
#define DISPLAY_H

#include "Macros.h"

class Display
{    
    public:
        Display(QWidget*);
        int brightness = 5;
        bool economy=false;
        int econSave=0;
        QString backgroundColour = "white";
        int update(QString, struct request);


    private:
        QWidget *device;
        QStackedWidget *stack;
        QFrame *background = device->findChild<QFrame *>("screen");

        int updateMode(QString, QLayout*);
        int updateMenu(int, QLayout*);
        int updateSelectMenuItem(int, int, QLayout*);
        int updatePowerLevel(int);
        int updateBrightnessLevel(int);
};

#endif // DISPLAY_H
