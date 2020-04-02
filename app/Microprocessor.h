#ifndef MICROPROCESSOR_H
#define MICROPROCESSOR_H

#include "Macros.h"
#include "Button.h"
#include "Display.h"
#include "battery.h"

class Microprocessor
{
    public:
        Microprocessor();
        Microprocessor(QWidget*);
        Microprocessor(const Microprocessor &processor);

        int request(QString);
        int request(QString, struct request);

    protected:

        Button *button;
        Display *display;
        Battery *battery;
};

#endif // MICROPROCESSOR_H
