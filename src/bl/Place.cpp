#include "Place.h"

Place::Place(QObject *pParent, QString name, QGeoLocation geoLocation, QUrl fullImage, QUrl thumbnailImage, QString description, QString city)
  : QObject(pParent)
  , m_uuid(QUuid::createUuid())
  , m_name(name)
  , m_dateTime(QDateTime::currentDateTime())
  , m_geoLocation(geoLocation)
  , m_fullImage(fullImage)
  , m_thumbnailImage(thumbnailImage)
  , m_description(description)
  , m_city(city)
{
}

Place::Place(QObject* pParent, QUuid uuid, QString name, QDateTime dateTime, QGeoLocation geoLocation, QUrl fullImage, QUrl thumbnailImage, QString description, QString city)
  : QObject(pParent)
  , m_uuid(uuid)
  , m_name(name)
  , m_dateTime(dateTime)
  , m_geoLocation(geoLocation)
  , m_fullImage(fullImage)
  , m_thumbnailImage(thumbnailImage)
  , m_description(description)
  , m_city(city)
{

}
