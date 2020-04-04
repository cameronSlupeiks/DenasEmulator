#include "Battery.h"
#include "DenasUI.h"
#include "ui_DenasUI.h"
#include <QtMath>
#include <iostream>

Battery::Battery(QWidget *device) : device(device) {}

int Battery::drain(struct request packet)
{
    if(packet.func == "drain")
    {
        battery_drain(packet);
    }
    else if(packet.func == "dead")
    {
        dead();
    }
    else if(packet.func == "warning")
    {
        warning();
    }
    return 0;
}

int Battery::dead()
{
    QFrame *screen = device->findChild<QFrame*>("screen");
    screen->setVisible(false);
    return 0;
}

int Battery::warning()
{
    message = device->findChild<QLabel*>("batWarning");
    message->setVisible(true);
    return 0;
}


int Battery::battery_drain(struct request packet)
{
    int unitTotal = 1;

    brightness = device->findChild<QProgressBar*>("brightnessBar");
    if (1 < brightness->value() && brightness->value() <= 33)
    {
        unitTotal = unitTotal + 1;
    }
    else if (33 < brightness->value() && brightness->value() <= 66)
    {
        unitTotal = unitTotal + 2;
    }
    else if (66 < brightness->value() && brightness->value() <= 100)
    {
        unitTotal = unitTotal + 3;
    }

    powerBar = device->findChild<QProgressBar*>("powerLevel");

    if (packet.useCase == "contact")
    {
        if (1 < powerBar->value() && powerBar->value() <= 10)
        {
            unitTotal = unitTotal + 1;
        }
        else if (10 < powerBar->value() && powerBar->value() <= 20)
        {
            unitTotal = unitTotal + 2;
        }
        else if (20 < powerBar->value() && powerBar->value() <= 30)
        {
            unitTotal = unitTotal + 3;
        }
        else if (30 < powerBar->value() && powerBar->value() <= 40)
        {
            unitTotal = unitTotal + 4;
        }
        else if (40 < powerBar->value() && powerBar->value() <= 50)
        {
            unitTotal = unitTotal + 5;
        }
        else if (50 < powerBar->value() && powerBar->value() <= 60)
        {
            unitTotal = unitTotal + 6;
        }
        else if (60 < powerBar->value() && powerBar->value() <= 70)
        {
            unitTotal = unitTotal + 7;
        }
        else if (70 < powerBar->value() && powerBar->value() <= 80)
        {
            unitTotal = unitTotal + 8;
        }
        else if (80 < powerBar->value() && powerBar->value() <= 90)
        {
            unitTotal = unitTotal + 9;
        }
        else if (90 < powerBar->value() && powerBar->value() <= 100)
        {
            unitTotal = unitTotal + 10;
        }

    }

    bar = device->findChild<QProgressBar*>("progressBar");
    int tempBattery = bar->value() - unitTotal;
    bar->setValue(tempBattery);

    return 0;
}
