#ifndef OKBUTTON_H
#define OKBUTTON_H

#include "Macros.h"
#include "Button.h"
#include "Microprocessor.h"

class OkButton : public Button
{
    friend class Button;

    public:
        OkButton(const Button &button);

    private:
        request packet;

        int confirm();

        Microprocessor *processor;
};

#endif // OKBUTTON_H
