#include "choixjoueur.h"
#include "ui_choixjoueur.h"
#include "controle.h"
#include <QKeyEvent>
#include <QDebug>

extern Controle *controle;

ChoixJoueur::ChoixJoueur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoixJoueur)
    , etat(0)
    , typeChoisi('0')
{
    ui->setupUi(this);

    ui->Continuer->setStyleSheet("background-color: white; color: black; font-size: 14px;");
    ui->Retour->setStyleSheet("background-color: white; color: black; font-size: 14px;");
    ui->Description->setVisible(false);
    ui->Continuer->setText("Continuer (esc)");
    ui->Retour->setVisible(false);

    updateQuiz();
}

ChoixJoueur::~ChoixJoueur()
{
    delete ui;
}

void ChoixJoueur::handleKeyPress(int key) {

    if (etat != 0) {
        if (key == Qt::Key_1) {
            BOUTONS = 1;
            //qDebug() << "Clavier1 (Oui) détecté";
        } else if (key == Qt::Key_2) {
            BOUTONS = 2;
            //qDebug() << "Clavier2 (Non) détecté";
        }
    }else{
        BOUTONS = 0;
    }

    if (etat == 0 && key == Qt::Key_Escape) {
        nomJoueur = ui->NomChoisi->text();
        ui->NomChoisi->clearFocus();
        //qDebug() << "Nom validé par Escape :" << nomJoueur;

        etat = 1;
    }
    updateQuiz();

}

void ChoixJoueur::handleArduinoInput(int boutons, int joystick, int accelerometre, int muons){

    if (etat != 0) {
        if (boutons == 1) {
            BOUTONS = 1;
            //qDebug() << "Clavier1 (Oui) détecté";
        } else if (boutons == 2) {
            BOUTONS = 2;
            //qDebug() << "Clavier2 (Non) détecté";
        }
    }else{
        BOUTONS = 0;
    }

    if (etat == 0 && boutons == 4) {
        nomJoueur = ui->NomChoisi->text();
        ui->NomChoisi->clearFocus();
        //qDebug() << "Nom validé par Escape :" << nomJoueur;

        etat = 1;
    }

    updateQuiz();
}



void ChoixJoueur::updateQuiz() {

    switch (etat) {
    case 0:
        ui->Titre->setText("Quel est ton nom ?");
        ui->NomChoisi->setFocus();
        break;

    case 1:
        ui->Titre->setText("Question de personnalité");
        ui->Description->setVisible(true);
        ui->Retour->setVisible(true);
        ui->Description->setText("Il faut choisir ton type... Réponds à ces questions pour le connaitre. "
                                 "Tu dois répondre par 1 (oui) ou par 2 (non) à chaque question.");
        ui->Continuer->setText("Oui (1)");
        ui->Retour->setText("Non (2)");

        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que 80% est une mauvaise note ?");
            etat = 2;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            emit requestMenuChange(0); //Passer au main menu
        }
        break;

    case 2: // Question 1 : Est-ce que 80% est une mauvaise note ?
        ui->Description->setText("Est-ce que 80% est une mauvaise note ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que la physique c'est cool ?");
            etat = 3;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que tu penses que les ordinateurs fonctionnent avec de l'essence ?");
            etat = 5;
        }
        break;

    case 3: // Question 2 : Est-ce que la physique c'est cool ?
        ui->Description->setText("Est-ce que la physique c'est cool ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie robotique! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '3'; // Type robotique
            etat = 9;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que des trucs morts c'est cool ?");
            etat = 4;
        }
        break;

    case 4: // Question 3 : Est-ce que des trucs morts c'est cool ?
        ui->Description->setText("Est-ce que des trucs morts c'est cool ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie biotech! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '7'; // Type biotech
            etat = 9;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie chimique! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '8'; // Type chimique
            etat = 9;
        }
        break;

    case 5: // Question 4 : Est-ce que tu penses que les ordinateurs fonctionnent avec de l'essence ?
        ui->Description->setText("Est-ce que tu penses que les ordinateurs fonctionnent avec de l'essence ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Hmmm, intéressant... Tu es un génie mécanique. Félicitations ! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '4'; // Type mécanique
            etat = 9;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que tu sais ce que c'est un Amplis-Op ?");
            etat = 6;
        }
        break;

    case 6: // Question 5 : Est-ce que tu sais ce que c'est un Amplis-Op ?
        ui->Description->setText("Est-ce que tu sais ce que c'est un Amplis-Op ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce qu'il te font peur ?");
            etat = 7;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Est-ce que tu es basique ?");
            etat = 8;
        }
        break;

    case 7: // Question 6 : Est-ce qu'il te font peur ?
        ui->Description->setText("Est-ce qu'il te font peur ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie informatique! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '1'; // Type informatique
            etat = 9;
        } else if (BOUTONS == 2) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie électrique! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '2'; // Type électrique
            etat = 9;
        }
        break;

    case 8: // Question 7 : Est-ce que tu es basique ?
        ui->Description->setText("Est-ce que tu es basique ?");
        if (BOUTONS == 1) {
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie civil! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '5'; // Type civil
            etat = 9;
        } else if (BOUTONS == 2) { // Réponse "Non" (Clavier2)
            BOUTONS = 0;
            ui->Description->setText("Félicitations tu es un génie du bâtiment! Tu as terminé le quiz.");
            ui->Continuer->setText("Débuter de la partie (1)");
            ui->Retour->setText("Recommencer le quiz (2)");
            typeChoisi = '6'; // Type bâtiment
            etat = 9;
        }
        break;

    case 9: // Fin du quiz : Choix du type terminé
        ui->Description->setText("Félicitations ! Tu as terminé le quiz.");
        ui->Continuer->setText("Débuter de la partie (1)");
        ui->Retour->setText("Recommencer le quiz (2)");

        if (BOUTONS == 1)
        {
            BOUTONS = 0;
            emit sendNomJoueur(nomJoueur); //Envoyer le nom du joueur a la classe map
            emit requestMenuChange(2); //Passer au menu map
        }

        if (BOUTONS == 2)
        {
            BOUTONS = 0;
            etat = 1;
            typeChoisi = '0';
        }
        break;

    default:
        break;
    }
}
