#ifndef MAP_H
#define MAP_H

#include <QWidget>

namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);
    void setNomJoueur(const QString &nom);

private:
    Ui::Map *ui;
    void update();

    void showExtFaculte();
    void showIntFaculte();
    void showCombat();
    void showGenidex();
    void showHistoRencontre();
    void quitGame();

    QString nomJoueur = "default";
    bool isPaused = 0;

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
    void setSegment(int seg);
    void setMessage(QString mes);
};

#endif // MAP_H
