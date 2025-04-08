#ifndef GENIDEX_H
#define GENIDEX_H

#include <QWidget>

namespace Ui {
class Genidex;
}

class Genidex : public QWidget
{
    Q_OBJECT

public:
    explicit Genidex(QWidget *parent = nullptr);
    ~Genidex();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);

private:
    Ui::Genidex *ui;
    void update();

    void showGenimon();
    void showListGenimon();
    void highlight();

    int etat = 0; // 0 = listGenimon, 1 = Genimon
    QString etatFiltre = "aucun";
    int selectionGenimon = 0; //0 a 7

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // GENIDEX_H
