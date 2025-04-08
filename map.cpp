#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Map)
{
    ui->setupUi(this);
    ui->NomPerso->setText(QString("%1").arg(nomJoueur));
}

Map::~Map()
{
    delete ui;
}

void Map::handleKeyPress(int key) {

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

void Map::handleArduinoInput(int boutons, int joystick, int accelerometre, int muons){

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

void Map::update(){

    if (!isPaused) {
        if (BOUTONS == 1) {
            showGenidex();
        } else if (BOUTONS == 2) {
            showHistoRencontre();
        } else if (BOUTONS == 3) {
            isPaused = 1;
        }
    }else {
        if (BOUTONS == 1) {
            quitGame();
        } else if (BOUTONS == 2) {
            //reset game a ajouter
        } else if (BOUTONS == 4) {
            isPaused = 0;
        }
    }
}



void Map::showExtFaculte()
{
    ui->BackGround->setPixmap(QPixmap(":/Decor/Image_Qt/Decor/5a8.png"));
    ui->NomPerso->setVisible(true);
}

void Map::showIntFaculte()
{
    ui->BackGround->setPixmap(QPixmap(":/Decor/Image_Qt/Decor/5a8.png"));   //Mettre bonne image
}

void Map::showCombat()
{
    BOUTONS = 0;
    JOYSTICKS = 0;
    ACCEL = 0;
    MUONS = 0;
    emit requestMenuChange(4); //Passer au menu combat
}

void Map::showGenidex()
{
    BOUTONS = 0;
    JOYSTICKS = 0;
    ACCEL = 0;
    MUONS = 0;
    emit requestMenuChange(5); //Passer au menu genidex
}

void Map::showHistoRencontre()
{
    BOUTONS = 0;
    JOYSTICKS = 0;
    ACCEL = 0;
    MUONS = 0;
    emit requestMenuChange(6); //Passer au menu histoRencontre
}

void Map::quitGame()
{
    BOUTONS = 0;
    JOYSTICKS = 0;
    ACCEL = 0;
    MUONS = 0;
    emit requestMenuChange(0); //Passer au main menu
}

void Map::setNomJoueur(const QString &nom)
{
    nomJoueur = nom;
    ui->NomPerso->setText(QString("%1").arg(nomJoueur));
}
