#include <QDebug>
#include "Display.h"

/*
 * Constructor: Display (default)
 * Purpose: initialize a default instance of this class.
 */
Display::Display(QWidget *device) : device(device)
{
    timer = new QTimer(this);
    time  = QTime(0,10,0,0);
    stack = device->findChild<QStackedWidget *>("stackedWidget");
    powerLevel = device->findChild<QProgressBar *>("powerLevel");

    qDebug() << "Constructing display...";
}

/*
 * Function: update
 * Purpose: to determine and call the necessary function of this class associated with the type (macro)
 *          and unpack the packet request to be passed as input values to the respective function call.
 *
 * in: a type (QString) (i.e., UPDATE_SELECT_ITEM, UPDATE_SELECT_MENU), a packet request (struct request)
 * return: not a predefined type (macro) for this function or function error (-1); otherwise, function call successful (0).
 */
int Display::update(QString type, struct request packet)
{
    if (type == UPDATE_SELECT_ITEM)
    {
        return updateSelectMenuItem(packet.index, packet.step, packet.layout);
    }
    else if (type == UPDATE_CHANGE_MODE)
    {
        return updateMode(packet.childName, packet.layout);
    }
    else if (type == UPDATE_CHANGE_MENU)
    {
        return updateMenu(packet.index, packet.layout);
    }
    else if (type == UPDATE_POWER_LEVEL)
    {
        return updatePowerLevel(packet.step);
    }
    else if (type == UPDATE_TIMER)
    {
        return startTimer();
    }
    else if (type == UPDATE_FREQUENCY)
    {
        return updateFrequency(packet.frequency);
    }
    else if (type == UPDATE_BRIGHTNESS_LEVEL)
    {
        return updateBrightnessLevel(packet.step);
    }

    return -1;
}

