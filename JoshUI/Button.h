#ifndef BUTTON_H
#define BUTTON_H

#include "ui_denasui.h"
#include "Microprocessor.h"

class Button
{
    public:
        Button(QWidget*);

        int press(QString);

    protected:
        bool *on;
        QWidget *device;
        QLayout *layout;
        QStackedWidget *stack;
        class Microprocessor *processor;
};

#endif // BUTTON_H
