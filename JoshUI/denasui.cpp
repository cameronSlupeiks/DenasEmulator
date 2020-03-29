#include "denasui.h"
#include "ui_denasui.h"
#include <QDebug>
#include <QMediaPlayer>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);

    //connect(player, &QMediaPlayer::positionChanged, this, &DenasUI::on_positionChanged);
   // connect(player, &QMediaPlayer::durationChanged, this, &DenasUI::on_positionChanged);
}

DenasUI::~DenasUI()
{
    delete ui;
}
/*
string backColour(string uiColour){
     if (uiColour.compare("colWhite")){

     }
}
*/
void DenasUI::on_upButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget) { return; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return; }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = layout->count() - 1; i >= 0; i--)
    {
        int prevIndex = i - 1;
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true && prevIndex >= 0)
        {
            // We found the currently selected menu item and it's not the last menu item in the list.
            QLabel *prevMenuItem = dynamic_cast<QLabel *>(layout->itemAt(prevIndex)->widget());
            QVariant nextSelected = prevMenuItem->property("selected");

            if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

            // Set the next menu item as selected.
            currMenuItem->setProperty("selected", false);
            currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
            prevMenuItem->setProperty("selected", true);
            prevMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

            break;
        }
    }
}

void DenasUI::on_downButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget) { return; }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty()) { return; }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = 0; i < layout->count(); i++)
    {
        int nextIndex = i + 1;
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true && nextIndex < layout->count())
        {
            // We found the currently selected menu item and it's not the last menu item in the list.
            QLabel *nextMenuItem = dynamic_cast<QLabel *>(layout->itemAt(nextIndex)->widget());
            QVariant nextSelected = nextMenuItem->property("selected");

            if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return; }

            // Set the next menu item as selected.
            currMenuItem->setProperty("selected", false);
            currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
            nextMenuItem->setProperty("selected", true);
            nextMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

            break;
        }
    }
}


void DenasUI::on_mainMenuButton_clicked()
{
     // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    ui->stackedWidget->setCurrentIndex(0);

}

void DenasUI::on_backButton_clicked()
{

    //audio safeguard
     player->stop();
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    //Depending on which page is open, it will go back to the approproate page before it
    switch(currStack){
     case 1 ://Program -main menu page
        ui->stackedWidget->setCurrentIndex(0);
        break;
    case 2 ://Frequency- main manu
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 3 ://med- main menu
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 4 ://screening- menu
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 5 ://child- main menu
       ui->stackedWidget->setCurrentIndex(0);
       break;
    case 6 ://settings - main manu
       ui->stackedWidget->setCurrentIndex(0);
        break;
    case 8 : //brightness - settings
       ui->stackedWidget->setCurrentIndex(6);
        break;
    case 9 ://sound - settings
       ui->stackedWidget->setCurrentIndex(6);
        break;
    case 10 ://colour-settings
       ui->stackedWidget->setCurrentIndex(6);
        break;

    }

}



//void DenasUI::on_brightnessSlider_valueChanged(int value) //-100 to 100
//{
 //    brightness = value/100;

     
//}

void DenasUI::on_volumeSlider_sliderMoved(int position)
{
    player->setVolume(position);
}




void DenasUI::on_okButton_clicked()
{
    // Get the current stack index (i.e., main menu, programs, frequency, etc.)
    int currStack = ui->stackedWidget->currentIndex();

    // Get the current stack.
    QWidget *widget = ui->stackedWidget->widget(currStack);

    if (!widget)
    {
        return;
    }

    QList <QLayout *> layouts = widget->findChildren<QLayout *>();

    if (layouts.isEmpty())
    {
        return;
    }

    // Each QWidget within the stack has only one layout with other objects as menu items.
    // Get the layout of the current QWidget.
    QLayout *layout = layouts.at(0);

    for (int i = 0; i < layout->count(); i++)
    {
        QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(i)->widget());

        QVariant currSelected = currMenuItem->property("selected");

        if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return; }

        if (currSelected == true)
        {
            QVariant currEnableDisable = currMenuItem->property("enableDisable");

            if (currEnableDisable.isValid() && currEnableDisable.type() == QMetaType::Bool)
            {

                //change background colour
                QLayout *layout = layouts.at(0);
                //extract backgroung rgb values from custom background property
               // QString uiBackground = currMenuItem->property("background").String;

                for (int i = 0; i < layout->count(); i++)
                {
                    if (currSelected ==true ){
                         //enable colour = true
                        currMenuItem->property("enableDiable")=true;

                        //Match theme selection with appropriate background colours
                        if(currMenuItem->objectName()=="colYellow"){  //green background
                            ui->screen->setStyleSheet("background-color: rgb(250,255,0);");
                            ui->stackedWidget->setStyleSheet("background-color: rgb(250,255,0);");


                        }else if(currMenuItem->objectName()=="colPurple"){  //green background
                            ui->screen->setStyleSheet("background-color: rgb(128, 70, 255);");
                            ui->stackedWidget->setStyleSheet("background-color: rgb(128, 70, 255);");

                        }else if(currMenuItem->objectName()=="colGreen"){//green background
                            ui->screen->setStyleSheet("background-color: rgb(115, 210, 22);");
                            ui->stackedWidget->setStyleSheet("background-color: rgba(115, 210, 22,100);");
                           // ui->colGreen->setStyleSheet("background-color: rgba(115, 210, 22);");
                            ui->colour->setStyleSheet("background-color: rgba(115, 210, 22);");


                        }else{        //default white background
                            ui->screen->setStyleSheet("background-color: rgb(255,255,255);");
                            ui->stackedWidget->setStyleSheet("background-color: rgb(255,255,255);");
                        }

                    }else{
                        //all other colours enable = false
                        currMenuItem->property("enableDiable")=false;
                    }
                }

                /*
                 * Add functionality (i.e., what do the child modes do).
                 */
            }
            else
            {
                // Get the QWidget with the object name that is the same as the menu item selected.
                QWidget *stack = ui->stackedWidget->findChild<QWidget *>(currMenuItem->text().toLower());

                // If there is a QWidget that exists with the same menu item name, make it the current widget.
                if (stack)
                {
                    ui->stackedWidget->setCurrentWidget(stack);

                    //When switched menus, play this
                    player->setMedia(QUrl::fromLocalFile("/home/student/A3Proj/DenasEmulator/JoshUI/Sounds/DeezNutsSoundEffect.mp3"));
                    player->play();

                    break;
                }
            }
        }
    }
}

void DenasUI::on_powerButton_clicked()
{
    for (int i = 0; i < ui->navButtons->count(); i++)
    {
        QPushButton *powerButton = dynamic_cast<QPushButton *>(ui->navButtons->itemAt(i)->widget());

        QVariant isOn = powerButton->property("on");

        if (isOn.isValid())
        {
            if (isOn == true)
            {
                ui->screen->setHidden(true);
                powerButton->setProperty("on", false);
            }
            else
            {
                ui->screen->setHidden(false);
                powerButton->setProperty("on", true);
            }
        }
    }
}

