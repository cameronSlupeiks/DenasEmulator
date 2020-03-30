#include "denasui.h"
#include "ui_denasui.h"
#include <QDebug>
#include <QMediaPlayer>

DenasUI::DenasUI(QWidget *parent) : QMainWindow(parent), ui(new Ui::DenasUI)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
}

DenasUI::~DenasUI()
{
    delete ui;
}

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



void DenasUI::on_brightnessSlider_valueChanged(int value) //-100 to 100
{
     brightness = value;

     
}

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

                //CHANGE BACKGROUND COLOUR
                QLayout *layout = layouts.at(0);

                for (int i = 0; i < layout->count(); i++)
                {
                    if (currSelected ==true ){
                         //enable colour = true
                        currMenuItem->property("enableDiable")=true;

                        //Match theme selection with appropriate background colours
                            //Yellow background
                        if(currMenuItem->objectName()=="colYellow"){
                           switch(brightness){
                           case 1 :
                               ui->screen->setStyleSheet("background-color: rgb(210,210,0);");
                               break;
                           case 2 :
                               ui->screen->setStyleSheet("background-color: rgb(225,225,0);");
                               break;
                           case 3 :
                               ui->screen->setStyleSheet("background-color: rgb(235,235,0);");
                               break;
                           case 4 :
                               ui->screen->setStyleSheet("background-color: rgb(245,245,0);");
                               break;
                           case 5 :
                               ui->screen->setStyleSheet("background-color: rgb(250,255,0);");
                               break;
                           case 6 :
                               ui->screen->setStyleSheet("background-color: rgb(250,255,25);");
                               break;
                           case 7 :
                               ui->screen->setStyleSheet("background-color: rgb(250,255,50);");
                               break;
                           case 8 :
                               ui->screen->setStyleSheet("background-color: rgb(250,255,75);");
                               break;
                           case 9 :
                               ui->screen->setStyleSheet("background-color: rgb(250,255,100);");
                               break;
                           }


                            //Purple background
                        }else if(currMenuItem->objectName()=="colPurple"){
                            switch(brightness){
                            case 1 :
                                ui->screen->setStyleSheet("background-color: rgb(110,35,255);");
                                break;
                            case 2 :
                                ui->screen->setStyleSheet("background-color: rgb(115,40,255);");
                                break;
                            case 3 :
                                ui->screen->setStyleSheet("background-color: rgb(120,50,255);");
                                break;
                            case 4 :
                                ui->screen->setStyleSheet("background-color: rgb(125,60, 255);");
                                break;
                            case 5 :
                                 ui->screen->setStyleSheet("background-color: rgb(128,70, 255);");
                                break;
                            case 6 :
                                ui->screen->setStyleSheet("background-color: rgb(138,80,255);");
                                break;
                            case 7 :
                                ui->screen->setStyleSheet("background-color: rgb(148,90,255);");
                                break;
                            case 8 :
                                ui->screen->setStyleSheet("background-color: rgb(158,110,255);");
                                break;
                            case 9 :
                                ui->screen->setStyleSheet("background-color: rgb(166,121,255);");
                                break;
                            }


                            //green background
                        }else if(currMenuItem->objectName()=="colGreen"){
                            switch(brightness){
                            case 1 :                                                                //brightness == 1 (from 1 - 9)
                                ui->screen->setStyleSheet("background-color: rgb(95,170,22);");
                                break;
                            case 2 :
                                ui->screen->setStyleSheet("background-color: rgb(100,180,22);");
                                break;
                            case 3 :
                                ui->screen->setStyleSheet("background-color: rgb(110,190,22);");
                                break;
                            case 4 :
                                ui->screen->setStyleSheet("background-color: rgb(115,200, 22);");
                                break;
                            case 5 :
                                 ui->screen->setStyleSheet("background-color: rgb(115, 210, 22);");
                                break;
                            case 6 :
                                ui->screen->setStyleSheet("background-color: rgb(120,215,22);");
                                break;
                            case 7 :
                                ui->screen->setStyleSheet("background-color: rgb(125,225,22);");
                                break;
                            case 8 :
                                ui->screen->setStyleSheet("background-color: rgb(130,235,22);");
                                break;
                            case 9 :                                                                //brightness == 9(from 1 - 9)
                                ui->screen->setStyleSheet("background-color: rgb(135,245,22);");
                                break;
                            }

                        //white background
                        }else if(currMenuItem->objectName()=="colWhite"){        //default white background
                            switch(brightness){
                            case 1 :                                                                //brightness == 1 (from 1 - 9)
                                ui->screen->setStyleSheet("background-color: rgb(200,200,200);");
                                break;
                            case 2 :
                                ui->screen->setStyleSheet("background-color: rgb(210,210,210);");
                                break;
                            case 3 :
                                ui->screen->setStyleSheet("background-color: rgb(220,220,220);");
                                break;
                            case 4 :
                                ui->screen->setStyleSheet("background-color: rgb(230,230,230);");
                                break;
                            case 5 :
                                 ui->screen->setStyleSheet("background-color: rgb(240,240,240);");
                                break;
                            case 6 :
                                ui->screen->setStyleSheet("background-color: rgb(243,243,243);");
                                break;
                            case 7 :
                                ui->screen->setStyleSheet("background-color: rgb(247,247,247);");
                                break;
                            case 8 :
                                ui->screen->setStyleSheet("background-color: rgb(251,251,251);");
                                break;
                            case 9 :                                                                //brightness == 9(from 1 - 9)
                                ui->screen->setStyleSheet("background-color: rgb(255,255,255);");
                                break;
                            }

                         //Child CLasses
                        }else if(currMenuItem->objectName() == "disable"){   //Disable current child mode
                            childOn= false;
                            childRange= 0;
                        }else if(currMenuItem->objectName() == "upToOneYear"){  //child setting for <1 year
                            childOn= true;
                            childRange= 1;
                        }else if(currMenuItem->objectName() == "oneToThreeYears"){   //child setting for 1-3 years
                            childOn= true;
                            childRange= 3;
                        }else if(currMenuItem->objectName() == "fourToSevenYears"){   //child setting for 4-7 years
                            childOn= true;
                            childRange= 7;
                        }else if(currMenuItem->objectName() == "sevenToTwelveYears"){  //child setting for 8-12 years year
                            childOn= true;
                            childRange= 12;
                        }

                    }else{
                        //all other colours enable = false
                        currMenuItem->property("enableDiable")=false;
                    }
                }





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

