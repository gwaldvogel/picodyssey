#include "PlacesModel.h"

PlacesModel::PlacesModel(QObject* pParent)
  : QAbstractListModel(pParent)
{

}

PlacesModel::PlacesModel(QJsonDocument jsonDoc, QObject* pParent)
  : QAbstractListModel(pParent)
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

/*  Returns the number of items in the string list as the number of rows
    in the model. */
int PlacesModel::rowCount(const QModelIndex& parent) const
{
  return m_list.count();
}

/*  Returns an appropriate value for the requested data.
    If the view requests an invalid index, an invalid variant is returned.
    Any valid index that corresponds to a string in the list causes that
    string to be returned. */
QVariant PlacesModel::data(const QModelIndex& index, int role) const
{
  if(!index.isValid())
  {
    return QVariant();
  }

  if(index.row() >= m_list.size())
  {
    return QVariant();
  }

  if(role == Qt::DisplayRole)
  {
    //return QVariant(m_list.at(index.row()));
  }
  else
  {
    return QVariant();
  }
}

/*  Returns the appropriate header string depending on the orientation of
    the header and the section. If anything other than the display role is
    requested, we return an invalid variant. */
//QVariant PlacesModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//  if (role != Qt::DisplayRole)
//  {
//    return QVariant();
//  }


//}

void PlacesModel::appendToList(Place* place)
{
  m_list.append(place);
  emit listChanged();
}

//QVariantList PlacesModel::getList()
//{
//  QVariantList qVList;
//  for(auto item: m_list)
//  {
//    qVList.append(QVariant(item));
//  }
//  return qVList;
//}