int Display::updateMode(QString childName, QLayout *layout)
{
        QLabel *child = device->findChild<QLabel *>(childName);
        stack = device->findChild<QStackedWidget*>("stackedWidget");

        // Get the index of the current widget within the stack.
        int widgetIndex = stack->currentIndex();

        // Get the current widget within the stack.
        QWidget *widget = stack->widget(widgetIndex);
        int brightness =5;
        bool childOn = false;
        int childRange =0;

        if (!child) { return -1; }

        if (childName == "enableDisable")
        {
            // The widget is a menu item that enables/disables the other menu items in the current menu.
            // An example of this is the ENABLE/DISABLE menu item in the CHILDREN menu.
            QString text;
            bool property;

            if (child->property("enableDisable").toBool())
            {
                qDebug() << "Child property, property accessed";
                // It is enabled, so disable the other menu items in the list.
                for (int i = 1; i < layout->count(); i++)
                {
                    layout->itemAt(i)->widget()->setHidden(true);
                }

                // Change the text and set it's property to false.
                text = "ENABLE";
                property = false;
            }
            else
            {
                qDebug() << "Child property, property accessed";
                // It is disabled, so enable the other menu items in the list.
                for (int i = 1; i < layout->count(); i++)
                {
                    layout->itemAt(i)->widget()->setHidden(false);
                }

                // Change the text and set it's property to true.
                text = "DISABLE";
                property = true;
            }

            child->setText(text);
            child->setProperty("enableDisable", property);

        }else if(childName== "enableDisable")      //Child CLasses
        {   //Disable current child mode
             childOn= false;
             childRange= 0;
         }else if(childName == "upToOneYear"){  //child setting for <1 year
             childOn= true;
             childRange= 1;
             powerLevel->setMaximum(30);
         }else if(childName== "oneToThreeYears"){   //child setting for 1-3 years
             childOn= true;
             childRange= 3;
             powerLevel->setMaximum(40);
         }else if(childName== "fourToSevenYears"){   //child setting for 4-7 years
             childOn= true;
             childRange= 7;
             powerLevel->setMaximum(50);
         }else if(childName== "sevenToTwelveYears"){  //child setting for 8-12 years year
             childOn= true;
             childRange= 12;
             powerLevel->setMaximum(60);
         }else if(widget->objectName() == "colour"){
            for (int i = 0; i < layout->count(); i++)
            {

                //Match theme selection with appropriate background colours set enableDisable to true
                    //Yellow background
                if(childName=="colYellow"){
                    child->property("enableDisable") = true;
                    backgroundColour="yellow";
                   switch(brightness){
                   case 1 :                                                                //brightness == 1 (from 1 - 9)
                       background->setStyleSheet("background-color: rgb(210,210,0);");
                       break;
                   case 2 :
                       background->setStyleSheet("background-color: rgb(225,225,0);");
                       break;
                   case 3 :
                       background->setStyleSheet("background-color: rgb(235,235,0);");
                       break;
                   case 4 :
                       background->setStyleSheet("background-color: rgb(245,245,0);");
                       break;
                   case 5 :
                       background->setStyleSheet("background-color: rgb(250,255,0);");
                       break;
                   case 6 :
                       background->setStyleSheet("background-color: rgb(250,255,25);");
                       break;
                   case 7 :
                       background->setStyleSheet("background-color: rgb(250,255,50);");
                       break;
                   case 8 :
                       background->setStyleSheet("background-color: rgb(250,255,75);");
                       break;
                   case 9 :                                                                //brightness == 9(from 1 - 9)
                       background->setStyleSheet("background-color: rgb(250,255,100);");
                       break;
                   }


                    //Purple background
                }else if(childName=="colPurple"){
                    child->property("enableDisable") = true;
                    backgroundColour="purple";
                    switch(brightness){
                    case 1 :                                                                //brightness == 1 (from 1 - 9)
                        background->setStyleSheet("background-color: rgb(110,35,255);");
                        break;
                    case 2 :
                        background->setStyleSheet("background-color: rgb(115,40,255);");
                        break;
                    case 3 :
                        background->setStyleSheet("background-color: rgb(120,50,255);");
                        break;
                    case 4 :
                        background->setStyleSheet("background-color: rgb(125,60, 255);");
                        break;
                    case 5 :
                         background->setStyleSheet("background-color: rgb(128,70, 255);");
                        break;
                    case 6 :
                        background->setStyleSheet("background-color: rgb(138,80,255);");
                        break;
                    case 7 :
                        background->setStyleSheet("background-color: rgb(148,90,255);");
                        break;
                    case 8 :
                        background->setStyleSheet("background-color: rgb(158,110,255);");
                        break;
                    case 9 :                                                                //brightness == 9(from 1 - 9)
                        background->setStyleSheet("background-color: rgb(166,121,255);");
                        break;
                    }


                    //green background
                }else if(childName=="colGreen"){
                    child->property("enableDisable") = true;
                    backgroundColour="green";
                    switch(brightness){
                    case 1 :                                                                //brightness == 1 (from 1 - 9)
                        background->setStyleSheet("background-color: rgb(95,170,22);");
                        break;
                    case 2 :
                        background->setStyleSheet("background-color: rgb(100,180,22);");
                        break;
                    case 3 :
                        background->setStyleSheet("background-color: rgb(110,190,22);");
                        break;
                    case 4 :
                        background->setStyleSheet("background-color: rgb(115,200, 22);");
                        break;
                    case 5 :
                         background->setStyleSheet("background-color: rgb(115, 210, 22);");
                        break;
                    case 6 :
                        background->setStyleSheet("background-color: rgb(120,215,22);");
                        break;
                    case 7 :
                        background->setStyleSheet("background-color: rgb(125,225,22);");
                        break;
                    case 8 :
                        background->setStyleSheet("background-color: rgb(130,235,22);");
                        break;
                    case 9 :                                                                //brightness == 9(from 1 - 9)
                        background->setStyleSheet("background-color: rgb(135,245,22);");
                        break;
                    }

                //white background
                }else if(childName=="colWhite"){        //default white background
                    child->property("enableDisable") = true;
                    backgroundColour="white";
                    switch(brightness){
                    case 1 :                                                                //brightness == 1 (from 1 - 9)
                        background->setStyleSheet("background-color: rgb(200,200,200);");
                        break;
                    case 2 :
                        background->setStyleSheet("background-color: rgb(210,210,210);");
                        break;
                    case 3 :
                        background->setStyleSheet("background-color: rgb(220,220,220);");
                        break;
                    case 4 :
                        background->setStyleSheet("background-color: rgb(230,230,230);");
                        break;
                    case 5 :
                         background->setStyleSheet("background-color: rgb(240,240,240);");
                        break;
                    case 6 :
                        background->setStyleSheet("background-color: rgb(243,243,243);");
                        break;
                    case 7 :
                        background->setStyleSheet("background-color: rgb(247,247,247);");
                        break;
                    case 8 :
                        background->setStyleSheet("background-color: rgb(251,251,251);");
                        break;
                    case 9 :                                                                //brightness == 9(from 1 - 9)
                        background->setStyleSheet("background-color: rgb(255,255,255);");
                        break;
                    }
                }else {
                    child->property("enableDisable") = false;
                }
            }
        }else if (childName=="EconOn"){
          //save previous brightness
            econSave = brightness;
            brightness=1;

            if(backgroundColour =="white"){
                background->setStyleSheet("background-color: rgb(200,200,200);");
            }else if(backgroundColour =="yellow"){
                background->setStyleSheet("background-color: rgb(210,210,0);");
            }else if(backgroundColour=="purple"){
                background->setStyleSheet("background-color: rgb(110,35,255);");
            }else if(backgroundColour=="green"){
                 background->setStyleSheet("background-color: rgb(95,170,22);");
            }

        }else if(childName=="Econoff"){
         brightness = econSave;
         econSave = 1;

         if(backgroundColour=="yellow"){
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(210,210,0);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(225,225,0);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(235,235,0);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(245,245,0);");
                break;
            case 5 :
                background->setStyleSheet("background-color: rgb(250,255,0);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(250,255,25);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(250,255,50);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(250,255,75);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(250,255,100);");
                break;
            }

             //Purple background
         }else if(backgroundColour=="purple"){
             switch(brightness){
             case 1 :                                                                //brightness == 1 (from 1 - 9)
                 background->setStyleSheet("background-color: rgb(110,35,255);");
                 break;
             case 2 :
                 background->setStyleSheet("background-color: rgb(115,40,255);");
                 break;
             case 3 :
                 background->setStyleSheet("background-color: rgb(120,50,255);");
                 break;
             case 4 :
                 background->setStyleSheet("background-color: rgb(125,60, 255);");
                 break;
             case 5 :
                  background->setStyleSheet("background-color: rgb(128,70, 255);");
                 break;
             case 6 :
                 background->setStyleSheet("background-color: rgb(138,80,255);");
                 break;
             case 7 :
                 background->setStyleSheet("background-color: rgb(148,90,255);");
                 break;
             case 8 :
                 background->setStyleSheet("background-color: rgb(158,110,255);");
                 break;
             case 9 :                                                                //brightness == 9(from 1 - 9)
                 background->setStyleSheet("background-color: rgb(166,121,255);");
                 break;
             }

             //green background
         }else if(backgroundColour=="green"){
             switch(brightness){
             case 1 :                                                                //brightness == 1 (from 1 - 9)
                 background->setStyleSheet("background-color: rgb(95,170,22);");
                 break;
             case 2 :
                 background->setStyleSheet("background-color: rgb(100,180,22);");
                 break;
             case 3 :
                 background->setStyleSheet("background-color: rgb(110,190,22);");
                 break;
             case 4 :
                 background->setStyleSheet("background-color: rgb(115,200, 22);");
                 break;
             case 5 :
                  background->setStyleSheet("background-color: rgb(115, 210, 22);");
                 break;
             case 6 :
                 background->setStyleSheet("background-color: rgb(120,215,22);");
                 break;
             case 7 :
                 background->setStyleSheet("background-color: rgb(125,225,22);");
                 break;
             case 8 :
                 background->setStyleSheet("background-color: rgb(130,235,22);");
                 break;
             case 9 :                                                                //brightness == 9(from 1 - 9)
                 background->setStyleSheet("background-color: rgb(135,245,22);");
                 break;
             }

         //white background
         }else if(backgroundColour=="white"){        //default white background
             switch(brightness){
             case 1 :                                                                //brightness == 1 (from 1 - 9)
                 background->setStyleSheet("background-color: rgb(200,200,200);");
                 break;
             case 2 :
                 background->setStyleSheet("background-color: rgb(210,210,210);");
                 break;
             case 3 :
                 background->setStyleSheet("background-color: rgb(220,220,220);");
                 break;
             case 4 :
                 background->setStyleSheet("background-color: rgb(230,230,230);");
                 break;
             case 5 :
                  background->setStyleSheet("background-color: rgb(240,240,240);");
                 break;
             case 6 :
                 background->setStyleSheet("background-color: rgb(243,243,243);");
                 break;
             case 7 :
                 background->setStyleSheet("background-color: rgb(247,247,247);");
                 break;
             case 8 :
                 background->setStyleSheet("background-color: rgb(251,251,251);");
                 break;
             case 9 :                                                                //brightness == 9(from 1 - 9)
                 background->setStyleSheet("background-color: rgb(255,255,255);");
                 break;
             }
         }

     }

    return -1;
}

