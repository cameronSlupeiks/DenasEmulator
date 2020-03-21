#ifndef DENASUI_H
#define DENASUI_H

#include <QMainWindow>

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
    void on_programsButton_clicked();

    void on_frequencyButton_clicked();

    void on_childButton_clicked();

    void on_screeningButton_clicked();

    void on_settingsButton_clicked();

    void on_medButton_clicked();

private:
    Ui::DenasUI *ui;
};
#endif // DENASUI_H
