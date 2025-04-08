#ifndef CHOIXACTION_H
#define CHOIXACTION_H

#include <QWidget>

namespace Ui {
class ChoixAction;
}

class ChoixAction : public QWidget
{
    Q_OBJECT

public:
    explicit ChoixAction(QWidget *parent = nullptr);
    ~ChoixAction();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);

private:
    Ui::ChoixAction *ui;
    void update();

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // CHOIXACTION_H
