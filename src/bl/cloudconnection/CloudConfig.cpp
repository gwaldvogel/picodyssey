#include "CloudConfig.h"

using namespace cloudconnection;

CloudConfig::CloudConfig(QObject *parent, QString cloudAddress, int cloudPort, bool useSsl)
  : QObject(parent)
  , m_qstrCloudAddress(cloudAddress)
  , m_cloudPort(cloudPort)
  , m_bUseSsl(useSsl)
{

}

QString CloudConfig::getCloudAddress()
{
  return m_qstrCloudAddress;
}

void CloudConfig::setCloudAddress(QString cloudAddress)
{
  if(cloudAddress != m_qstrCloudAddress)
  {
    m_qstrCloudAddress = cloudAddress;
    emit cloudAddressChanged();
  }
}

int CloudConfig::getCloudPort()
{
  return m_cloudPort;
}

void CloudConfig::setCloudPort(int cloudPort)
{
  if(cloudPort != m_cloudPort)
  {
    m_cloudPort = cloudPort;
    emit cloudPortChanged();
  }
}

bool CloudConfig::getUseSsl()
{
  return m_bUseSsl;
}

void CloudConfig::setUseSsl(bool useSsl)
{
  if(useSsl != m_bUseSsl)
  {
    m_bUseSsl = useSsl;
    emit useSslChanged();
  }
}
