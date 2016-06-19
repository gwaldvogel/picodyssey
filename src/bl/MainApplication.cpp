#include "MainApplication.h"

#include <QDebug>
#include <QQmlContext>

MainApplication::MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent)
  : QObject(pParent)
  , m_bLoggedIn(false)
//  , m_lastMarkerCoordinates()
  , m_pEngine(pEngine)
  , cconfig(this, "http://192.168.2.192", 80)
//  , m_pOAuthHandlerTwitter(new OAuthHandlerFacebook(this))
{
  initUiConnections();
  cconfig.getRandPlace();
}

void MainApplication::load()
{
  m_pEngine->load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
}

bool MainApplication::getLoggedIn()
{
  return m_bLoggedIn;
}

void MainApplication::setLoggedIn(bool loggedIn)
{
  if(m_bLoggedIn != loggedIn)
  {
    m_bLoggedIn = loggedIn;
    emit loggedInChanged(m_bLoggedIn);
  }
}

void MainApplication::setCurrentPlace(Place* place)
{
  if(m_pCurrentPlace != place)
  {
    m_pCurrentPlace = place;
    emit currentPlaceChanged();
  }
}

Place*MainApplication::getCurrentPlace()
{
  return m_pCurrentPlace;
}

void MainApplication::loadNewPlace()
{
  cconfig.getRandPlace();
}

//QGeoCoordinate MainApplication::getLastMarkerCoordinates()
//{
//  return m_lastMarkerCoordinates;
//}

//void MainApplication::setLastMarkerCoordinates(QGeoCoordinate marker)
//{
//  if(m_lastMarkerCoordinates != marker)
//  {
//    m_lastMarkerCoordinates = marker;
//    emit lastMarkerCoordinatesChanged();
//  }
//}

void MainApplication::uploadPicture(QString image)
{
  qDebug() << "Fancy upload shice...";
}

void MainApplication::initUiConnections()
{
  m_pEngine->rootContext()->setContextProperty("app", this);
//  m_pEngine->rootContext()->setContextProperty("OAuthHandlerTwitter", m_pOAuthHandlerTwitter);
}

