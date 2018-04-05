/********************************************************************************
** Form generated from reading UI file 'MainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *widget;
    QLabel *label_6;
    QLineEdit *lineEdit_Step;
    QLabel *label_7;
    QLineEdit *lineEdit_Frequency;
    QLabel *label;
    QLineEdit *lineEdit_Sigma;
    QLabel *label_2;
    QLineEdit *lineEdit_Epsilon;
    QLabel *label_3;
    QLineEdit *lineEdit_Radius;
    QLabel *label_4;
    QLineEdit *lineEdit_Height;
    QLabel *label_8;
    QLineEdit *lineEdit_HeightRec;
    QLabel *label_9;
    QRadioButton *radioButton_Ez;
    QRadioButton *radioButton_Hy;
    QRadioButton *radioButton_Hx;
    QRadioButton *radioButton_Ja;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_Settings;
    QLineEdit *lineEdit_WidthRec;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(725, 561);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWin->sizePolicy().hasHeightForWidth());
        MainWin->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setSizeIncrement(QSize(0, 0));

        gridLayout->addWidget(widget, 0, 0, 21, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        lineEdit_Step = new QLineEdit(centralwidget);
        lineEdit_Step->setObjectName(QStringLiteral("lineEdit_Step"));

        gridLayout->addWidget(lineEdit_Step, 1, 1, 1, 4);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 1, 1, 2);

        lineEdit_Frequency = new QLineEdit(centralwidget);
        lineEdit_Frequency->setObjectName(QStringLiteral("lineEdit_Frequency"));

        gridLayout->addWidget(lineEdit_Frequency, 3, 1, 1, 4);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 1, 1, 1);

        lineEdit_Sigma = new QLineEdit(centralwidget);
        lineEdit_Sigma->setObjectName(QStringLiteral("lineEdit_Sigma"));

        gridLayout->addWidget(lineEdit_Sigma, 5, 1, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 6, 1, 1, 1);

        lineEdit_Epsilon = new QLineEdit(centralwidget);
        lineEdit_Epsilon->setObjectName(QStringLiteral("lineEdit_Epsilon"));

        gridLayout->addWidget(lineEdit_Epsilon, 7, 1, 1, 4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 8, 1, 1, 1);

        lineEdit_Radius = new QLineEdit(centralwidget);
        lineEdit_Radius->setObjectName(QStringLiteral("lineEdit_Radius"));

        gridLayout->addWidget(lineEdit_Radius, 9, 1, 1, 4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 10, 1, 1, 2);

        lineEdit_Height = new QLineEdit(centralwidget);
        lineEdit_Height->setObjectName(QStringLiteral("lineEdit_Height"));

        gridLayout->addWidget(lineEdit_Height, 11, 1, 1, 4);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 12, 1, 1, 2);

        lineEdit_HeightRec = new QLineEdit(centralwidget);
        lineEdit_HeightRec->setObjectName(QStringLiteral("lineEdit_HeightRec"));

        gridLayout->addWidget(lineEdit_HeightRec, 13, 1, 1, 4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 14, 1, 1, 2);

        radioButton_Ez = new QRadioButton(centralwidget);
        radioButton_Ez->setObjectName(QStringLiteral("radioButton_Ez"));
        radioButton_Ez->setChecked(true);

        gridLayout->addWidget(radioButton_Ez, 16, 1, 1, 1);

        radioButton_Hy = new QRadioButton(centralwidget);
        radioButton_Hy->setObjectName(QStringLiteral("radioButton_Hy"));

        gridLayout->addWidget(radioButton_Hy, 16, 2, 1, 1);

        radioButton_Hx = new QRadioButton(centralwidget);
        radioButton_Hx->setObjectName(QStringLiteral("radioButton_Hx"));

        gridLayout->addWidget(radioButton_Hx, 16, 3, 1, 1);

        radioButton_Ja = new QRadioButton(centralwidget);
        radioButton_Ja->setObjectName(QStringLiteral("radioButton_Ja"));

        gridLayout->addWidget(radioButton_Ja, 16, 4, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 17, 1, 1, 2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 18, 1, 1, 4);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 19, 1, 1, 3);

        pushButton_Settings = new QPushButton(centralwidget);
        pushButton_Settings->setObjectName(QStringLiteral("pushButton_Settings"));

        gridLayout->addWidget(pushButton_Settings, 20, 1, 1, 3);

        lineEdit_WidthRec = new QLineEdit(centralwidget);
        lineEdit_WidthRec->setObjectName(QStringLiteral("lineEdit_WidthRec"));

        gridLayout->addWidget(lineEdit_WidthRec, 15, 1, 1, 4);

        MainWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWin->setStatusBar(statusbar);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "Cathode irradiation", 0));
        label_6->setText(QApplication::translate("MainWin", "dx:", 0));
        label_7->setText(QApplication::translate("MainWin", "Frequency:", 0));
        label->setText(QApplication::translate("MainWin", "Sigma:", 0));
        label_2->setText(QApplication::translate("MainWin", "Epsilon:", 0));
        label_3->setText(QApplication::translate("MainWin", "Radius:", 0));
        label_4->setText(QApplication::translate("MainWin", "Height(R*H):", 0));
        label_8->setText(QApplication::translate("MainWin", "Height Rect:", 0));
        label_9->setText(QApplication::translate("MainWin", "Width Rect:", 0));
        radioButton_Ez->setText(QApplication::translate("MainWin", "Ez", 0));
        radioButton_Hy->setText(QApplication::translate("MainWin", "Hy", 0));
        radioButton_Hx->setText(QApplication::translate("MainWin", "Hx", 0));
        radioButton_Ja->setText(QApplication::translate("MainWin", "Ja", 0));
        label_5->setText(QApplication::translate("MainWin", "Time, ns:", 0));
        pushButton_2->setText(QApplication::translate("MainWin", "Start", 0));
        pushButton_Settings->setText(QApplication::translate("MainWin", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
