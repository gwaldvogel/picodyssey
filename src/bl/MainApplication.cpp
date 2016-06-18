#include "MainApplication.h"

#include <QQmlContext>

MainApplication::MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent)
  : QObject(pParent)
  , m_bLoggedIn(false)
  , m_pEngine(pEngine)
//  , m_pOAuthHandlerTwitter(new OAuthHandlerFacebook(this))
{
  initUiConnections();
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

void MainApplication::initUiConnections()
{
  m_pEngine->rootContext()->setContextProperty("app", this);
//  m_pEngine->rootContext()->setContextProperty("OAuthHandlerTwitter", m_pOAuthHandlerTwitter);
}