/*
 * Function: updateMenu
 * Purpose: to change to the submenu within the current menu item at the index parameter within the stack
 *
 * in: an index (integer), a layout (QLayout*)
 * return: success (0); otherwise, error (-1).
 */
int Display::updateMenu(int index, QLayout *layout)
{
    QLabel *currMenu = dynamic_cast<QLabel *>(layout->itemAt(index)->widget());
    QWidget *subMenu;

    if (currMenu->text() == "ALLERGIES" || currMenu->text() == "HEAD" || currMenu->text() == "ARMS")
    {
        device->findChild<QWidget *>("upButton")->setEnabled(false);
        device->findChild<QWidget *>("downButton")->setEnabled(false);
        subMenu = stack->findChild<QWidget *>("power");
    }

    else
    {
        subMenu = stack->findChild<QWidget *>(currMenu->text().toLower());
    }

    if (subMenu) {stack->setCurrentWidget(subMenu); return 0;}

    return -1;
}

/*
 * Function: updateSelectMenuItem
 * Purpose: to update the display by selecting the next menu item in the current menu.
 *
 * in: an index (integer), a step value (integer), a layout (QLayout*)
 * return: success (0); otherwise, error (-1).
 */
int Display::updateSelectMenuItem(int index, int step, QLayout *layout)
{
    int nextIndex = index + step;

    QLabel *currMenuItem = dynamic_cast<QLabel *>(layout->itemAt(index)->widget());

    QVariant currSelected = currMenuItem->property("selected");

    // If the menu item does not have a "selected" property that is a boolean, return with error -1.
    if (!currSelected.isValid() && currSelected.type() != QMetaType::Bool) { return -1; }

    if (currSelected == true && nextIndex < layout->count() && nextIndex >= 0)
    {
        if (!layout->itemAt(nextIndex)->widget()->isEnabled()) { nextIndex += step; }
        if (nextIndex > (layout->count() - 1) || nextIndex < 0) { return -1; }

        // We found the currently selected menu item.
        // The next menu item is within range, so get its widget for property and text manipulation.
        QLabel *nextMenuItem = dynamic_cast<QLabel *>(layout->itemAt(nextIndex)->widget());
        QVariant nextSelected = nextMenuItem->property("selected");

        if (!nextMenuItem) { return -1; }

        // If the next menu item to select does not have a "selected" property that is a boolean, return with error -1.
        if (!nextSelected.isValid() && nextSelected.type() != QMetaType::Bool) { return -1; }

        // Set the next menu item as selected and unselect the previous menu item.
        currMenuItem->setProperty("selected", false);
        currMenuItem->setFont(QFont("Sans", 13, QFont::Normal));
        nextMenuItem->setProperty("selected", true);
        nextMenuItem->setFont(QFont("Sans", 15, QFont::Bold));

        // Return with success 0.
        return 0;
    }

    // The current menu item is not selected or its index is out of range, return with error -1;
    return -1;
}

