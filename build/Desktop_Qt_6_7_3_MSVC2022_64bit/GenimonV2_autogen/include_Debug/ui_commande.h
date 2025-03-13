/********************************************************************************
** Form generated from reading UI file 'commande.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDE_H
#define UI_COMMANDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Commande
{
public:
    QLabel *ClavierW;
    QLabel *ClavierH;
    QLabel *AccelZ;
    QLabel *ManetteB3;
    QLabel *ManetteB1;
    QLabel *TitreManette;
    QLabel *AccelX;
    QLabel *BackGround;
    QLabel *ClavierS;
    QLabel *ManetteJoy;
    QLabel *ClavierA;
    QLabel *AccelY;
    QLabel *ManetteBJoy;
    QLabel *ManetteB2;
    QLabel *ManetteB4;
    QLabel *TitreClavier;
    QLabel *ClavierD;
    QLabel *Retour1;

    void setupUi(QWidget *Commande)
    {
        if (Commande->objectName().isEmpty())
            Commande->setObjectName("Commande");
        Commande->resize(1280, 720);
        ClavierW = new QLabel(Commande);
        ClavierW->setObjectName("ClavierW");
        ClavierW->setEnabled(true);
        ClavierW->setGeometry(QRect(830, 150, 200, 40));
        QFont font;
        font.setPointSize(10);
        ClavierW->setFont(font);
        ClavierW->setAutoFillBackground(true);
        ClavierW->setScaledContents(false);
        ClavierW->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierW->setWordWrap(false);
        ClavierH = new QLabel(Commande);
        ClavierH->setObjectName("ClavierH");
        ClavierH->setEnabled(true);
        ClavierH->setGeometry(QRect(830, 350, 200, 40));
        ClavierH->setFont(font);
        ClavierH->setAutoFillBackground(true);
        ClavierH->setScaledContents(false);
        ClavierH->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierH->setWordWrap(false);
        AccelZ = new QLabel(Commande);
        AccelZ->setObjectName("AccelZ");
        AccelZ->setGeometry(QRect(200, 550, 200, 40));
        AccelZ->setFont(font);
        AccelZ->setAutoFillBackground(true);
        AccelZ->setScaledContents(false);
        AccelZ->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AccelZ->setWordWrap(false);
        ManetteB3 = new QLabel(Commande);
        ManetteB3->setObjectName("ManetteB3");
        ManetteB3->setGeometry(QRect(200, 250, 200, 40));
        ManetteB3->setFont(font);
        ManetteB3->setAutoFillBackground(true);
        ManetteB3->setScaledContents(false);
        ManetteB3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteB3->setWordWrap(false);
        ManetteB1 = new QLabel(Commande);
        ManetteB1->setObjectName("ManetteB1");
        ManetteB1->setEnabled(true);
        ManetteB1->setGeometry(QRect(200, 150, 200, 40));
        ManetteB1->setFont(font);
        ManetteB1->setAutoFillBackground(true);
        ManetteB1->setScaledContents(false);
        ManetteB1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteB1->setWordWrap(false);
        TitreManette = new QLabel(Commande);
        TitreManette->setObjectName("TitreManette");
        TitreManette->setGeometry(QRect(200, 50, 200, 40));
        QFont font1;
        font1.setPointSize(14);
        TitreManette->setFont(font1);
        TitreManette->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AccelX = new QLabel(Commande);
        AccelX->setObjectName("AccelX");
        AccelX->setGeometry(QRect(200, 450, 200, 40));
        AccelX->setFont(font);
        AccelX->setAutoFillBackground(true);
        AccelX->setScaledContents(false);
        AccelX->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AccelX->setWordWrap(false);
        BackGround = new QLabel(Commande);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(0, 0, 1280, 721));
        BackGround->setBaseSize(QSize(100, 100));
        BackGround->setAutoFillBackground(true);
        BackGround->setFrameShape(QFrame::Shape::Box);
        BackGround->setTextFormat(Qt::TextFormat::PlainText);
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/MainMenu/Image_Qt/EcranAccueil/pixel-art-sky-background-with-clouds-cloudy-blue-sky-for-8bit-game-on-white-background-vector.jpg")));
        BackGround->setScaledContents(true);
        ClavierS = new QLabel(Commande);
        ClavierS->setObjectName("ClavierS");
        ClavierS->setEnabled(true);
        ClavierS->setGeometry(QRect(830, 250, 200, 40));
        ClavierS->setFont(font);
        ClavierS->setAutoFillBackground(true);
        ClavierS->setScaledContents(false);
        ClavierS->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierS->setWordWrap(false);
        ManetteJoy = new QLabel(Commande);
        ManetteJoy->setObjectName("ManetteJoy");
        ManetteJoy->setGeometry(QRect(200, 400, 200, 40));
        ManetteJoy->setFont(font);
        ManetteJoy->setAutoFillBackground(true);
        ManetteJoy->setScaledContents(false);
        ManetteJoy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteJoy->setWordWrap(false);
        ClavierA = new QLabel(Commande);
        ClavierA->setObjectName("ClavierA");
        ClavierA->setEnabled(true);
        ClavierA->setGeometry(QRect(830, 300, 200, 40));
        ClavierA->setFont(font);
        ClavierA->setAutoFillBackground(true);
        ClavierA->setScaledContents(false);
        ClavierA->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierA->setWordWrap(false);
        AccelY = new QLabel(Commande);
        AccelY->setObjectName("AccelY");
        AccelY->setGeometry(QRect(200, 500, 200, 40));
        AccelY->setFont(font);
        AccelY->setAutoFillBackground(true);
        AccelY->setScaledContents(false);
        AccelY->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AccelY->setWordWrap(false);
        ManetteBJoy = new QLabel(Commande);
        ManetteBJoy->setObjectName("ManetteBJoy");
        ManetteBJoy->setGeometry(QRect(200, 350, 200, 40));
        ManetteBJoy->setFont(font);
        ManetteBJoy->setAutoFillBackground(true);
        ManetteBJoy->setScaledContents(false);
        ManetteBJoy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteBJoy->setWordWrap(false);
        ManetteB2 = new QLabel(Commande);
        ManetteB2->setObjectName("ManetteB2");
        ManetteB2->setGeometry(QRect(200, 200, 200, 40));
        ManetteB2->setFont(font);
        ManetteB2->setAutoFillBackground(true);
        ManetteB2->setScaledContents(false);
        ManetteB2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteB2->setWordWrap(false);
        ManetteB4 = new QLabel(Commande);
        ManetteB4->setObjectName("ManetteB4");
        ManetteB4->setGeometry(QRect(200, 300, 200, 40));
        ManetteB4->setFont(font);
        ManetteB4->setAutoFillBackground(true);
        ManetteB4->setScaledContents(false);
        ManetteB4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ManetteB4->setWordWrap(false);
        TitreClavier = new QLabel(Commande);
        TitreClavier->setObjectName("TitreClavier");
        TitreClavier->setGeometry(QRect(830, 50, 200, 40));
        TitreClavier->setFont(font1);
        TitreClavier->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierD = new QLabel(Commande);
        ClavierD->setObjectName("ClavierD");
        ClavierD->setEnabled(true);
        ClavierD->setGeometry(QRect(830, 200, 200, 40));
        ClavierD->setFont(font);
        ClavierD->setAutoFillBackground(true);
        ClavierD->setScaledContents(false);
        ClavierD->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ClavierD->setWordWrap(false);
        Retour1 = new QLabel(Commande);
        Retour1->setObjectName("Retour1");
        Retour1->setGeometry(QRect(565, 600, 150, 40));
        QPalette palette;
        QBrush brush(QColor(135, 135, 135, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        Retour1->setPalette(palette);
        Retour1->setAutoFillBackground(true);
        Retour1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        BackGround->raise();
        ClavierW->raise();
        ClavierH->raise();
        AccelZ->raise();
        ManetteB3->raise();
        ManetteB1->raise();
        TitreManette->raise();
        AccelX->raise();
        ClavierS->raise();
        ManetteJoy->raise();
        ClavierA->raise();
        AccelY->raise();
        ManetteBJoy->raise();
        ManetteB2->raise();
        ManetteB4->raise();
        TitreClavier->raise();
        ClavierD->raise();
        Retour1->raise();

        retranslateUi(Commande);

        QMetaObject::connectSlotsByName(Commande);
    } // setupUi

    void retranslateUi(QWidget *Commande)
    {
        Commande->setWindowTitle(QCoreApplication::translate("Commande", "Form", nullptr));
        ClavierW->setText(QCoreApplication::translate("Commande", "W", nullptr));
        ClavierH->setText(QCoreApplication::translate("Commande", "H", nullptr));
        AccelZ->setText(QCoreApplication::translate("Commande", "Accel_Z :", nullptr));
        ManetteB3->setText(QCoreApplication::translate("Commande", "Bouton3", nullptr));
        ManetteB1->setText(QCoreApplication::translate("Commande", "Bouton1", nullptr));
        TitreManette->setText(QCoreApplication::translate("Commande", "Controle Manette", nullptr));
        AccelX->setText(QCoreApplication::translate("Commande", "Accel_X :", nullptr));
        BackGround->setText(QString());
        ClavierS->setText(QCoreApplication::translate("Commande", "S", nullptr));
        ManetteJoy->setText(QCoreApplication::translate("Commande", "EtatJoystick :", nullptr));
        ClavierA->setText(QCoreApplication::translate("Commande", "A", nullptr));
        AccelY->setText(QCoreApplication::translate("Commande", "Accel_Y :", nullptr));
        ManetteBJoy->setText(QCoreApplication::translate("Commande", "BoutonJoystick", nullptr));
        ManetteB2->setText(QCoreApplication::translate("Commande", "Bouton2", nullptr));
        ManetteB4->setText(QCoreApplication::translate("Commande", "Bouton4", nullptr));
        TitreClavier->setText(QCoreApplication::translate("Commande", "Equivalent Clavier", nullptr));
        ClavierD->setText(QCoreApplication::translate("Commande", "D", nullptr));
        Retour1->setText(QCoreApplication::translate("Commande", "Retour au menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Commande: public Ui_Commande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDE_H
