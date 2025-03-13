#include "controle.h"
#include "./ui_controle.h"
#include <QVBoxLayout>

#include "mainmenu.h"
#include "capture.h"
#include "choixjoueur.h"
#include "combat.h"
#include "commande.h"
#include "genidex.h"
#include "historencontre.h"
#include "map.h"
#include "regle.h"

Controle::Controle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Controle)
    , stackedWidget(new QStackedWidget(this))
{
    ui->setupUi(this);

    // Créez les différentes pages
    stackedWidget->addWidget(new MainMenu(this)); // Index 0
    stackedWidget->addWidget(new ChoixJoueur(this)); // Index 1
    stackedWidget->addWidget(new Map(this)); // Index 2
    stackedWidget->addWidget(new Capture(this)); // Index 3
    stackedWidget->addWidget(new Combat(this)); // Index 4
    stackedWidget->addWidget(new Genidex(this)); // Index 5
    stackedWidget->addWidget(new HistoRencontre(this)); // Index 6
    stackedWidget->addWidget(new Commande(this)); // Index 7
    stackedWidget->addWidget(new Regle(this)); // Index 8
    setCentralWidget(stackedWidget);

    ChoixJoueur* choixJoueurMenu = qobject_cast<ChoixJoueur*>(stackedWidget->widget(1));
    if (choixJoueurMenu) {
        connect(this, &Controle::sendKeyPress, choixJoueurMenu, &ChoixJoueur::handleKeyPress);
    }

    // Connexion entre le signal de ChoixJoueur et la méthode changeMenu
    connect(choixJoueurMenu, &ChoixJoueur::requestMenuChange, this, &Controle::changeMenu);
}

Controle::~Controle()
{
    delete ui;
}

void Controle::keyPressEvent(QKeyEvent *event) {

    if (stackedWidget->currentIndex() == 0) // Menu Main
    {
        switch (event->key()) {
        case Qt::Key_1:
            changeMenu(1); // Aller à ChoixJoueur
            break;
        case Qt::Key_2:
            changeMenu(7); // Aller à Commande
            break;
        case Qt::Key_3:
            changeMenu(8); // Aller à Regle
            break;
        case Qt::Key_4:
            QApplication::quit(); // Quitter
            break;
        default:
            QMainWindow::keyPressEvent(event);
        }
    }else if (stackedWidget->currentIndex() == 1) // Menu ChoixJoueur
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_Escape) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        } else {
            QMainWindow::keyPressEvent(event); // Comportement par défaut
        }

    }else if (stackedWidget->currentIndex() == 2) // Menu Map
    {

    }else if (stackedWidget->currentIndex() == 3) // Menu Capture
    {

    }else if (stackedWidget->currentIndex() == 4) // Menu Combat
    {

    }else if (stackedWidget->currentIndex() == 5) // Menu Genidex
    {

    }else if (stackedWidget->currentIndex() == 6) // Menu HistoRencontre
    {

    }else if (stackedWidget->currentIndex() == 7) // Menu Commande
    {

    }else if (stackedWidget->currentIndex() == 8) // Menu Regle
    {

    }

}

void Controle::changeMenu(int index) {
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);
    }
}
