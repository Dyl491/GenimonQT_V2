#include "historencontre.h"
#include "ui_historencontre.h"

HistoRencontre::HistoRencontre(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoRencontre)
{
    ui->setupUi(this);
}

HistoRencontre::~HistoRencontre()
{
    delete ui;
}

void HistoRencontre::handleKeyPress(int key) {

}
