#ifndef BATTERY_H
#define BATTERY_H

#include "ui_denasui.h"
#include "Microprocessor.h"

class Battery
{
public:
    Battery(QWidget*);
public slots:
    int battery_darin(QString,int);
private:
    QWidget *device;
    QProgressBar *bar;

};

#endif // BATTERY_H
