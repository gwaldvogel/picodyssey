#ifndef PLACESMODEL_H
#define PLACESMODEL_H

#include <QObject>

class PlacesModel : public QObject
{
  Q_OBJECT
public:
  explicit PlacesModel(QObject *parent = 0);

signals:

public slots:
};

#endif // PLACESMODEL_H