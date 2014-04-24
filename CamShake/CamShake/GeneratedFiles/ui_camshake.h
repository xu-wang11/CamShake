/********************************************************************************
** Form generated from reading UI file 'camshake.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMSHAKE_H
#define UI_CAMSHAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamShakeClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ContinuousBtn;
    QPushButton *DiscreteBtn;
    QPushButton *StopBtn;
    QLabel *label_detection;
    QLabel *label_hint;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CamShakeClass)
    {
        if (CamShakeClass->objectName().isEmpty())
            CamShakeClass->setObjectName(QStringLiteral("CamShakeClass"));
        CamShakeClass->resize(660, 386);
        CamShakeClass->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        centralWidget = new QWidget(CamShakeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 261, 181));
        groupBox->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(110, 25, 121, 25));
        plainTextEdit_2 = new QPlainTextEdit(groupBox);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(110, 65, 121, 25));
        plainTextEdit_3 = new QPlainTextEdit(groupBox);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(110, 105, 121, 25));
        plainTextEdit_7 = new QPlainTextEdit(groupBox);
        plainTextEdit_7->setObjectName(QStringLiteral("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(110, 145, 121, 25));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(30, 150, 54, 12));
        ContinuousBtn = new QPushButton(centralWidget);
        ContinuousBtn->setObjectName(QStringLiteral("ContinuousBtn"));
        ContinuousBtn->setEnabled(true);
        ContinuousBtn->setGeometry(QRect(40, 210, 261, 31));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ContinuousBtn->sizePolicy().hasHeightForWidth());
        ContinuousBtn->setSizePolicy(sizePolicy);
        ContinuousBtn->setStyleSheet(QStringLiteral("font: 75 9pt \"Consolas\";"));
        DiscreteBtn = new QPushButton(centralWidget);
        DiscreteBtn->setObjectName(QStringLiteral("DiscreteBtn"));
        DiscreteBtn->setEnabled(true);
        DiscreteBtn->setGeometry(QRect(40, 250, 261, 31));
        StopBtn = new QPushButton(centralWidget);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setEnabled(true);
        StopBtn->setGeometry(QRect(40, 290, 261, 31));
        label_detection = new QLabel(centralWidget);
        label_detection->setObjectName(QStringLiteral("label_detection"));
        label_detection->setGeometry(QRect(333, 31, 301, 301));
        label_hint = new QLabel(centralWidget);
        label_hint->setObjectName(QStringLiteral("label_hint"));
        label_hint->setGeometry(QRect(10, 330, 421, 21));
        label_hint->setStyleSheet(QStringLiteral("font: 75 8pt \"Consolas\";"));
        CamShakeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CamShakeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 20));
        CamShakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CamShakeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CamShakeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CamShakeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CamShakeClass->setStatusBar(statusBar);

        retranslateUi(CamShakeClass);

        QMetaObject::connectSlotsByName(CamShakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *CamShakeClass)
    {
        CamShakeClass->setWindowTitle(QApplication::translate("CamShakeClass", "CamShake", 0));
        groupBox->setTitle(QApplication::translate("CamShakeClass", "Key Setting", 0));
        label->setText(QApplication::translate("CamShakeClass", "LEFT", 0));
        label_2->setText(QApplication::translate("CamShakeClass", "RIGHT", 0));
        label_3->setText(QApplication::translate("CamShakeClass", "UP", 0));
        label_4->setText(QApplication::translate("CamShakeClass", "DOWN", 0));
        ContinuousBtn->setText(QApplication::translate("CamShakeClass", "Continuous Control", 0));
        DiscreteBtn->setText(QApplication::translate("CamShakeClass", "Discrete Control", 0));
        StopBtn->setText(QApplication::translate("CamShakeClass", "Stop", 0));
        label_detection->setText(QString());
        label_hint->setText(QApplication::translate("CamShakeClass", "This head-control widget is used for triggering key event.", 0));
    } // retranslateUi

};

namespace Ui {
    class CamShakeClass: public Ui_CamShakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMSHAKE_H
