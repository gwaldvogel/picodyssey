#ifndef PLACESMODEL_H
#define PLACESMODEL_H

#include "Place.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QAbstractListModel>
#include <QObject>

class PlacesModel : public QObject
{
  Q_OBJECT

public:
  PlacesModel(QObject* pParent = 0);
  PlacesModel(QJsonDocument jsonDoc, QObject* pParent);

  QList<Place*>& getList();

signals:
  void listChanged();

private:
  QList<Place*> m_list;
};

#endif // PLACESMODEL_H
