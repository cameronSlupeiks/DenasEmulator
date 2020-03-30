#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include "Macros.h"
#include "Button.h"
#include "Microprocessor.h"

class ControlButton : public Button
{
    friend class Button;

    private:
        ControlButton(const Button &button);

        int increment_decrement(int);

        request packet;

        Microprocessor *processor;
};

#endif // CONTROLBUTTON_H
