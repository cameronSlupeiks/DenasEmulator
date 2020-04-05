#ifndef DISPLAY_H
#define DISPLAY_H

#include <QTime>
#include <QTimer>
#include "Macros.h"

class Display : public QObject
{    
    Q_OBJECT

    public:
        Display(QWidget*);

        QString backgroundColour = "white";
        bool economy = false;
        int brightness = 5;
        int econSave = 0;

        int update(QString, struct request);
        int reset();

    public slots:
        void updateTimer();

    private:
        QWidget *device;
        QStackedWidget *stack;
        QProgressBar *powerLevel;
        QTimer *timer;
        QTime time;
        QFrame *background = device->findChild<QFrame *>("screen");

        int updateMode(QString, QLayout*);
        int updateMenu(int, QLayout*);
        int updateSelectMenuItem(int, int, QLayout*);
        int updatePowerLevel(int);
        int updateBrightnessLevel(int);
        int updateFrequency(QString);
        int startTimer();
};

#endif // DISPLAY_H
