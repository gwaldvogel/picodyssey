#include "CloudConnection.h"

using namespace cloudconnection;

CloudConnection::CloudConnection(QObject *parent)
  : QObject(parent)
  , m_cloudConfig(new CloudConfig(this))
{

}
