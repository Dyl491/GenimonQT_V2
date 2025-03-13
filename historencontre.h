#ifndef HISTORENCONTRE_H
#define HISTORENCONTRE_H

#include <QWidget>

namespace Ui {
class HistoRencontre;
}

class HistoRencontre : public QWidget
{
    Q_OBJECT

public:
    explicit HistoRencontre(QWidget *parent = nullptr);
    ~HistoRencontre();

private:
    Ui::HistoRencontre *ui;
};

#endif // HISTORENCONTRE_H
