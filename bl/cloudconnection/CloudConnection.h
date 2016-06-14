#ifndef CLOUDCONNECTION_H
#define CLOUDCONNECTION_H

#include <bl/cloudconnection/CloudConfig.h>

#include <QObject>

namespace cloudconnection
{
  class CloudConnection : public QObject
  {
    Q_OBJECT
  public:
    explicit CloudConnection(QObject *parent = 0);

  signals:

  private:
    CloudConfig m_cloudConfig;
  };
}

#endif // CLOUDCONNECTION_H
