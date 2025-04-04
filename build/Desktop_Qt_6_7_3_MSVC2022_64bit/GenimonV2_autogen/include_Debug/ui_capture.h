/********************************************************************************
** Form generated from reading UI file 'capture.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURE_H
#define UI_CAPTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Capture
{
public:
    QLabel *BackGround;
    QLabel *Genimon;
    QLabel *Joueur;
    QLabel *Capturer;
    QLabel *Partir;
    QLabel *Pokeball;

    void setupUi(QWidget *Capture)
    {
        if (Capture->objectName().isEmpty())
            Capture->setObjectName("Capture");
        Capture->resize(1280, 720);
        BackGround = new QLabel(Capture);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(0, 0, 1280, 720));
        BackGround->setAutoFillBackground(true);
        BackGround->setTextFormat(Qt::TextFormat::PlainText);
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/Decor/Image_Qt/Decor/AreneCombat.png")));
        BackGround->setScaledContents(true);
        Genimon = new QLabel(Capture);
        Genimon->setObjectName("Genimon");
        Genimon->setGeometry(QRect(800, 50, 300, 300));
        Genimon->setAutoFillBackground(true);
        Joueur = new QLabel(Capture);
        Joueur->setObjectName("Joueur");
        Joueur->setGeometry(QRect(50, 440, 250, 250));
        Joueur->setAutoFillBackground(true);
        Capturer = new QLabel(Capture);
        Capturer->setObjectName("Capturer");
        Capturer->setGeometry(QRect(420, 610, 250, 75));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        Capturer->setFont(font);
        Capturer->setAutoFillBackground(true);
        Capturer->setFrameShape(QFrame::Shape::Box);
        Capturer->setLineWidth(5);
        Capturer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Partir = new QLabel(Capture);
        Partir->setObjectName("Partir");
        Partir->setGeometry(QRect(690, 610, 250, 75));
        Partir->setFont(font);
        Partir->setAutoFillBackground(true);
        Partir->setFrameShape(QFrame::Shape::Box);
        Partir->setLineWidth(5);
        Partir->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Pokeball = new QLabel(Capture);
        Pokeball->setObjectName("Pokeball");
        Pokeball->setGeometry(QRect(500, 190, 100, 80));
        Pokeball->setAutoFillBackground(false);
        Pokeball->setPixmap(QPixmap(QString::fromUtf8(":/Decor/Image_Qt/Decor/pokeball1.png")));
        Pokeball->setScaledContents(true);

        retranslateUi(Capture);

        QMetaObject::connectSlotsByName(Capture);
    } // setupUi

    void retranslateUi(QWidget *Capture)
    {
        Capture->setWindowTitle(QCoreApplication::translate("Capture", "Form", nullptr));
        BackGround->setText(QString());
        Genimon->setText(QCoreApplication::translate("Capture", "TextLabel", nullptr));
        Joueur->setText(QCoreApplication::translate("Capture", "TextLabel", nullptr));
        Capturer->setText(QCoreApplication::translate("Capture", "Lancer ball (1)", nullptr));
        Partir->setText(QCoreApplication::translate("Capture", "Partir (2)", nullptr));
        Pokeball->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Capture: public Ui_Capture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURE_H
