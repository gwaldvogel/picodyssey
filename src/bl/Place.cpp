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
                     QUuid(jsonObj["placeId"].toString()),
                     jsonObj["name"].toString(),
                     QDateTime::fromMSecsSinceEpoch(jsonObj["date"].toInt() * 1000).date(),
                     QGeoCoordinate(jsonObj["geoN"].toDouble(), jsonObj["geoE"].toDouble()),
                     jsonObj["image"].toString(),
                     jsonObj["thumbnail"].toString(),
                     jsonObj["description"].toString(),
                     jsonObj["city"].toString());
  }
}

QJsonDocument Place::toJson()
{
  QJsonObject jsonObj;
  jsonObj.insert("placeId", m_placeId.toString().replace("{", "").replace("}", ""));
  jsonObj.insert("name", m_name);
  jsonObj.insert("date", (m_date.toMSecsSinceEpoch() / 1000));
  jsonObj.insert("geoN", m_geoCoordinate.longitude());
  jsonObj.insert("geoE", m_geoCoordinate.latitude());
  jsonObj.insert("image", m_image.toString());
  jsonObj.insert("thumbnail", m_thumbnail.toString());
  jsonObj.insert("description", m_description);
  jsonObj.insert("city", "Freiburg");
  jsonObj.insert(kKeyType, kValType);
  return QJsonDocument(jsonObj);
}


