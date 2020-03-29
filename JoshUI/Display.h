#ifndef DISPLAY_H
#define DISPLAY_H

#include "Macros.h"
#include "ui_denasui.h"

class Display
{
    public:
        Display();

        int update(QString, struct request);

    private:
        int updateSelectMenuItem(int, int, QLayout*);
};

#endif // DISPLAY_H
