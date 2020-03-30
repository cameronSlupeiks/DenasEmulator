#ifndef DENASUI_H
#define DENASUI_H

#include <QMainWindow>
#include "Microprocessor.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class DenasUI; }
QT_END_NAMESPACE

class DenasUI : public QMainWindow
{
    Q_OBJECT

    public:
        DenasUI(QWidget *parent = nullptr);
        ~DenasUI();
    public slots:
        void timer_exec();
    private slots:
        void on_upButton_clicked();
        void on_okButton_clicked();
        void on_downButton_clicked();
        void on_backButton_clicked();
        void on_powerButton_clicked();
        void on_mainMenuButton_clicked();
        void on_volumeSlider_sliderMoved(int position);

    private:
        Ui::DenasUI *ui;
        Microprocessor *microProcessor;
        QTimer *timer;

};
#endif // DENASUI_H
