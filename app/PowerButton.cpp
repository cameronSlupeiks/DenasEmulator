#include <QDebug>
#include "PowerButton.h"
#include <QTimer>

/*
 * Constructor: PowerButton (copy)
 * Purpose: initialize a copy of the parent class, Button.
 *
 * in: a Button reference (const Button)
 */
PowerButton::PowerButton(const Button &button) : Button(button)
{
    qDebug() << "Constructing PowerButton copy of Button...";
}

/*
 * Function: toggle
 * Purpose: to turn on or off the device display.
 *
 * return: success of toggling display power (0).
 */
int PowerButton::toggle(struct request packet)
{
    QFrame *screen = device->findChild<QFrame*>("screen");
    //1 is off
    //0 is on
    QProgressBar *theBar = device->findChild<QProgressBar*>("progressBar");
    QCheckBox* Box = device->findChild<QCheckBox*>("checkBox");
    if(theBar->value()>0)
    {
        if(*on == 0)
        {
            packet.time->start(1000);
        }
        else
        {
            packet.time->stop();
        }
    }
    else
    {
        Box->setCheckState(Qt::CheckState(0));
        screen->setHidden(true);
        theBar->setValue(100);

    }
    screen->setHidden(*on);
    *on = !(*on);

    return 0;
}
