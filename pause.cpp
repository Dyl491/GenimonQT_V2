#include "pause.h"
#include "ui_pause.h"

Pause::Pause(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pause)
{
    ui->setupUi(this);
}

Pause::~Pause()
{
    delete ui;
}

void Pause::handleKeyPress(int key) {
    if (key == Qt::Key_1) {
        QApplication::quit(); // Quitter
    }
    else if (key == Qt::Key_2) {
        emit requestMenuChange(0); //Passer au menu main
        emit reinitialiserJeu();
    }
    else if (key == Qt::Key_4) {
        emit requestMenuChange(2); //Passer au menu map
    }
}

void Pause::handleArduinoInput(int boutons, int joystick, int accelerometre, int muons){

    if(boutons ==1){
        QApplication::quit(); // Quitter
    }else if(boutons ==2){
        emit requestMenuChange(0); //Passer au menu main
        emit reinitialiserJeu();
    }else if(boutons ==4){
        emit requestMenuChange(2); //Passer au menu map
    }
}
