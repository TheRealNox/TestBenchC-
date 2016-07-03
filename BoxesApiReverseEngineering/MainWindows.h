/*
 *  MainWindows.h
 *  
 *  Created by Nicolas Aubry on 03-07-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#ifndef __MAINWINDOWS_H__
#define __MAINWINDOWS_H__

#include <QtWidgets/QMainWindow>
#include "ui_MainWindows.h"

class						MainWindows : public QMainWindow
{
	Q_OBJECT
	// -- Attributs
private:
	Ui::MainWindowsClass	_ui;
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
	// --!Methods
};

#endif//__MAINWINDOWS_H__

