#include "controle.h"
#include "./ui_controle.h"
#include "mainmenu.h"

#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>



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
    stackedWidget->addWidget(new Pause(this)); // Index 9
    stackedWidget->addWidget(new ChoixAction(this)); // Index 10
    setCentralWidget(stackedWidget);

    choixJoueurMenu = qobject_cast<ChoixJoueur*>(stackedWidget->widget(1));
    mapMenu = qobject_cast<Map*>(stackedWidget->widget(2));
    captureMenu = qobject_cast<Capture*>(stackedWidget->widget(3));
    combatMenu = qobject_cast<Combat*>(stackedWidget->widget(4));
    genidexMenu = qobject_cast<Genidex*>(stackedWidget->widget(5));
    histoRencontreMenu = qobject_cast<HistoRencontre*>(stackedWidget->widget(6));
    commandeMenu = qobject_cast<Commande*>(stackedWidget->widget(7));
    regleMenu = qobject_cast<Regle*>(stackedWidget->widget(8));
    pauseMenu = qobject_cast<Pause*>(stackedWidget->widget(9));
    choixActionMenu = qobject_cast<ChoixAction*>(stackedWidget->widget(10));

    //Permet d'envoyer nom joueur de choixJoueur a Map
    connect(choixJoueurMenu, &ChoixJoueur::sendNomJoueur, mapMenu, &Map::setNomJoueur);

}

Controle::~Controle()
{
    if (sendDataTimer) {
        sendDataTimer->stop();
        delete sendDataTimer;
    }

    if (serialPort && serialPort->isOpen()) {
        stopReading();
        serialPort->close();
    }

    delete serialPort;
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
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3 || event->key() == Qt::Key_4) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 3) // Menu Capture
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 4) // Menu Combat
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3 || event->key() == Qt::Key_4) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 5) // Menu Genidex
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3 || event->key() == Qt::Key_F || event->key() == Qt::Key_A
            || event->key() == Qt::Key_W || event->key() == Qt::Key_D || event->key() == Qt::Key_S) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 6) // Menu HistoRencontre
    {
        if (event->key() == Qt::Key_4) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 7) // Menu Commande
    {
        if (event->key() == Qt::Key_2 || event->key() == Qt::Key_H || event->key() == Qt::Key_A
            || event->key() == Qt::Key_W || event->key() == Qt::Key_D || event->key() == Qt::Key_S) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 8) // Menu Regle
    {
        if (event->key() == Qt::Key_2) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }else if (stackedWidget->currentIndex() == 9) // Menu Pause
    {

    }else if (stackedWidget->currentIndex() == 10) // Menu ChoixAction
    {
        if (event->key() == Qt::Key_1 || event->key() == Qt::Key_2 || event->key() == Qt::Key_3) {
            emit sendKeyPress(event->key()); // Émettre le signal avec la touche pressée
        }

    }

}

