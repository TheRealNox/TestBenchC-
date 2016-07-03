/*
 *  main.cpp
 *  
 *  Created by Nicolas Aubry on 03-07-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#include "MainWindows.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MainWindows w;
	w.show();

	return a.exec();
}