int Display::updatePowerLevel(int step)
{
    if (step == 1)       {powerLevel->setValue(powerLevel->value() + 1); return 0;}
    else if (step == -1) {powerLevel->setValue(powerLevel->value() - 1); return 0;}
    else {return -1;}
}

int Display::updateBrightnessLevel(int step)
{
    stack = device->findChild<QStackedWidget *>("stackedWidget");

    QProgressBar *brightnessBar = device->findChild<QProgressBar *>("brightnessBar");


    if (step == 1)
    {
        brightnessBar->setValue(brightnessBar->value() + 1);
        brightness +=1;

        //economy settings
        economy=false;//if brightness is turned up, economy mode is turned off
        QLabel *Econ_on = device->findChild<QLabel *>("EconOn");
        QLabel *Econ_off = device->findChild<QLabel *>("EconOff");

        //Change labels to correct for mode change
        Econ_on->property("selected")=false;
        Econ_on->property("enableDisable")=false;
        Econ_off->property("selected")=true;
        Econ_off->property("enableDisable")=true;

        //adjust for colour of background
        if(backgroundColour=="yellow"){
           switch(brightness){
           case 1 :                                                                //brightness == 1 (from 1 - 9)
               background->setStyleSheet("background-color: rgb(210,210,0);");
               break;
           case 2 :
               background->setStyleSheet("background-color: rgb(225,225,0);");
               break;
           case 3 :
               background->setStyleSheet("background-color: rgb(235,235,0);");
               break;
           case 4 :
               background->setStyleSheet("background-color: rgb(245,245,0);");
               break;
           case 5 :
               background->setStyleSheet("background-color: rgb(250,255,0);");
               break;
           case 6 :
               background->setStyleSheet("background-color: rgb(250,255,25);");
               break;
           case 7 :
               background->setStyleSheet("background-color: rgb(250,255,50);");
               break;
           case 8 :
               background->setStyleSheet("background-color: rgb(250,255,75);");
               break;
           case 9 :                                                                //brightness == 9(from 1 - 9)
               background->setStyleSheet("background-color: rgb(250,255,100);");
               break;
           }

            //Purple background
        }else if(backgroundColour=="purple"){
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(110,35,255);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(115,40,255);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(120,50,255);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(125,60, 255);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(128,70, 255);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(138,80,255);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(148,90,255);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(158,110,255);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(166,121,255);");
                break;
            }


            //green background
        }else if(backgroundColour=="green"){
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(95,170,22);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(100,180,22);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(110,190,22);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(115,200, 22);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(115, 210, 22);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(120,215,22);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(125,225,22);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(130,235,22);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(135,245,22);");
                break;
            }

        //white background
        }else if(backgroundColour=="white"){        //default white background
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(200,200,200);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(210,210,210);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(220,220,220);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(230,230,230);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(240,240,240);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(243,243,243);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(247,247,247);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(251,251,251);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(255,255,255);");
                break;
            }
        }

        return 0;

    }
    else if (step == -1)
    {
        brightnessBar->setValue(brightnessBar->value() - 1);
        brightness -=1;
        if(backgroundColour=="yellow"){
           switch(brightness){
           case 1 :                                                                //brightness == 1 (from 1 - 9)
               background->setStyleSheet("background-color: rgb(210,210,0);");
               break;
           case 2 :
               background->setStyleSheet("background-color: rgb(225,225,0);");
               break;
           case 3 :
               background->setStyleSheet("background-color: rgb(235,235,0);");
               break;
           case 4 :
               background->setStyleSheet("background-color: rgb(245,245,0);");
               break;
           case 5 :
               background->setStyleSheet("background-color: rgb(250,255,0);");
               break;
           case 6 :
               background->setStyleSheet("background-color: rgb(250,255,25);");
               break;
           case 7 :
               background->setStyleSheet("background-color: rgb(250,255,50);");
               break;
           case 8 :
               background->setStyleSheet("background-color: rgb(250,255,75);");
               break;
           case 9 :                                                                //brightness == 9(from 1 - 9)
               background->setStyleSheet("background-color: rgb(250,255,100);");
               break;
           }


            //Purple background
        }else if(backgroundColour=="purple"){
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(110,35,255);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(115,40,255);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(120,50,255);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(125,60, 255);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(128,70, 255);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(138,80,255);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(148,90,255);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(158,110,255);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(166,121,255);");
                break;
            }


            //green background
        }else if(backgroundColour=="green"){
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(95,170,22);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(100,180,22);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(110,190,22);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(115,200, 22);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(115, 210, 22);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(120,215,22);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(125,225,22);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(130,235,22);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(135,245,22);");
                break;
            }

        //white background
        }else if(backgroundColour=="white"){        //default white background
            switch(brightness){
            case 1 :                                                                //brightness == 1 (from 1 - 9)
                background->setStyleSheet("background-color: rgb(200,200,200);");
                break;
            case 2 :
                background->setStyleSheet("background-color: rgb(210,210,210);");
                break;
            case 3 :
                background->setStyleSheet("background-color: rgb(220,220,220);");
                break;
            case 4 :
                background->setStyleSheet("background-color: rgb(230,230,230);");
                break;
            case 5 :
                 background->setStyleSheet("background-color: rgb(240,240,240);");
                break;
            case 6 :
                background->setStyleSheet("background-color: rgb(243,243,243);");
                break;
            case 7 :
                background->setStyleSheet("background-color: rgb(247,247,247);");
                break;
            case 8 :
                background->setStyleSheet("background-color: rgb(251,251,251);");
                break;
            case 9 :                                                                //brightness == 9(from 1 - 9)
                background->setStyleSheet("background-color: rgb(255,255,255);");
                break;
            }
        }

        qDebug() << "decreasing brightness on display -1"; return 0;}
    else {return -1;}
}

