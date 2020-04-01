#ifndef MICROPROCESSOR_H
#define MICROPROCESSOR_H

#include "Macros.h"
#include "Button.h"
#include "Display.h"

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
};

#endif // MICROPROCESSOR_H
