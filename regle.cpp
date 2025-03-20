#include "regle.h"
#include "ui_regle.h"
#include <QDebug>

Regle::Regle(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Regle)
{
    ui->setupUi(this);
}

Regle::~Regle()
{
    delete ui;
}

void Regle::handleKeyPress(int key) {

    if (key == Qt::Key_2) {
        emit requestMenuChange(0); //Passer au menu principal
        clearFocus();
    }
}
