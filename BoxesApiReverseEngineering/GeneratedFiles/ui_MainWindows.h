/********************************************************************************
** Form generated from reading UI file 'MainWindows.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWS_H
#define UI_MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowsClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *tryLogin;
    QPushButton *getHomePage;
    QLabel *crsfToken;
    QLabel *label_2;
    QLineEdit *loginInput;
    QLabel *label;
    QLineEdit *passwordInput;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowsClass)
    {
        if (MainWindowsClass->objectName().isEmpty())
            MainWindowsClass->setObjectName(QStringLiteral("MainWindowsClass"));
        MainWindowsClass->resize(600, 197);
        centralWidget = new QWidget(MainWindowsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tryLogin = new QPushButton(centralWidget);
        tryLogin->setObjectName(QStringLiteral("tryLogin"));

        gridLayout->addWidget(tryLogin, 3, 0, 1, 2);

        getHomePage = new QPushButton(centralWidget);
        getHomePage->setObjectName(QStringLiteral("getHomePage"));

        gridLayout->addWidget(getHomePage, 0, 0, 1, 2);

        crsfToken = new QLabel(centralWidget);
        crsfToken->setObjectName(QStringLiteral("crsfToken"));

        gridLayout->addWidget(crsfToken, 0, 2, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        loginInput = new QLineEdit(centralWidget);
        loginInput->setObjectName(QStringLiteral("loginInput"));

        gridLayout->addWidget(loginInput, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 3, 1, 1);

        passwordInput = new QLineEdit(centralWidget);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));

        gridLayout->addWidget(passwordInput, 2, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        MainWindowsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MainWindowsClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowsClass->setStatusBar(statusBar);

        retranslateUi(MainWindowsClass);

        QMetaObject::connectSlotsByName(MainWindowsClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowsClass)
    {
        MainWindowsClass->setWindowTitle(QApplication::translate("MainWindowsClass", "Box.es API Discovering", 0));
        tryLogin->setText(QApplication::translate("MainWindowsClass", "try Login", 0));
        getHomePage->setText(QApplication::translate("MainWindowsClass", "get box.es crsf token", 0));
        crsfToken->setText(QString());
        label_2->setText(QApplication::translate("MainWindowsClass", "login", 0));
        loginInput->setText(QString());
        label->setText(QString());
        passwordInput->setText(QString());
        label_3->setText(QApplication::translate("MainWindowsClass", "password", 0));
        label_4->setText(QApplication::translate("MainWindowsClass", "Status:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowsClass: public Ui_MainWindowsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
