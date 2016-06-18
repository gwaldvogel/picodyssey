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
public:
  Place(QObject *pParent, QString name, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city = "freiburg");
  Place(QObject *pParent, QUuid placeId, QString name, QDate date, QGeoCoordinate geoCoordinate, QUrl image, QUrl thumbnail, QString description, QString city = "freiburg");
  static Place* fromJson(QJsonDocument jsonDoc, QObject* pParent = 0);

private:
  QUuid m_placeId;
  QString m_name;
  QDateTime m_date;
  QGeoCoordinate m_geoCoordinate;
  QUrl m_image;
  QUrl m_thumbnail;

  QString m_description;
  QString m_city;
  QString m_type = "place";
};

#endif // PLACE_H
