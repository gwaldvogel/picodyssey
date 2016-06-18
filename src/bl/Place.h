#ifndef PLACE_H
#define PLACE_H

#include <QDateTime>
#include <QGeoCoordinate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QUrl>
#include <QUuid>

class Place : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QUuid placeId MEMBER m_placeId CONSTANT)
  Q_PROPERTY(QString name MEMBER m_name CONSTANT)
  Q_PROPERTY(QDateTime date MEMBER m_date CONSTANT)
  Q_PROPERTY(QGeoCoordinate geoCoordinates MEMBER m_geoCoordinates CONSTANT)
  Q_PROPERTY(QUrl image MEMBER m_image CONSTANT)
  Q_PROPERTY(QUrl thumbnail MEMBER m_thumbnail CONSTANT)
  Q_PROPERTY(QString description MEMBER m_description CONSTANT)
  Q_PROPERTY(QString city MEMBER m_city CONSTANT)
public:
  Place() {}
  Place(QObject *pParent, QString name, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city = "freiburg");
  Place(QObject *pParent, QUuid placeId, QString name, QDate date, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city = "freiburg");
  Place(const Place &other);
  static Place* fromJson(QJsonDocument jsonDoc, QObject* pParent = 0);
  QJsonDocument toJson();
  ~Place();

private:
  QUuid           m_placeId;
  QString         m_name;
  QDateTime       m_date;
  QGeoCoordinate  m_geoCoordinate;
  QUrl            m_image;
  QUrl            m_thumbnail;
  QString         m_description;
  QString         m_city;
  QString         m_type = "place";
};

Q_DECLARE_METATYPE(Place)
#endif // PLACE_H
