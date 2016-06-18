#ifndef PLACESMODEL_H
#define PLACESMODEL_H

#include "Place.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QAbstractListModel>
#include <QObject>

class PlacesModel : public QAbstractListModel
{
  Q_OBJECT

public:
  PlacesModel(QObject* pParent = Q_NULLPTR);
  PlacesModel(QJsonDocument jsonDoc, QObject* pParent = Q_NULLPTR);
  PlacesModel(const PlacesModel &other);
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
  void appendToList(Place* place);
//  QVariantList getList();
  ~PlacesModel();

signals:
  void listChanged();

private:
  QList<Place*> m_list;
};

Q_DECLARE_METATYPE(PlacesModel)
#endif // PLACESMODEL_H
