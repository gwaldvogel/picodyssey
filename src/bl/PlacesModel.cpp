#include "PlacesModel.h"

PlacesModel::PlacesModel(QObject* pParent)
  : QObject(pParent)
{

}

PlacesModel::PlacesModel(QJsonDocument jsonDoc, QObject* pParent)
  : QObject(pParent)
{
  if(jsonDoc.isArray() && !jsonDoc.isNull() && !jsonDoc.isEmpty())
  {
    QJsonArray jsonArray = jsonDoc.array();
    for(int32_t i = 0; i < jsonArray.size(); ++i)
    {
      m_list.append(Place::fromJson(QJsonDocument(jsonArray[i].toObject())));
    }
  }
}

QList<Place*>& PlacesModel::getList()
{
  return m_list;
}

