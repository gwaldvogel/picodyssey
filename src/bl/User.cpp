#include "User.h"

QString const User::kKeyType = "type";
QString const User::kValType = "user";

User::User(QObject* pParent, QUuid userId, QString name, uint8_t numberOfPlaces)
  : QObject(pParent)
  , m_userId(userId)
  , m_name(name)
  , m_numberOfPlaces(numberOfPlaces)
  , m_places(new PlacesModel(this))
{

}

User* User::fromJson(QJsonDocument jsonDoc, QObject* pParent)
{
  User* retVal = nullptr;
  if(jsonDoc.isObject() && !jsonDoc.isNull() && !jsonDoc.isEmpty())
  {
    QJsonObject jsonObj = jsonDoc.object();
    retVal = new User(pParent,
                    QUuid(jsonObj["userId"].toString()),
                    jsonObj["name"].toString(),
                    jsonObj["numberOfPlaces"].toInt());
  }
  return retVal;
}

QJsonDocument User::toJson()
{
  QJsonObject jsonObj;
  jsonObj.insert("UserId", m_userId.toString().replace("{", "").replace("}", ""));
  jsonObj.insert("name", m_name);
  jsonObj.insert("numberOfPlaces", m_numberOfPlaces);
  jsonObj.insert(kKeyType, kValType);
  return QJsonDocument(jsonObj);
}
