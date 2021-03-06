#include "Place.h"

#include <QBuffer>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QImageWriter>

QString const Place::kKeyType = "type";
QString const Place::kValType = "place";

Place::Place(QObject *pParent, QString name, QGeoCoordinate geoCoordinate, QString image, QUrl thumbnail, QString description, QString city)
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
  emit imageChanged();
}

Place::Place(QObject* pParent, QUuid placeId, QString name, QDate date, QGeoCoordinate geoCoordinate, QString image, QUrl thumbnail, QString description, QString city)
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
  emit imageChanged();
}

Place* Place::fromJson(QJsonDocument jsonDoc, QObject* pParent)
{
  Place* retVal = nullptr;
  if(jsonDoc.isObject() && !jsonDoc.isNull() && !jsonDoc.isEmpty())
  {
    QJsonObject jsonObj = jsonDoc.object();
    QImage tempImage;
    QString image;
    Place::base64ToImage(tempImage, jsonObj["image"].toString().toLatin1());
    image = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/tempImage" + QString::number(qrand())  + ".jpg";

    if(!QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)).exists())
    {
      QDir().mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    }

    QImageWriter writer(image);
    if(!writer.write(tempImage))
    {
      qDebug() << writer.errorString();
    }
    retVal = new Place(pParent,
                     QUuid(jsonObj["placeId"].toString()),
                     jsonObj["name"].toString(),
                     QDateTime::fromMSecsSinceEpoch(jsonObj["date"].toInt() * 1000).date(),
                     QGeoCoordinate(jsonObj["geoN"].toString().toDouble(), jsonObj["geoE"].toString().toDouble()),
                     image,
                     jsonObj["thumbnail"].toString(),
                     jsonObj["description"].toString(),
                     jsonObj["city"].toString());
    qDebug() << jsonObj["geoN"].toString().toDouble() << jsonObj["geoE"].toDouble() << QGeoCoordinate(jsonObj["geoN"].toDouble(), jsonObj["geoE"].toDouble()) << QGeoCoordinate(jsonObj["geoN"].toDouble(), jsonObj["geoE"].toDouble()).latitude(), QGeoCoordinate(jsonObj["geoN"].toDouble(), jsonObj["geoE"].toDouble()).longitude();
  }
  return retVal;
}

void Place::base64ToImage(QImage& imagePng, QByteArray const& base64Image)
{
  imagePng.loadFromData(QByteArray::fromBase64(base64Image), "JPG");
}

void Place::imageTo64Base(QByteArray& base64Image, QImage const& imagePng)
{
  QBuffer buffer(&base64Image);
  buffer.open(QIODevice::WriteOnly);
  imagePng.save(&buffer, "JPG");
  base64Image = base64Image.toBase64();

}

QJsonDocument Place::toJson()
{
  QJsonObject jsonObj;
  QByteArray base64Image;
//  Place::imageTo64Base(base64Image, m_image);
  jsonObj.insert("placeId", m_placeId.toString().replace("{", "").replace("}", ""));
  jsonObj.insert("name", m_name);
  jsonObj.insert("date", (m_date.toMSecsSinceEpoch() / 1000));
  jsonObj.insert("geoN", m_geoCoordinate.longitude());
  jsonObj.insert("geoE", m_geoCoordinate.latitude());
  jsonObj.insert("image", QString(base64Image));
  jsonObj.insert("thumbnail", m_thumbnail.toString());
  jsonObj.insert("description", m_description);
  jsonObj.insert("city", "Freiburg");
  jsonObj.insert(kKeyType, kValType);
  return QJsonDocument(jsonObj);
}
