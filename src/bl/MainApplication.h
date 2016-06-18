#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <Place.h>

class MainApplication : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool loggedIn READ getLoggedIn WRITE setLoggedIn NOTIFY loggedInChanged)
  Q_PROPERTY(Place* currentPlace READ getCurrentPlace WRITE setCurrentPlace NOTIFY currentPlaceChanged)

public:
  MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent = 0);

  void load();

  bool getLoggedIn();
  void setLoggedIn(bool loggedIn);
  void setCurrentPlace(Place* place);
  Place* getCurrentPlace();


signals:
  void loggedInChanged(bool loggedIn);
  void currentPlaceChanged();

private:
  void initUiConnections();
  bool m_bLoggedIn;
  Place* m_pCurrentPlace;

  QQmlApplicationEngine* m_pEngine;
//  OAuthHandlerFacebook* m_pOAuthHandlerTwitter;
};

#endif // MAINAPPLICATION_H
