/********************************************************************************
** Form generated from reading UI file 'genidex.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENIDEX_H
#define UI_GENIDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Genidex
{
public:
    QLabel *Genimon6;
    QLabel *Attaque;
    QLabel *Genimon5;
    QLabel *BackGround;
    QLabel *Nom1;
    QLabel *Genimon7;
    QLabel *Genimon4;
    QLabel *Nom8;
    QLabel *Nom2;
    QLabel *Genimon;
    QLabel *Genimon2;
    QLabel *Nom3;
    QLabel *Genimon1;
    QLabel *HP;
    QLabel *Nom7;
    QLabel *Description;
    QLabel *Genimon3;
    QLabel *Filtre;
    QLabel *Nom;
    QLabel *Type;
    QLabel *Genimon8;
    QLabel *Nom4;
    QLabel *Nom5;
    QLabel *Rarete;
    QLabel *Nom6;

    void setupUi(QWidget *Genidex)
    {
        if (Genidex->objectName().isEmpty())
            Genidex->setObjectName("Genidex");
        Genidex->resize(1280, 720);
        Genimon6 = new QLabel(Genidex);
        Genimon6->setObjectName("Genimon6");
        Genimon6->setGeometry(QRect(380, 400, 200, 200));
        Genimon6->setFrameShape(QFrame::Shape::Box);
        Genimon6->setFrameShadow(QFrame::Shadow::Raised);
        Genimon6->setLineWidth(10);
        Genimon6->setMidLineWidth(0);
        Attaque = new QLabel(Genidex);
        Attaque->setObjectName("Attaque");
        Attaque->setGeometry(QRect(680, 460, 500, 150));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        Attaque->setFont(font);
        Attaque->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Genimon5 = new QLabel(Genidex);
        Genimon5->setObjectName("Genimon5");
        Genimon5->setGeometry(QRect(120, 400, 200, 200));
        Genimon5->setFrameShape(QFrame::Shape::Box);
        Genimon5->setFrameShadow(QFrame::Shadow::Raised);
        Genimon5->setLineWidth(10);
        Genimon5->setMidLineWidth(0);
        BackGround = new QLabel(Genidex);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(-5, -35, 1300, 800));
        BackGround->setAutoFillBackground(true);
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/Decor/Image_Qt/Decor/Livre2D_V2.png")));
        BackGround->setScaledContents(true);
        Nom1 = new QLabel(Genidex);
        Nom1->setObjectName("Nom1");
        Nom1->setGeometry(QRect(120, 320, 201, 41));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        Nom1->setFont(font1);
        Genimon7 = new QLabel(Genidex);
        Genimon7->setObjectName("Genimon7");
        Genimon7->setGeometry(QRect(700, 400, 200, 200));
        Genimon7->setFrameShape(QFrame::Shape::Box);
        Genimon7->setFrameShadow(QFrame::Shadow::Raised);
        Genimon7->setLineWidth(10);
        Genimon7->setMidLineWidth(0);
        Genimon4 = new QLabel(Genidex);
        Genimon4->setObjectName("Genimon4");
        Genimon4->setGeometry(QRect(960, 120, 200, 200));
        Genimon4->setFrameShape(QFrame::Shape::Box);
        Genimon4->setFrameShadow(QFrame::Shadow::Raised);
        Genimon4->setLineWidth(10);
        Genimon4->setMidLineWidth(0);
        Nom8 = new QLabel(Genidex);
        Nom8->setObjectName("Nom8");
        Nom8->setGeometry(QRect(960, 600, 201, 41));
        Nom8->setFont(font1);
        Nom2 = new QLabel(Genidex);
        Nom2->setObjectName("Nom2");
        Nom2->setGeometry(QRect(380, 320, 201, 41));
        Nom2->setFont(font1);
        Genimon = new QLabel(Genidex);
        Genimon->setObjectName("Genimon");
        Genimon->setGeometry(QRect(210, 100, 301, 491));
        Genimon->setFrameShape(QFrame::Shape::Box);
        Genimon->setFrameShadow(QFrame::Shadow::Raised);
        Genimon->setLineWidth(10);
        Genimon->setMidLineWidth(0);
        Genimon2 = new QLabel(Genidex);
        Genimon2->setObjectName("Genimon2");
        Genimon2->setGeometry(QRect(380, 120, 200, 200));
        Genimon2->setFrameShape(QFrame::Shape::Box);
        Genimon2->setFrameShadow(QFrame::Shadow::Raised);
        Genimon2->setLineWidth(10);
        Genimon2->setMidLineWidth(0);
        Nom3 = new QLabel(Genidex);
        Nom3->setObjectName("Nom3");
        Nom3->setGeometry(QRect(700, 320, 201, 41));
        Nom3->setFont(font1);
        Genimon1 = new QLabel(Genidex);
        Genimon1->setObjectName("Genimon1");
        Genimon1->setGeometry(QRect(120, 120, 200, 200));
        Genimon1->setFrameShape(QFrame::Shape::Box);
        Genimon1->setFrameShadow(QFrame::Shadow::Raised);
        Genimon1->setLineWidth(10);
        Genimon1->setMidLineWidth(0);
        HP = new QLabel(Genidex);
        HP->setObjectName("HP");
        HP->setGeometry(QRect(680, 410, 500, 41));
        HP->setFont(font);
        Nom7 = new QLabel(Genidex);
        Nom7->setObjectName("Nom7");
        Nom7->setGeometry(QRect(700, 600, 201, 41));
        Nom7->setFont(font1);
        Description = new QLabel(Genidex);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(680, 190, 500, 150));
        Description->setFont(font);
        Description->setAutoFillBackground(false);
        Description->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Description->setWordWrap(true);
        Genimon3 = new QLabel(Genidex);
        Genimon3->setObjectName("Genimon3");
        Genimon3->setGeometry(QRect(700, 120, 200, 200));
        Genimon3->setFrameShape(QFrame::Shape::Box);
        Genimon3->setFrameShadow(QFrame::Shadow::Raised);
        Genimon3->setLineWidth(10);
        Genimon3->setMidLineWidth(0);
        Filtre = new QLabel(Genidex);
        Filtre->setObjectName("Filtre");
        Filtre->setGeometry(QRect(110, 50, 201, 41));
        Filtre->setFont(font1);
        Nom = new QLabel(Genidex);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(680, 90, 500, 41));
        Nom->setFont(font);
        Type = new QLabel(Genidex);
        Type->setObjectName("Type");
        Type->setGeometry(QRect(680, 360, 500, 41));
        Type->setFont(font);
        Genimon8 = new QLabel(Genidex);
        Genimon8->setObjectName("Genimon8");
        Genimon8->setGeometry(QRect(960, 400, 200, 200));
        Genimon8->setFrameShape(QFrame::Shape::Box);
        Genimon8->setFrameShadow(QFrame::Shadow::Raised);
        Genimon8->setLineWidth(10);
        Genimon8->setMidLineWidth(0);
        Nom4 = new QLabel(Genidex);
        Nom4->setObjectName("Nom4");
        Nom4->setGeometry(QRect(960, 320, 201, 41));
        Nom4->setFont(font1);
        Nom5 = new QLabel(Genidex);
        Nom5->setObjectName("Nom5");
        Nom5->setGeometry(QRect(120, 600, 201, 41));
        Nom5->setFont(font1);
        Rarete = new QLabel(Genidex);
        Rarete->setObjectName("Rarete");
        Rarete->setGeometry(QRect(680, 140, 500, 41));
        Rarete->setFont(font);
        Nom6 = new QLabel(Genidex);
        Nom6->setObjectName("Nom6");
        Nom6->setGeometry(QRect(380, 600, 201, 41));
        Nom6->setFont(font1);
        BackGround->raise();
        Genimon6->raise();
        Attaque->raise();
        Genimon5->raise();
        Nom1->raise();
        Genimon7->raise();
        Genimon4->raise();
        Nom8->raise();
        Nom2->raise();
        Genimon->raise();
        Genimon2->raise();
        Nom3->raise();
        Genimon1->raise();
        HP->raise();
        Nom7->raise();
        Description->raise();
        Genimon3->raise();
        Filtre->raise();
        Nom->raise();
        Type->raise();
        Genimon8->raise();
        Nom4->raise();
        Nom5->raise();
        Rarete->raise();
        Nom6->raise();

        retranslateUi(Genidex);

        QMetaObject::connectSlotsByName(Genidex);
    } // setupUi

    void retranslateUi(QWidget *Genidex)
    {
        Genidex->setWindowTitle(QCoreApplication::translate("Genidex", "Form", nullptr));
        Genimon6->setText(QString());
        Attaque->setText(QCoreApplication::translate("Genidex", "Attaques :", nullptr));
        Genimon5->setText(QString());
        BackGround->setText(QString());
        Nom1->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Genimon7->setText(QString());
        Genimon4->setText(QString());
        Nom8->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Nom2->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Genimon->setText(QString());
        Genimon2->setText(QString());
        Nom3->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Genimon1->setText(QString());
        HP->setText(QCoreApplication::translate("Genidex", "HP :", nullptr));
        Nom7->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Description->setText(QCoreApplication::translate("Genidex", "Description : ", nullptr));
        Genimon3->setText(QString());
        Filtre->setText(QCoreApplication::translate("Genidex", "Filtre Genimon :", nullptr));
        Nom->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Type->setText(QCoreApplication::translate("Genidex", "Type :", nullptr));
        Genimon8->setText(QString());
        Nom4->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Nom5->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
        Rarete->setText(QCoreApplication::translate("Genidex", "Raret\303\251 :", nullptr));
        Nom6->setText(QCoreApplication::translate("Genidex", "Nom :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Genidex: public Ui_Genidex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENIDEX_H
