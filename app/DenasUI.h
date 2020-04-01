#ifndef DENASUI_H
#define DENASUI_H

#include <cstdlib>
#include <QMainWindow>
#include "Microprocessor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DenasUI; }
QT_END_NAMESPACE

class DenasUI : public QMainWindow
{
    Q_OBJECT

    public:
        DenasUI(QWidget *parent = nullptr);
        ~DenasUI();

    private slots:
        void on_okButton_clicked();
        void on_upButton_clicked();
        void on_downButton_clicked();
        void on_backButton_clicked();
        void on_leftButton_clicked();
        void on_rightButton_clicked();
        void on_powerButton_clicked();
        void on_mainMenuButton_clicked();

        void on_externalElectrode_stateChanged(int arg1);

private:
        Ui::DenasUI *ui;
        Microprocessor *microProcessor;
};
#endif // DENASUI_H
