#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QStackedWidget>

class Button
{
    public:
        Button(class Microprocessor*, QWidget*);

        int press(QString);
        int press(QString, struct request);

        QWidget *device;

    protected:
        bool *on;

        QLayout *layout;
        QStackedWidget *stack;

        class Microprocessor *processor;
};

#endif // BUTTON_H