void Controle::changeMenu(int index) {
    if (index >= 0 && index < stackedWidget->count()) {
        stackedWidget->setCurrentIndex(index);
    }

// Deconnecter les liens entres menu avant d'en faire d'autres
    disconnect(this, &Controle::sendKeyPress, choixJoueurMenu, &ChoixJoueur::handleKeyPress);
    disconnect(choixJoueurMenu, &ChoixJoueur::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, mapMenu, &Map::handleKeyPress);
    disconnect(mapMenu, &Map::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, captureMenu, &Capture::handleKeyPress);
    disconnect(captureMenu, &Capture::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, combatMenu, &Combat::handleKeyPress);
    disconnect(combatMenu, &Combat::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, genidexMenu, &Genidex::handleKeyPress);
    disconnect(genidexMenu, &Genidex::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, histoRencontreMenu, &HistoRencontre::handleKeyPress);
    disconnect(histoRencontreMenu, &HistoRencontre::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, commandeMenu, &Commande::handleKeyPress);
    disconnect(commandeMenu, &Commande::requestMenuChange, this, &Controle::changeMenu);
    disconnect(this, &Controle::sendKeyPress, regleMenu, &Regle::handleKeyPress);
    disconnect(regleMenu, &Regle::requestMenuChange, this, &Controle::changeMenu);

    disconnect(this, &Controle::sendKeyPress, choixActionMenu, &ChoixAction::handleKeyPress);
    disconnect(choixActionMenu, &ChoixAction::requestMenuChange, this, &Controle::changeMenu);


// Relier commande clavier et de changement de menu aux autres menus.
    if(index == 1){
        connect(this, &Controle::sendKeyPress, choixJoueurMenu, &ChoixJoueur::handleKeyPress);
        connect(choixJoueurMenu, &ChoixJoueur::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 2){
        connect(this, &Controle::sendKeyPress, mapMenu, &Map::handleKeyPress);
        connect(mapMenu, &Map::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 3){
        connect(this, &Controle::sendKeyPress, captureMenu, &Capture::handleKeyPress);
        connect(captureMenu, &Capture::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 4){
        connect(this, &Controle::sendKeyPress, combatMenu, &Combat::handleKeyPress);
        connect(combatMenu, &Combat::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 5){
        connect(this, &Controle::sendKeyPress, genidexMenu, &Genidex::handleKeyPress);
        connect(genidexMenu, &Genidex::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 6){
        connect(this, &Controle::sendKeyPress, histoRencontreMenu, &HistoRencontre::handleKeyPress);
        connect(histoRencontreMenu, &HistoRencontre::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 7){
        connect(this, &Controle::sendKeyPress, commandeMenu, &Commande::handleKeyPress);
        connect(commandeMenu, &Commande::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 8){
        connect(this, &Controle::sendKeyPress, regleMenu, &Regle::handleKeyPress);
        connect(regleMenu, &Regle::requestMenuChange, this, &Controle::changeMenu);
    }else if(index == 9){

    }else if(index == 10){
        connect(this, &Controle::sendKeyPress, choixActionMenu, &ChoixAction::handleKeyPress);
        connect(choixActionMenu, &ChoixAction::requestMenuChange, this, &Controle::changeMenu);
    }
}



//---------- Communication aruino --------------------------------------------------------------------------

void Controle::connectToArduino() {

    // Vérifiez s'il existe des ports série disponibles
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    if (availablePorts.isEmpty()) {
        // Si aucun port série n'est disponible, affichez un message d'erreur à l'utilisateur
        qDebug() << "Erreur, aucun port série disponible. Assurez-vous que l'Arduino est correctement connecté.";
        return;
    }

    bool connected = false;
    foreach (const QSerialPortInfo &info, availablePorts) {
        serialPort->setPort(info);
        serialPort->setBaudRate(QSerialPort::Baud115200);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if (serialPort->open(QIODevice::ReadWrite)) {
            qDebug() << "Connecté à l'Arduino sur le port" << info.portName();
            connected = true;
            break;  // Sortir dès que la connexion est établie
        } else {
            qDebug() << "Échec de la connexion au port" << info.portName();
        }
    }

    if (!connected) {
        // Si la connexion échoue, affichez un message à l'utilisateur
        qDebug() << "Erreur de connexion, Échec de la connexion à l'Arduino. Vérifiez le câble et réessayez.";
    }else{
        //Lier communication manette
        connect(serialPort, &QSerialPort::readyRead, this, &Controle::RcvFromSerial);
        connect(sendDataTimer, &QTimer::timeout, this, [this]() {SendToSerial(MESSAGE, SEGMENT);});
    }
}

void Controle::startReading() {
    // Commence à lire les données série
    if (!serialPort->isOpen()) {
        connectToArduino();
        qDebug() << "Commence à lire les données série";
    }else{
        qDebug() << "Communication deja fonctionnelle";
    }
}

void Controle::stopReading() {
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Arrete à lire les données série";
    }
}

void Controle::RcvFromSerial() {
    static QByteArray buffer;  // Tampon pour accumuler les données
    QJsonObject jsonObject;

    // Lire les données du port série
    // Lire toutes les données disponibles
    buffer.append(serialPort->readAll());
    qDebug() << "Données lues:" << buffer;
    qDebug() << "Lire les données du port série" << buffer;

    // Vérifier si nous avons un message complet (terminé par un '\n')
    int endIndex = buffer.indexOf('}');
    if (endIndex != -1) {
        QByteArray data = buffer.left(endIndex);  // Extraire le message complet
        buffer.remove(0, endIndex + 1);  // Supprimer le message du tampon

        // Si les données sont en format JSON, on les analyse
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (doc.isNull()) {
            qDebug() << "Erreur : Le JSON est mal formé.";
            return;
        } else {
            if (doc.isObject()) {
                jsonObject = doc.object();
                qDebug() << "C'est un objet JSON";
                qDebug() << "Émission du signal dataReceived";
            }else if (doc.isArray()) {
                QJsonArray jsonArray = doc.array();
                qDebug() << "C'est un tableau JSON";
                jsonObject["array"] = jsonArray;
            }else {
                QVariant value = doc.toVariant();
                qDebug() << "C'est une valeur simple:" << value;
            }
        }
    }

    if (jsonObject.contains("boutton")) {
        BOUTTONS = jsonObject["boutton"].toInt();
    }
    if (jsonObject.contains("JoyPosition")) {
        JOYSTICK = jsonObject["JoyPosition"].toInt();
    }

    if (jsonObject.contains("AccCountZ")) {
        ACCELEROMETRE = jsonObject["AccCountZ"].toInt();
    }

    if (jsonObject.contains("muons")) {
        MUONS = jsonObject["muons"].toInt();
    }

    qDebug() << "manette :" << BOUTTONS << JOYSTICK << ACCELEROMETRE << MUONS;

    sendDataTimer->start(100);

}



void Controle::SendToSerial(const QString &message, int segment) {
    QJsonObject jsonObject;
    jsonObject["message"] = message;
    jsonObject["segment"] = segment;

    // Convertir l'objet JSON en QByteArray
    QJsonDocument doc(jsonObject);
    QByteArray jsonData = doc.toJson();

    // Envoyer le message JSON via le port série
    if (serialPort->isOpen()) {
        serialPort->write(jsonData);
        qDebug() << "Message envoyé à l'Arduino:" << jsonData;
    } else {
        qDebug() << "Erreur : Port série non ouvert.";
    }
}



void Controle::setSegment(int seg)
{
    SEGMENT = seg;
}

void Controle::setMessage(QString mes)
{
    MESSAGE = mes;
}








