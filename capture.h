#ifndef CAPTURE_H
#define CAPTURE_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>

namespace Ui {
class Capture;
}

class Capture : public QWidget
{
    Q_OBJECT

public:
    explicit Capture(QWidget *parent = nullptr);
    ~Capture();

public slots:
    void handleKeyPress(int key);
    void handleArduinoInput(int boutons, int joystick, int accelerometre, int muons);

private:
    Ui::Capture *ui;
    QPropertyAnimation *animation;
    void update();

    void animPokeball();
    void animCapture();

    int BOUTONS = 0;
    int JOYSTICKS = 0;
    int ACCEL = 0;
    int MUONS = 0;

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // CAPTURE_H
