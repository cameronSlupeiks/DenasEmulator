#ifndef POWERBUTTON_H
#define POWERBUTTON_H

#include "Macros.h"
#include "Button.h"

class PowerButton : public Button
{
    friend class Button;

    private:
        PowerButton(const Button &button);

        int toggle(struct request packet);
};

#endif // POWERBUTTON_H
