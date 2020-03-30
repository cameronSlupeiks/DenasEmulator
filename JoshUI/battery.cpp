#include "battery.h"
#include "denasui.h"
#include "ui_denasui.h"
#include <QtMath>
#include <iostream>

Battery::Battery(QWidget *device) : device(device) {}

int Battery::battery_darin()
{
    bar = device->findChild<QProgressBar*>("progressBar");
    int tempBattery = bar->value() - 1;
    bar->setValue(tempBattery);
    return 0;
}

int Battery::battery_darin_because(QString useCase,int unit)
{
    bar = device->findChild<QProgressBar*>("progressBar");
    if(useCase == "frequency")
    {
        int tempBattery = bar->value() -  qFloor((unit * 0.1)+1);
        bar->setValue(tempBattery);
    }
    else if(useCase == "brightness")
    {

    }
    else if(useCase == "volume")
    {

    }
    else if(useCase == "theme")
    {

    }
    return 0;
}
