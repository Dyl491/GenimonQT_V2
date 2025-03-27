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

    if (!isPaused) {
        if (key == Qt::Key_1) {
            showGenidex();
        } else if (key == Qt::Key_2) {
            showHistoRencontre();
        } else if (key == Qt::Key_3) {
            isPaused = 1;
        }
    }else {
        if (key == Qt::Key_1) {
            quitGame();
        } else if (key == Qt::Key_2) {
            //reset game a ajouter
        } else if (key == Qt::Key_4) {
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
    emit requestMenuChange(4); //Passer au menu combat
}

void Map::showGenidex()
{
    emit requestMenuChange(5); //Passer au menu genidex
}

void Map::showHistoRencontre()
{
    emit requestMenuChange(6); //Passer au menu histoRencontre
}

void Map::quitGame()
{
    emit requestMenuChange(0); //Passer au main menu
}

void Map::setNomJoueur(const QString &nom)
{
    nomJoueur = nom;
    ui->NomPerso->setText(QString("%1").arg(nomJoueur));
}
