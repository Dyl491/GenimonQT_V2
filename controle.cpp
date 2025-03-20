#include "controle.h"
#include "./ui_controle.h"
#include <QVBoxLayout>
#include <QSerialPortInfo>
#include <QDebug>
#include "libs/json.hpp"

using json = nlohmann::json;

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
        connect(choixJoueurMenu, &ChoixJoueur::requestMenuChange, this, &Controle::changeMenu);
    }
    Map* mapMenu = qobject_cast<Map*>(stackedWidget->widget(2));
    if (mapMenu) {
        connect(this, &Controle::sendKeyPress, mapMenu, &Map::handleKeyPress);
        connect(mapMenu, &Map::requestMenuChange, this, &Controle::changeMenu);
    }
    Capture* captureMenu = qobject_cast<Capture*>(stackedWidget->widget(3));
    if (captureMenu) {
        connect(this, &Controle::sendKeyPress, captureMenu, &Capture::handleKeyPress);
        connect(captureMenu, &Capture::requestMenuChange, this, &Controle::changeMenu);
    }
    Combat* combatMenu = qobject_cast<Combat*>(stackedWidget->widget(4));
    if (combatMenu) {
        connect(this, &Controle::sendKeyPress, combatMenu, &Combat::handleKeyPress);
        connect(combatMenu, &Combat::requestMenuChange, this, &Controle::changeMenu);
    }
    Genidex* genidexMenu = qobject_cast<Genidex*>(stackedWidget->widget(5));
    if (genidexMenu) {
        connect(this, &Controle::sendKeyPress, genidexMenu, &Genidex::handleKeyPress);
        connect(genidexMenu, &Genidex::requestMenuChange, this, &Controle::changeMenu);
    }
    HistoRencontre* histoRencontreMenu = qobject_cast<HistoRencontre*>(stackedWidget->widget(6));
    if (histoRencontreMenu) {
        connect(this, &Controle::sendKeyPress, histoRencontreMenu, &HistoRencontre::handleKeyPress);
        connect(histoRencontreMenu, &HistoRencontre::requestMenuChange, this, &Controle::changeMenu);
    }
    Commande* commandeMenu = qobject_cast<Commande*>(stackedWidget->widget(7));
    if (commandeMenu) {
        connect(this, &Controle::sendKeyPress, commandeMenu, &Commande::handleKeyPress);
        connect(commandeMenu, &Commande::requestMenuChange, this, &Controle::changeMenu);
    }
    Regle* regleMenu = qobject_cast<Regle*>(stackedWidget->widget(8));
    if (regleMenu) {
        connect(this, &Controle::sendKeyPress, regleMenu, &Regle::handleKeyPress);
        connect(regleMenu, &Regle::requestMenuChange, this, &Controle::changeMenu);
    }



    // Initialisation du port série
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        serial->setPort(info);
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            qDebug() << "Connecté à l'Arduino sur le port" << info.portName();
            connect(serial, &QSerialPort::readyRead, this, &Controle::readSerialData);
            break;
        }else {
            qDebug() << "Échec de la connexion au port" << info.portName();
        }
    }



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
            emit sendKeyPress(event->key());
        } else {
            QMainWindow::keyPressEvent(event);
        }

    }else if (stackedWidget->currentIndex() == 2) // Menu Map
    {

    }else if (stackedWidget->currentIndex() == 3) // Menu Capture
    {

    }else if (stackedWidget->currentIndex() == 4) // Menu Combat
    {

    }else if (stackedWidget->currentIndex() == 5) // Menu Genidex
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3 || event->key() == Qt::Key_F || event->key() == Qt::Key_A
            || event->key() == Qt::Key_W || event->key() == Qt::Key_D || event->key() == Qt::Key_S) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        } else {
            QMainWindow::keyPressEvent(event); // Comportement par défaut
        }
        setFocus();
    }else if (stackedWidget->currentIndex() == 6) // Menu HistoRencontre
    {

    }else if (stackedWidget->currentIndex() == 7) // Menu Commande
    {
        if (event->key() == Qt::Key_2 || event->key() == Qt::Key_H || event->key() == Qt::Key_A
            || event->key() == Qt::Key_W || event->key() == Qt::Key_D || event->key() == Qt::Key_S) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        } else {
            QMainWindow::keyPressEvent(event); // Comportement par défaut
        }
        setFocus();

    }else if (stackedWidget->currentIndex() == 8) // Menu Regle
    {
        if (event->key() == Qt::Key_2) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        } else {
            QMainWindow::keyPressEvent(event); // Comportement par défaut
        }
        setFocus();
    }else
    {
        changeMenu(0);
    }

}

void Controle::changeMenu(int index) {
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);

    }
}



void Controle::readSerialData() {
    readData.append(serial->readAll());

    if (readData.contains("\n")) {
        QString rawData = QString(readData);
        int pos1 = rawData.indexOf("{");
        int pos2 = rawData.indexOf("}", pos1);

        if (pos1 != -1 && pos2 != -1) {
            rawData = rawData.mid(pos1, pos2 - pos1 + 1);

            try {
                json j_msg_rcv = json::parse(rawData.toStdString());
                int button = j_msg_rcv.value("boutton", 0);
                int joyPos = j_msg_rcv.value("JoyPosition", 0);
                double accX = j_msg_rcv.value("AccX", 0.0);
                double accY = j_msg_rcv.value("AccY", 0.0);
                double accZ = j_msg_rcv.value("AccZ", 0.0);

                handleArduinoInput(button, joyPos, accX, accY, accZ);
            }
            catch (const json::parse_error& e) {
                qDebug() << "Erreur de parsing JSON : " << e.what();
            }
        }

        readData.clear();  // Effacer les données lues
    }
}

void Controle::handleArduinoInput(int button, int joyPos, double accX, double accY, double accZ) {
    if (stackedWidget->currentIndex() == 0) { // Menu Main
        if (button == 1) {
            changeMenu(1);
            sendToArduino("MenuChoixJoueur",1);
        } else if (button == 2) {
            changeMenu(7);
        }
    }

    if (stackedWidget->currentIndex() == 0) // Menu Main
    {
        switch (button) {
        case 1:
            changeMenu(1); // Aller à ChoixJoueur
            break;
        case 2:
            changeMenu(7); // Aller à Commande
            break;
        case 3:
            changeMenu(8); // Aller à Regle
            break;
        case 4:
            QApplication::quit(); // Quitter
            break;
        }
    }else if (stackedWidget->currentIndex() == 1) // Menu ChoixJoueur
    {
        if (button == 1 || button == 2) {
            // Émettre le signal avec la touche pressée
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

void Controle::sendToArduino(const QString &message, int nbSeg) {
    if (serial->bytesAvailable() > 0) {
        qDebug() << "Le port série est occupé, attente avant d'envoyer.";
        return;
    }

    json j_msg;
    j_msg["messageLCD"] = message.toStdString(); // Conversion QString -> std::string
    j_msg["nbSeg"] = nbSeg;

    QString jsonString = QString::fromStdString(j_msg.dump());
    serial->write(jsonString.toUtf8());

    qDebug() << "Message envoyé à Arduino : " << jsonString;
}
















