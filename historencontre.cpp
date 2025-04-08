#include "historencontre.h"
#include "ui_historencontre.h"

HistoRencontre::HistoRencontre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoRencontre)
{
    ui->setupUi(this);
}

HistoRencontre::~HistoRencontre()
{
    delete ui;
}

void HistoRencontre::handleKeyPress(int key) {

    if (key == Qt::Key_1) {
        BOUTONS = 1;
    }else if (key == Qt::Key_2) {
        BOUTONS = 2;
    }else if (key == Qt::Key_3) {
        BOUTONS = 3;
    }else if (key == Qt::Key_4) {
        BOUTONS = 4;
    }

    if (key == Qt::Key_W){
        JOYSTICKS = 1;
    }else if (key == Qt::Key_D){
        JOYSTICKS = 2;
    }else if (key == Qt::Key_S){
        JOYSTICKS = 3;
    }else if (key == Qt::Key_A){
        JOYSTICKS = 4;
    }else{
        JOYSTICKS = 0;
    }

    update();
}

void HistoRencontre::handleArduinoInput(int boutons, int joystick, int accelerometre, int muons){

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

    update();
}

void HistoRencontre::update(){
    if (BOUTONS == 4) {
        BOUTONS = 0;
        JOYSTICKS = 0;
        ACCEL = 0;
        MUONS = 0;
        emit requestMenuChange(2); //Passer au menu map
    }
}
