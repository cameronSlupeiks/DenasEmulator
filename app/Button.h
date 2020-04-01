#ifndef BUTTON_H
#define BUTTON_H

#include "ui_denasui.h"
// #include "Microprocessor.h"

class Button
{
    public:
        Button(class Microprocessor*, QWidget*);

        int press(QString);
        int press(QString,struct request packet);

        QWidget *device;

    protected:
        bool *on;

        QLayout *layout;
        QStackedWidget *stack;

        class Microprocessor *processor;
};

#endif // BUTTON_H
