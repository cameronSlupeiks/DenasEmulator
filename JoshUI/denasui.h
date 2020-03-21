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

private:
    Ui::DenasUI *ui;
};
#endif // DENASUI_H
