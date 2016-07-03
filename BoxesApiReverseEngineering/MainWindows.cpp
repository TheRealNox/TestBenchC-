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
	connect(this->_ui.tryLogin, &QPushButton::clicked,
		this, &MainWindows::tryLoinTriggered);
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

	if (replyText.isNull() || replyText.isEmpty())
	{
		qDebug() << "Answer for" << BOX_BASE_URL_HTTPS << "was empty or null";
		this->_ui.statusBar->setStatusTip(QString("Answer for ").append(BOX_BASE_URL_HTTPS).append(" was empty or null"));
		return;
	}

	replyText.truncate(replyText.lastIndexOf(XML_META_CRSF_TOKEN_END));
	replyText = replyText.remove(0, sizeof(XML_META_CRSF_TOKEN_BEGIN) + replyText.lastIndexOf(XML_META_CRSF_TOKEN_BEGIN));

	this->_ui.crsfToken->setText(replyText);
	this->_autToken = replyText;
}

void						MainWindows::tryLoinTriggered()
{
	QNetworkRequest			newRequest(QUrl(BOX_LOGIN_URL_TTPS));
	QEventLoop				eventLoop;
	QString					replyText;
	QNetworkReply *			reply = nullptr;


	QString					postData = QString(BOX_LOGIN_POST_DATA)
		.arg(this->_autToken.toHtmlEscaped())
		.arg(QString("nox.aubry@gmail.com").toHtmlEscaped())
		.arg(QString("r3m!1989n0x"));

	newRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	newRequest.setRawHeader("origin", "https://box.es");
	newRequest.setSslConfiguration(*this->_sslConfig);

	reply = this->_networkManager->post(newRequest, QByteArray(postData.toStdString().c_str()));

	QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
	eventLoop.exec();

	if (reply->error() != QNetworkReply::NoError)
	{
		qDebug() << "Network Error:" << reply->errorString();
		return;
	}

	replyText = reply->readAll();

	const QList<QPair<QByteArray, QByteArray>> headers = reply->rawHeaderPairs();

	for each (auto pair in headers)
	{
		qDebug() << "header name:" << pair.first << "header data" << pair.second;
	}


	if (replyText.isNull() || replyText.isEmpty())
	{
		qDebug() << "Answer for" << BOX_BASE_URL_HTTPS << "was empty or null";
		this->_ui.statusBar->setStatusTip(QString("Answer for ").append(BOX_BASE_URL_HTTPS).append(" was empty or null"));
		return;
	}

}