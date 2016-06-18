#ifndef PLACE_H
#define PLACE_H

#include <QObject>
#include <QUuid>
#include <QUrl>
#include <QDateTime>
#include <QGeoLocation>

class Place : public QObject
{
  Q_OBJECT
public:
  Place(QObject *pParent, QString name, QGeoLocation geoLocation, QUrl fullImage, QUrl thumbnailImage, QString description, QString city = "freiburg");
  Place(QObject *pParent, QUuid uuid, QString name, QDateTime dateTime, QGeoLocation geoLocation, QUrl fullImage, QUrl thumbnailImage, QString description, QString city = "freiburg");

private:
  QUuid m_uuid;
  QString m_name;
  QDateTime m_dateTime;
  QGeoLocation m_geoLocation;
  QUrl m_fullImage;
  QUrl m_thumbnailImage;
  QString m_description;
  QString m_city;
  QString m_type = "place";
};

#endif // PLACE_H
