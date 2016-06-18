#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>

class MainApplication : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool loggedIn READ getLoggedIn WRITE setLoggedIn NOTIFY loggedInChanged)

public:
  MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent = 0);

  void load();

  bool getLoggedIn();
  void setLoggedIn(bool loggedIn);

signals:
  void loggedInChanged(bool loggedIn);

private:
  void initUiConnections();
  bool m_bLoggedIn;

  QQmlApplicationEngine* m_pEngine;
//  OAuthHandlerFacebook* m_pOAuthHandlerTwitter;
};

#endif // MAINAPPLICATION_H
