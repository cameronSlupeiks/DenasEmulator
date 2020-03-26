#ifndef DENASUI_H
#define DENASUI_H

#include <QMainWindow>
#include <QGraphicsEffect>
#include <QAbstractAudioOutput>
//#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class DenasUI; }
QT_END_NAMESPACE

class DenasUI : public QMainWindow
{
    Q_OBJECT

public:
    DenasUI(QWidget *parent = nullptr);
    double brightness=0;    //brightness selector changed
    int childRange=0;       //child range selected
    bool childOn=false;    //child setting on or off check
    ~DenasUI();

private slots:
    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_mainMenuButton_clicked();

    void on_backButton_clicked();

    void on_okButton_clicked();

    void on_powerButton_clicked();


   // void on_brightnessSlider_valueChanged(int value);

    //Audio
   //  void on_volumeSlider_sliderMoved(int position);
     //called when file is being played through media player and position has changed
  //   void on_positionChanged(qint64 position);
     //used when we load file, give full length of file itself
   //  void on_durationChanged(qint64 position);



private:
    Ui::DenasUI *ui;
  //  QMediaPlayer *player;
};
#endif // DENASUI_H
