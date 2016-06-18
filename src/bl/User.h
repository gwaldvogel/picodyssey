#ifndef USER_H
#define USER_H

#include "PlacesModel.h"

#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QUuid>

class User : public QObject
{
  Q_OBJECT
public:
  User(QObject* pParent, QUuid userId, QString name, uint8_t numberOfPlaces);
  static User* fromJson(QJsonDocument jsonDoc, QObject* pParent = 0);
  QJsonDocument toJson();

private:
  QUuid m_userId;
  QString m_name;
  uint8_t m_numberOfPlaces;
  PlacesModel* m_places;

  QString m_type = "user";
};

#endif // USER_H