int Display::updateFrequency(QString frequency)
{
    QFrame *screen = device->findChild<QFrame *>("screen");
    QLabel *frequencyLabel = screen->findChild<QLabel *>("frequencyLabel");

    frequencyLabel->setText("Frequency: " + frequency);

    return 0;
}

int Display::startTimer()
{
    QWidget *widget = stack->findChild<QWidget *>("med");

    connect(timer, SIGNAL(timeout()), SLOT(updateTimer()));
    timer->start(1000);
    stack->setCurrentWidget(widget);

    qDebug() << "programsTimer started...";

    return 0;
}

void Display::updateTimer()
{
    QTime local_time = time;
    QString time_text = local_time.toString("mm : ss");
    QLabel *label = stack->findChild<QLabel *>("countdown");

    qDebug() << time.second();

    device->findChild<QWidget *>("leftButton")->setEnabled(false);
    device->findChild<QWidget *>("rightButton")->setEnabled(false);
    device->findChild<QWidget *>("upButton")->setEnabled(false);
    device->findChild<QWidget *>("downButton")->setEnabled(false);
    device->findChild<QWidget *>("okButton")->setEnabled(false);
    device->findChild<QWidget *>("mainMenuButton")->setEnabled(false);

    label->setText(time_text);
    time = time.addSecs(-1);

    if (time.minute() == 0 && time.second() == 0 ) {this->reset();}
}

int Display::reset()
{
    QWidget *widget = stack->findChild<QWidget *>("main");

    timer->stop();
    time = QTime(0,10,0,0);

    device->findChild<QWidget *>("leftButton")->setEnabled(true);
    device->findChild<QWidget *>("rightButton")->setEnabled(true);
    device->findChild<QWidget *>("upButton")->setEnabled(true);
    device->findChild<QWidget *>("downButton")->setEnabled(true);
    device->findChild<QWidget *>("okButton")->setEnabled(true);
    device->findChild<QWidget *>("mainMenuButton")->setEnabled(true);

    powerLevel->setValue(0);
    stack->setCurrentWidget(widget);

    qDebug() << "Program Timer Reset...";

    return 0;
}
