#ifndef DISPLAY_H
#define DISPLAY_H

#include "Macros.h"

class Display
{    
    public:
        Display(QWidget*);

        int update(QString, struct request);


    private:
        QWidget *device;
        QStackedWidget *stack;

        int updateMode(QString, QLayout*);
        int updateMenu(int, QLayout*);
        int updateSelectMenuItem(int, int, QLayout*);
        int updatePowerLevel(int);
};

#endif // DISPLAY_H
