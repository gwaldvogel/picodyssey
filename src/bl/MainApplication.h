#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <Place.h>
#include <CloudConfig.h>

class MainApplication : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool loggedIn READ getLoggedIn WRITE setLoggedIn NOTIFY loggedInChanged)
  Q_PROPERTY(Place* currentPlace READ getCurrentPlace WRITE setCurrentPlace NOTIFY currentPlaceChanged)
//  Q_PROPERTY(QGeoCoordinate lastMarkerCoordinates READ getLastMarkerCoordinates WRITE setLastMarkerCoordinates NOTIFY lastMarkerCoordinatesChanged)

public:
  MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent = 0);

  void load();

  bool getLoggedIn();
  void setLoggedIn(bool loggedIn);
  void setCurrentPlace(Place* place);
  Place* getCurrentPlace();

  Q_INVOKABLE void loadNewPlace();

  cloudconnection::CloudConfig cconfig;

//  QGeoCoordinate getLastMarkerCoordinates();
//  void setLastMarkerCoordinates(QGeoCoordinate marker);

Q_INVOKABLE void uploadPicture(QString image);

signals:
  void loggedInChanged(bool loggedIn);
  void currentPlaceChanged();
//  void lastMarkerCoordinatesChanged();

private:
  void initUiConnections();
  bool m_bLoggedIn;
  Place* m_pCurrentPlace;
//  QGeoCoordinate m_lastMarkerCoordinates;

  QQmlApplicationEngine* m_pEngine;
//  OAuthHandlerFacebook* m_pOAuthHandlerTwitter;
};

#endif // MAINAPPLICATION_H
