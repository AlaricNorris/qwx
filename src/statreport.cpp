// Copyright (C) 2014 Leslie Zhai <xiang.zhai@i-soft.com.cn>

#include "statreport.h"
#include "globaldeclarations.h"

StatReport::StatReport(HttpPost* parent) 
  : HttpPost(parent)
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

StatReport::~StatReport() 
{
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
#endif
}

void StatReport::firstRequestSuccess(QString uuid) 
{
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxstatreport?type=1&r=" + 
        QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"" + WX_CGI_PATH 
        + "login, First Request Success, uuid: " + uuid + "\"}]}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void StatReport::secondRequestStart(QString uuid) 
{
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxstatreport?type=1&r=" + 
        QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"" + WX_CGI_PATH 
        + "login, Second Request Start, uuid: " + uuid + "\"}]}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void StatReport::post(QString uuid) 
{
    QString url = WX_SERVER_HOST + WX_CGI_PATH + "webwxstatreport?type=1&r=" + 
        QString::number(time(NULL));
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << url;
#endif
    QString json = "{\"BaseRequest\":{\"Uin\":0,\"Sid\":0},\"Count\":1,"
        "\"List\":[{\"Type\":1,\"Text\":\"" + WX_CGI_PATH + "login, "
        "Second Request Success, uuid: " + uuid + ", time: 190765ms\"}]}";
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__ << json;
#endif
    HttpPost::post(url, json);
}

void StatReport::finished(QNetworkReply* reply) 
{
    QString replyStr = QString(reply->readAll());
#if QWX_DEBUG
    qDebug() << "DEBUG:" << __PRETTY_FUNCTION__;
    qDebug() << "DEBUG:" << replyStr;
#endif
}