/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myslider.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *voice_control;
    QPushButton *btn_open;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_ct;
    MySlider *progress_report;
    QLabel *label_all_time;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_ht;
    QPushButton *btn_qj;
    QPushButton *btn_start;
    QPushButton *btn_fullshow;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QListWidget *listWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(809, 572);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/player.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        horizontalLayout_5 = new QHBoxLayout(Widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/voice.png);"));

        horizontalLayout_3->addWidget(label_2);

        voice_control = new QSlider(Widget);
        voice_control->setObjectName(QString::fromUtf8("voice_control"));
        voice_control->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(voice_control);

        btn_open = new QPushButton(Widget);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        QFont font1;
        font1.setPointSize(20);
        btn_open->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_open->setIcon(icon1);
        btn_open->setIconSize(QSize(40, 40));
        btn_open->setFlat(true);

        horizontalLayout_3->addWidget(btn_open);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/progress.png);"));

        horizontalLayout_2->addWidget(label_4);

        label_ct = new QLabel(Widget);
        label_ct->setObjectName(QString::fromUtf8("label_ct"));

        horizontalLayout_2->addWidget(label_ct);

        progress_report = new MySlider(Widget);
        progress_report->setObjectName(QString::fromUtf8("progress_report"));
        progress_report->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(progress_report);

        label_all_time = new QLabel(Widget);
        label_all_time->setObjectName(QString::fromUtf8("label_all_time"));

        horizontalLayout_2->addWidget(label_all_time);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_ht = new QPushButton(Widget);
        btn_ht->setObjectName(QString::fromUtf8("btn_ht"));
        btn_ht->setStyleSheet(QString::fromUtf8("border:None;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/24gf-previousCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ht->setIcon(icon2);
        btn_ht->setIconSize(QSize(40, 40));
        btn_ht->setCheckable(true);
        btn_ht->setAutoExclusive(true);

        horizontalLayout->addWidget(btn_ht);

        btn_qj = new QPushButton(Widget);
        btn_qj->setObjectName(QString::fromUtf8("btn_qj"));
        btn_qj->setStyleSheet(QString::fromUtf8("border:None;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/24gf-nextCircle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_qj->setIcon(icon3);
        btn_qj->setIconSize(QSize(40, 40));
        btn_qj->setCheckable(true);
        btn_qj->setAutoExclusive(true);

        horizontalLayout->addWidget(btn_qj);

        btn_start = new QPushButton(Widget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setStyleSheet(QString::fromUtf8("border:None;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_start->setIcon(icon4);
        btn_start->setIconSize(QSize(40, 40));
        btn_start->setCheckable(true);
        btn_start->setAutoExclusive(true);

        horizontalLayout->addWidget(btn_start);

        btn_fullshow = new QPushButton(Widget);
        btn_fullshow->setObjectName(QString::fromUtf8("btn_fullshow"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/24gf-fullScreenEnter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullshow->setIcon(icon5);
        btn_fullshow->setIconSize(QSize(40, 40));
        btn_fullshow->setCheckable(true);
        btn_fullshow->setAutoExclusive(true);
        btn_fullshow->setFlat(true);

        horizontalLayout->addWidget(btn_fullshow);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(label_5);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_4->addWidget(listWidget);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_5->addLayout(horizontalLayout_6);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\230\277\347\213\270\347\232\204\346\222\255\346\224\276\345\231\250", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        btn_open->setText(QString());
        label_4->setText(QString());
        label_ct->setText(QCoreApplication::translate("Widget", "00:00:00", nullptr));
        label_all_time->setText(QCoreApplication::translate("Widget", "00:00:00", nullptr));
        btn_ht->setText(QString());
        btn_qj->setText(QString());
        btn_start->setText(QString());
        btn_fullshow->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "<html><head/><body><p>\346\222\255</p><p>\346\224\276</p><p>\345\210\227</p><p>\350\241\250</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
