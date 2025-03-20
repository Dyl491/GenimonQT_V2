#ifndef CONTROLE_H
#define CONTROLE_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QKeyEvent>
#include <QSerialPort>
#include "libs/json.hpp"

using json = nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui {
class Controle;
}
QT_END_NAMESPACE

class Controle : public QMainWindow
{
    Q_OBJECT

public:
    Controle(QWidget *parent = nullptr);
    ~Controle();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Controle *ui;
    QStackedWidget *stackedWidget;
    QSerialPort *serial;
    QByteArray readData;

    void changeMenu(int index);
    void handleArduinoInput(int bouton, int joyPosition, double accX, double accY, double accZ);
    void sendToArduino(const QString &message, int nbSeg);

private slots:
    void readSerialData();

signals:
    void sendKeyPress(int key); // Signal pour envoyer les touches clavier
};
#endif // CONTROLE_H
