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

private:
    Ui::Combat *ui;
    QTimer *TransTimer;
    void transition();
    void combat();
    void info();
    void showEvent(QShowEvent *event);

signals:
    void requestMenuChange(int index);  // Signal pour demander un changement de menu
};

#endif // COMBAT_H
