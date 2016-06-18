#include "Place.h"

Place::Place(QObject *pParent, QString name, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city)
  : QObject(pParent)
  , m_placeId(QUuid::createUuid())
  , m_name(name)
  , m_date(QDateTime::currentDateTime())
  , m_geoCoordinate(geoCoordinate)
  , m_image(image)
  , m_thumbnail(thumbnail)
  , m_description(description)
  , m_city(city)
{
}

Place::Place(QObject* pParent, QUuid placeId, QString name, QDate date, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city)
  : QObject(pParent)
  , m_placeId(placeId)
  , m_name(name)
  , m_date(date)
  , m_geoCoordinate(geoCoordinate)
  , m_image(image)
  , m_thumbnail(thumbnail)
  , m_description(description)
  , m_city(city)
{

}

Place* Place::fromJson(QJsonDocument jsonDoc, QObject* pParent)
{
  if(jsonDoc.isObject() && !jsonDoc.isNull() && !jsonDoc.isEmpty())
  {
    QJsonObject jsonObj = jsonDoc.object();
    return new Place(pParent,
                     jsonObj["placeId"].toString(),
                     jsonObj["name"].toString(),
                     QDateTime::fromMSecsSinceEpoch(jsonObj["date"].toInt() * 1000).date(),
                     QGeoCoordinate(jsonObj["geoN"].toDouble(), jsonObj["geoE"].toDouble()),
                     jsonObj["image"].toString(),
                     jsonObj["thumbnail"].toString(),
                     jsonObj["description"].toString(),
                     jsonObj["city"].toString());
  }
}


