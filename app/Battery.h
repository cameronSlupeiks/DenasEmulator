#ifndef BATTERY_H
#define BATTERY_H

#include "ui_DenasUI.h"
#include <QLabel>

class Battery
{

    public:
        Battery(QWidget*);

    public slots:
        int drain(struct request);

    private:
        int battery_drain(struct request);
        int warning();
        int dead();
        QWidget *device;
        QProgressBar *bar;
        QProgressBar *powerBar;
        QLabel *message;
        QProgressBar *brightness;
        class Microprocessor *processor;
};

#endif // BATTERY_H
