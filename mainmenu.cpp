#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMediaPlayer>
#include <QAudioOutput>

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QAudioOutput *audioOutput = new QAudioOutput(this);
    QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setSource(QUrl("qrc:/Music/Image_Qt/Music/Blitzkrieg 2022.wav"));
    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->play();
}

MainMenu::~MainMenu()
{
    delete ui;
}
