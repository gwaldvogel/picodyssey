#ifndef PLACESMODEL_H
#define PLACESMODEL_H

#include "Place.h"

#include <QObject>

class PlacesModel : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QList list READ getList NOTIFY listChanged)
public:
  PlacesModel(QObject* pParent = 0);
  void appendToList(Place* place);
  QList getList();

signals:
  void listChanged();

private:
  Qlist m_list;
};

#endif // PLACESMODEL_H
