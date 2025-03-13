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

private:
    Ui::Genidex *ui;
};

#endif // GENIDEX_H
