#ifndef REGLE_H
#define REGLE_H

#include <QWidget>

namespace Ui {
class Regle;
}

class Regle : public QWidget
{
    Q_OBJECT

public:
    explicit Regle(QWidget *parent = nullptr);
    ~Regle();

private:
    Ui::Regle *ui;
};

#endif // REGLE_H
