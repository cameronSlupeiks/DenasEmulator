#ifndef BATTERY_H
#define BATTERY_H

#include "ui_denasui.h"
#include "Microprocessor.h"

class Battery
{
public:
    Battery(QWidget*);
public slots:
    int battery_darin();
    int battery_darin_because(QString useCase,int unit);

private:
    QWidget *device;
    QProgressBar *bar;
};

#endif // BATTERY_H
