/********************************************************************************
** Form generated from reading UI file 'choixaction.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXACTION_H
#define UI_CHOIXACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChoixAction
{
public:
    QLabel *BackGround;
    QLabel *Genimon;
    QLabel *Attaque;
    QLabel *Capturer;
    QLabel *Fuir;

    void setupUi(QWidget *ChoixAction)
    {
        if (ChoixAction->objectName().isEmpty())
            ChoixAction->setObjectName("ChoixAction");
        ChoixAction->resize(1280, 720);
        BackGround = new QLabel(ChoixAction);
        BackGround->setObjectName("BackGround");
        BackGround->setGeometry(QRect(0, 0, 1280, 720));
        BackGround->setBaseSize(QSize(100, 100));
        BackGround->setAutoFillBackground(true);
        BackGround->setFrameShape(QFrame::Shape::Box);
        BackGround->setTextFormat(Qt::TextFormat::PlainText);
        BackGround->setPixmap(QPixmap(QString::fromUtf8(":/Decor/Image_Qt/Decor/AreneCombat.png")));
        BackGround->setScaledContents(true);
        Genimon = new QLabel(ChoixAction);
        Genimon->setObjectName("Genimon");
        Genimon->setGeometry(QRect(440, 50, 400, 400));
        Genimon->setAutoFillBackground(true);
        Attaque = new QLabel(ChoixAction);
        Attaque->setObjectName("Attaque");
        Attaque->setGeometry(QRect(57, 530, 350, 120));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        Attaque->setFont(font);
        Attaque->setAutoFillBackground(true);
        Attaque->setFrameShape(QFrame::Shape::Box);
        Attaque->setLineWidth(5);
        Attaque->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Capturer = new QLabel(ChoixAction);
        Capturer->setObjectName("Capturer");
        Capturer->setGeometry(QRect(465, 530, 350, 120));
        Capturer->setFont(font);
        Capturer->setAutoFillBackground(true);
        Capturer->setFrameShape(QFrame::Shape::Box);
        Capturer->setLineWidth(5);
        Capturer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Fuir = new QLabel(ChoixAction);
        Fuir->setObjectName("Fuir");
        Fuir->setGeometry(QRect(875, 530, 350, 120));
        Fuir->setFont(font);
        Fuir->setAutoFillBackground(true);
        Fuir->setFrameShape(QFrame::Shape::Box);
        Fuir->setLineWidth(5);
        Fuir->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(ChoixAction);

        QMetaObject::connectSlotsByName(ChoixAction);
    } // setupUi

    void retranslateUi(QWidget *ChoixAction)
    {
        ChoixAction->setWindowTitle(QCoreApplication::translate("ChoixAction", "Form", nullptr));
        BackGround->setText(QString());
        Genimon->setText(QCoreApplication::translate("ChoixAction", "TextLabel", nullptr));
        Attaque->setText(QCoreApplication::translate("ChoixAction", "Attaquer (1)", nullptr));
        Capturer->setText(QCoreApplication::translate("ChoixAction", "Capturer (2)", nullptr));
        Fuir->setText(QCoreApplication::translate("ChoixAction", "Fuir (3)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChoixAction: public Ui_ChoixAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXACTION_H
