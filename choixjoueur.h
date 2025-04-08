#ifndef CHOIXJOUEUR_H
#define CHOIXJOUEUR_H

#include <QWidget>

namespace Ui {
class ChoixJoueur;
}

class ChoixJoueur : public QWidget
{
    Q_OBJECT

public:
    explicit ChoixJoueur(QWidget *parent = nullptr);
    ~ChoixJoueur();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);

private:
    Ui::ChoixJoueur *ui;
    void updateQuiz();

    int etat;
    char typeChoisi;
    QString nomJoueur;

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
    void sendNomJoueur(const QString &nom); // Signal pour envoyer le nom choisi du joueur a map
};

#endif // CHOIXJOUEUR_H
