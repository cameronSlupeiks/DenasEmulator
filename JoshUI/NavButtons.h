#ifndef NAVBUTTONS_H
#define NAVBUTTONS_H

#include "Macros.h"
#include "Button.h"
#include "denasui.h"
#include "Microprocessor.h"

class NavButton : public Button
{
    friend class Button;

    private:
        NavButton(const Button &button);

        int navigate(int);

        request packet;
        QLayout *layout;

        Microprocessor *processor;
};

#endif // NAVBUTTONS_H
