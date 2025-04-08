#ifndef COMBAT_H
#define COMBAT_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Combat;
}

class Combat : public QWidget
{
    Q_OBJECT

public:
    explicit Combat(QWidget *parent = nullptr);
    ~Combat();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);

private:
    Ui::Combat *ui;
    QTimer *TransTimer;
    void update();

    void transition();
    void combat();
    void info();
    void showEvent(QShowEvent *event);

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // COMBAT_H
