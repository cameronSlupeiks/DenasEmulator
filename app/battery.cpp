#include "battery.h"
#include "DenasUI.h"
#include "ui_denasui.h"
#include <QtMath>
#include <iostream>

Battery::Battery(QWidget *device) : device(device) {}

int Battery::battery_darin(QString useCase,int num)
{
    bar = device->findChild<QProgressBar*>("progressBar");


    int unitTotal = 1;

    if(useCase == "boost")
    {
        unitTotal = unitTotal + qFloor((num * 0.1)+1);
    }
    else if (useCase == "powerLevel")
    {

    }
    int tempBattery = bar->value() - unitTotal;
    bar->setValue(tempBattery);

    return 0;
}
