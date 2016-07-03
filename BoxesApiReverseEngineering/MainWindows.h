/*
 *  MainWindows.h
 *  
 *  Created by Nicolas Aubry on 03-07-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#ifndef __MAINWINDOWS_H__
#define __MAINWINDOWS_H__

//Qt includes
#include <QtConcurrent>
#include <QtWidgets/QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslConfiguration>

//Local includes
#include "DefinesAndEnums.h"
#include "WebHelper.h"

//Ui includes
#include "ui_MainWindows.h"

class						MainWindows : public QMainWindow
{
	Q_OBJECT
	// -- Attributs
private:
	Ui::MainWindowsClass	_ui;
	QNetworkAccessManager *	_networkManager;
	QSslConfiguration *		_sslConfig;
	QString					_autToken;
	// --!Attributs

	// -- CTors & DTor
public:
	MainWindows(QWidget *parent = 0);
	~MainWindows();

private:
	// --!CTors & DTor

	// -- Methods
public:

private:
	void					connectActions();
	void					setUpNetwork();
	// --!Methods

	// -- SignalsAndSlots
private slots:
	void					getHomePageTriggered();
	void					tryLoinTriggered();
	// --!SignalsAndSlots
};

#endif//__MAINWINDOWS_H__

