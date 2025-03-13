#ifndef COMMANDE_H
#define COMMANDE_H

#include <QWidget>

namespace Ui {
class Commande;
}

class Commande : public QWidget
{
    Q_OBJECT

public:
    explicit Commande(QWidget *parent = nullptr);
    ~Commande();

private:
    Ui::Commande *ui;
};

#endif // COMMANDE_H
