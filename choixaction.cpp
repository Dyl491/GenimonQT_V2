#include "choixaction.h"
#include "ui_choixaction.h"

ChoixAction::ChoixAction(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoixAction)
{
    ui->setupUi(this);
}

ChoixAction::~ChoixAction()
{
    delete ui;
}



void ChoixAction::handleKeyPress(int key) {
    if (key == Qt::Key_1) {
        emit requestMenuChange(4); //Passer au menu combat
        clearFocus();
    }

    if (key == Qt::Key_2) {
        emit requestMenuChange(3); //Passer au menu capture
        clearFocus();
    }

    if (key == Qt::Key_3) {
        emit requestMenuChange(2); //Passer au menu map
        clearFocus();
    }
}

void ChoixAction::handleArduinoInput(int boutons, int joystick, int accelerometre, int muons){

    if(boutons ==1){
        BOUTONS = 1;
    }else if(boutons ==2){
        BOUTONS = 2;
    }else if(boutons ==3){
        BOUTONS = 3;
    }else if(boutons ==4){
        BOUTONS = 4;
    }

    if(joystick ==1){
        JOYSTICKS = 1;
    }else if(joystick ==2){
        JOYSTICKS = 2;
    }else if(joystick ==3){
        JOYSTICKS = 3;
    }else if(joystick ==4){
        JOYSTICKS = 4;
    }

    ACCEL = accelerometre;
    MUONS = muons;
}
