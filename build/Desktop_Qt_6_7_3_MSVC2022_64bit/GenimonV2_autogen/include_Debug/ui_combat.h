/********************************************************************************
** Form generated from reading UI file 'combat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMBAT_H
#define UI_COMBAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Combat
{
public:
    QProgressBar *HP_V1;
    QProgressBar *HP_V2;
    QLabel *HP2;
    QLabel *Genimon2;
    QLabel *Genimon1;
    QLabel *TableauInfo;
    QLabel *BackGround;
    QLabel *Attaque4;
    QLabel *Nom2;
    QLabel *Attaque2;
    QLabel *Attaque1;
    QLabel *Attaque3;
    QLabel *HP1;
    QLabel *Nom1;

    void setupUi(QWidget *Combat)
    {
        if (Combat->objectName().isEmpty())
            Combat->setObjectName("Combat");
        Combat->resize(1280, 720);
        HP_V1 = new QProgressBar(Combat);
        HP_V1->setObjectName("HP_V1");
        HP_V1->setGeometry(QRect(320, 435, 110, 25));
        HP_V1->setValue(24);
        HP_V2 = new QProgressBar(Combat);
        HP_V2->setObjectName("HP_V2");
        HP_V2->setGeometry(QRect(940, 295, 110, 25));
        HP_V2->setValue(24);
        HP2 = new QLabel(Combat);
        HP2->setObjectName("HP2");
        HP2->setGeometry(QRect(900, 285, 150, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        HP2->setFont(font);
        Genimon2 = new QLabel(Combat);
        Genimon2->setObjectName("Genimon2");
        Genimon2->setGeometry(QRect(900, 140, 150, 150));
        Genimon2->setAutoFillBackground(true);
        Genimon1 = new QLabel(Combat);
        Genimon1->setObjectName("Genimon1");
        Genimon1->setGeometry(QRect(280, 280, 150, 150));
        Genimon1->setAutoFillBackground(true);
        TableauInfo = new QLabel(Combat);
        TableauInfo->setObjectName("TableauInfo");
        TableauInfo->setGeometry(QRect(890, 420, 391, 301));
        TableauInfo->setFont(font);
        TableauInfo->setAutoFillBackground(true);
        TableauInfo->setFrameShape(QFrame::Shape::Box);
        TableauInfo->setLineWidth(5);
        TableauInfo->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        BackGround = new QLabel(Combat);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(0, 0, 1280, 720));
        BackGround->setAutoFillBackground(true);
        BackGround->setTextFormat(Qt::TextFormat::PlainText);
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/Decor/Image_Qt/Decor/AreneCombat.png")));
        BackGround->setScaledContents(true);
        Attaque4 = new QLabel(Combat);
        Attaque4->setObjectName("Attaque4");
        Attaque4->setGeometry(QRect(530, 645, 250, 75));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        Attaque4->setFont(font1);
        Attaque4->setAutoFillBackground(true);
        Attaque4->setFrameShape(QFrame::Shape::Box);
        Attaque4->setLineWidth(5);
        Attaque4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Nom2 = new QLabel(Combat);
        Nom2->setObjectName("Nom2");
        Nom2->setGeometry(QRect(900, 105, 150, 40));
        Nom2->setFont(font);
        Attaque2 = new QLabel(Combat);
        Attaque2->setObjectName("Attaque2");
        Attaque2->setGeometry(QRect(280, 645, 250, 75));
        Attaque2->setFont(font1);
        Attaque2->setAutoFillBackground(true);
        Attaque2->setFrameShape(QFrame::Shape::Box);
        Attaque2->setLineWidth(5);
        Attaque2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Attaque1 = new QLabel(Combat);
        Attaque1->setObjectName("Attaque1");
        Attaque1->setGeometry(QRect(280, 570, 250, 75));
        Attaque1->setFont(font1);
        Attaque1->setAutoFillBackground(true);
        Attaque1->setFrameShape(QFrame::Shape::Box);
        Attaque1->setLineWidth(5);
        Attaque1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Attaque3 = new QLabel(Combat);
        Attaque3->setObjectName("Attaque3");
        Attaque3->setGeometry(QRect(530, 570, 250, 75));
        Attaque3->setFont(font1);
        Attaque3->setAutoFillBackground(true);
        Attaque3->setFrameShape(QFrame::Shape::Box);
        Attaque3->setLineWidth(5);
        Attaque3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        HP1 = new QLabel(Combat);
        HP1->setObjectName("HP1");
        HP1->setGeometry(QRect(280, 425, 150, 40));
        HP1->setFont(font);
        Nom1 = new QLabel(Combat);
        Nom1->setObjectName("Nom1");
        Nom1->setGeometry(QRect(280, 245, 150, 40));
        Nom1->setFont(font);
        BackGround->raise();
        Attaque4->raise();
        Nom2->raise();
        Attaque2->raise();
        Attaque1->raise();
        Attaque3->raise();
        Nom1->raise();
        Genimon1->raise();
        Genimon2->raise();
        HP1->raise();
        HP2->raise();
        HP_V1->raise();
        HP_V2->raise();
        TableauInfo->raise();

        retranslateUi(Combat);

        QMetaObject::connectSlotsByName(Combat);
    } // setupUi

    void retranslateUi(QWidget *Combat)
    {
        Combat->setWindowTitle(QCoreApplication::translate("Combat", "Form", nullptr));
        HP2->setText(QCoreApplication::translate("Combat", "HP :", nullptr));
        Genimon2->setText(QCoreApplication::translate("Combat", "TextLabel", nullptr));
        Genimon1->setText(QCoreApplication::translate("Combat", "TextLabel", nullptr));
        TableauInfo->setText(QCoreApplication::translate("Combat", "Info du combat :", nullptr));
        BackGround->setText(QString());
        Attaque4->setText(QString());
        Nom2->setText(QCoreApplication::translate("Combat", "Nom :", nullptr));
        Attaque2->setText(QString());
        Attaque1->setText(QString());
        Attaque3->setText(QString());
        HP1->setText(QCoreApplication::translate("Combat", "HP :", nullptr));
        Nom1->setText(QCoreApplication::translate("Combat", "Nom :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Combat: public Ui_Combat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMBAT_H
