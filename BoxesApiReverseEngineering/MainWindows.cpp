/*
 *  MainWindows.cpp
 *  
 *  Created by Nicolas Aubry on 03-07-2016
 *  Copyright 2016 Nicolas Aubry. All rights reserved.
 *  
 */

#include "MainWindows.h"

MainWindows::MainWindows(QWidget *parent)
	: QMainWindow(parent), _networkManager(nullptr), _sslConfig(nullptr)
{
	this->_ui.setupUi(this);
	this->_ui.crsfToken->setTextFormat(Qt::PlainText);
	this->setUpNetwork();
	this->connectActions();
}

MainWindows::~MainWindows()
{

}

void						MainWindows::connectActions()
{
	connect(this->_ui.getHomePage, &QPushButton::clicked,
			this, &MainWindows::getHomePageTriggered);
}

void						MainWindows::setUpNetwork()
{
	this->_networkManager = new QNetworkAccessManager();

	this->_sslConfig = new QSslConfiguration(QSslConfiguration::defaultConfiguration());
	this->_sslConfig->setProtocol(QSsl::TlsV1_2);
}

void						MainWindows::getHomePageTriggered()
{
	QNetworkRequest			newRequest(QUrl(BOX_BASE_URL_HTTPS));
	QEventLoop				eventLoop;
	QString					replyText;
	QNetworkReply *			reply = nullptr;


	newRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	newRequest.setSslConfiguration(*this->_sslConfig);


	reply = this->_networkManager->get(newRequest);

	QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
	eventLoop.exec();

	if (reply->error() != QNetworkReply::NoError)
	{
		qDebug() << "Network Error:" << reply->errorString();
		return;
	}

	replyText = reply->readAll();

	qDebug() << "begin index:" << replyText.lastIndexOf(XML_META_CRSF_TOKEN_BEGIN);
	qDebug() << "end index:" << replyText.lastIndexOf(XML_META_CRSF_TOKEN_END);

	replyText.truncate(replyText.lastIndexOf(XML_META_CRSF_TOKEN_END));
	replyText = replyText.remove(0, sizeof(XML_META_CRSF_TOKEN_BEGIN) + replyText.lastIndexOf(XML_META_CRSF_TOKEN_BEGIN));

	qDebug() << sizeof(XML_META_CRSF_TOKEN_BEGIN);

	this->_ui.crsfToken->setText(replyText);
	
	if (replyText.isNull() || replyText.isEmpty())
	{
		qDebug() << "Answer for" << BOX_BASE_URL_HTTPS << "was empty or null";
		this->_ui.statusBar->setStatusTip(QString("Answer for ").append(BOX_BASE_URL_HTTPS).append(" was empty or null"));
		return;
	}
}

