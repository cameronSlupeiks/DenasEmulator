#ifndef MICROPROCESSOR_H
#define MICROPROCESSOR_H

#include "Macros.h"
#include "Button.h"
#include "Display.h"
#include "battery.h"
#include "ui_denasui.h"

class Microprocessor
{
    public:
        Microprocessor();
        Microprocessor(QWidget*);
        Microprocessor(const Microprocessor &processor);

        int request(QString);
        int request(QString, struct request);

    protected:
        QWidget *device;
        class Button *button;
        Display *display;
        class Battery *battery;
};

#endif // MICROPROCESSOR_H
