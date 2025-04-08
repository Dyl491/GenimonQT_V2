#include "capture.h"
#include "ui_capture.h"
#include <QEasingCurve>

Capture::Capture(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Capture)
{
    ui->setupUi(this);
    ui->Pokeball->setVisible(false);
}

Capture::~Capture()
{
    delete ui;
}

void Capture::handleKeyPress(int key) {

    if(key == Qt::Key_1){
        animPokeball();
    }else if (key == Qt::Key_2){
        emit requestMenuChange(2); //Passer au menu map
        clearFocus();
    }

}



void Capture::animPokeball(){

    ui->Pokeball->setVisible(true);

    // Animation de la Pokéball
    animation = new QPropertyAnimation(ui->Pokeball, "pos", this);
    animation->setDuration(1000); // Durée de l'animation
    animation->setStartValue(QPoint(200, 440)); // Position de départ
    animation->setEndValue(QPoint(800, 170)); // Position d'arrivée

    // Utiliser un mouvement de courbe parabolique
    animation->setEasingCurve(QEasingCurve::OutQuad); // Courbe d'accélération de type "rebond"

    animation->start();

    // Timer pour faire disparaître la Pokéball après l'animation
    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        ui->Pokeball->setVisible(false);  // Cacher la Pokéball après l'animation
        animation->deleteLater();  // Supprimer l'animation après qu'elle soit terminée
    });
}



void Capture::animCapture(){

    int i =0;
    ui->Pokeball->setVisible(true);
    ui->Pokeball->move(800,170);

    // Obtenir la position actuelle de la Pokéball
    QPoint originalPos = ui->Pokeball->pos();

    // Créer un QPropertyAnimation pour animer la position
    QPropertyAnimation *shakeAnim = new QPropertyAnimation(ui->Pokeball, "pos");
    shakeAnim->setDuration(100);
    shakeAnim->setStartValue(originalPos);
    shakeAnim->setEndValue(originalPos + QPoint(10, 0));  // Déplacer à droite

    // Animation pour aller à gauche
    QPropertyAnimation *shakeAnim2 = new QPropertyAnimation(ui->Pokeball, "pos");
    shakeAnim2->setDuration(100);
    shakeAnim2->setStartValue(originalPos + QPoint(10, 0));
    shakeAnim2->setEndValue(originalPos - QPoint(10, 0));  // Déplacer à gauche

    // Animation pour revenir à la position initiale
    QPropertyAnimation *shakeAnim3 = new QPropertyAnimation(ui->Pokeball, "pos");
    shakeAnim3->setDuration(100);
    shakeAnim3->setStartValue(originalPos - QPoint(10, 0));
    shakeAnim3->setEndValue(originalPos);  // Retourner à la position initiale

    // Appliquer une courbe d'accélération pour les animations
    shakeAnim->setEasingCurve(QEasingCurve::OutQuad);
    shakeAnim2->setEasingCurve(QEasingCurve::OutQuad);
    shakeAnim3->setEasingCurve(QEasingCurve::OutQuad);

    // Démarrer la première animation
    shakeAnim->start();

    QTimer::singleShot(shakeAnim->duration(), [=]() {
        shakeAnim2->start();
        shakeAnim->deleteLater();
    });
    QTimer::singleShot(shakeAnim2->duration() + shakeAnim->duration(), [=]() {
        shakeAnim3->start();
        shakeAnim2->deleteLater();
    });
    QTimer::singleShot(shakeAnim3->duration() + shakeAnim2->duration() + shakeAnim->duration(), [=]() {
        shakeAnim3->deleteLater();
    });
}




