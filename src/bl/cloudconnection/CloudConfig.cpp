#include "CloudConfig.h"

#include "Place.h"
#include "User.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QDebug>
#include <QString>

#include <cassert>

using namespace cloudconnection;

CloudConfig::CloudConfig(QObject *parent, QString cloudAddress, int cloudPort, bool useSsl)
  : QObject(parent)
  , m_cloudUrl(cloudAddress)
  , m_bUseSsl(useSsl)
{
  m_cloudUrl.setPort(cloudPort);
  m_networkManager.reset(new QNetworkAccessManager(this));
}

QString CloudConfig::getCloudAddress()
{
  return m_cloudUrl.url();
}

void CloudConfig::setCloudAddress(QString cloudAddress)
{
  if(cloudAddress != m_cloudUrl.url())
  {
    m_cloudUrl.setUrl(cloudAddress);
    emit cloudAddressChanged();
  }
}

int CloudConfig::getCloudPort()
{
  return m_cloudUrl.port();
}

void CloudConfig::setCloudPort(int cloudPort)
{
  if(cloudPort != m_cloudUrl.port())
  {
    m_cloudUrl.setPort(cloudPort);
    emit cloudPortChanged();
  }
}

bool CloudConfig::getUseSsl()
{
  return m_bUseSsl;
}

void CloudConfig::setUseSsl(bool useSsl)
{
  if(useSsl != m_bUseSsl)
  {
    m_bUseSsl = useSsl;
    emit useSslChanged();
  }
}

void CloudConfig::getPlace(QUuid const& uuid)
{
  sendGetRequest(kRequestPlace + uuid.toString());
}

void CloudConfig::getUser(QUuid const& uuid)
{
  sendGetRequest(kRequestUser + uuid.toString());
}

void CloudConfig::getPlaces()
{
  sendGetRequest(kRequestPlaces);
}

void CloudConfig::getUserPlaces(QUuid const& uuid)
{
  sendGetRequest(kRequestUserPlaces + uuid.toString());
}

void CloudConfig::sendGetRequest(QString const& requestPath)
{
  connect(m_networkManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  //m_networkManager->post(QNetworkRequest(m_cloudUrl), uuid.toByteArray());
  QUrl urlWithPath = m_cloudUrl;
  urlWithPath.setPath(requestPath);
  qDebug() << "Path " << urlWithPath.path();
  m_networkManager->get(QNetworkRequest(urlWithPath));
}

void CloudConfig::replyFinished(QNetworkReply* reply)
{
  QByteArray bytes = reply->readAll();
  int const statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
  { // debug
    QString content = QString::fromUtf8(bytes.data(), bytes.size());
    qDebug() << "Status code " << QVariant(statusCode).toString();
    qDebug() << "Content " << content;
  }
  QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes);
  if(jsonDoc.isObject() && !jsonDoc.isNull() && !jsonDoc.isEmpty())
  {
    QString type = jsonDoc.object()[Place::kKeyType].toString();
    if (QString::compare(type, Place::kValType, Qt::CaseSensitive))
    {
      Place* place = Place::fromJson(jsonDoc);


    }
    else if (QString::compare(type, User::kValType, Qt::CaseSensitive))
    {
      User* user = User::fromJson(jsonDoc);

    }
    else
    {
      assert(false);
    }
  }
}

