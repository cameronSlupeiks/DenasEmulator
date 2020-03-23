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
    void on_upButton_clicked();

    void on_downButton_clicked();

private:
    Ui::DenasUI *ui;
};
#endif // DENASUI_H
