
#include "CloudConfig.h"

#include <src/bl/MainApplication.h>
#include <Place.h>
#include <PlacesModel.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QUuid>


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  MainApplication mainApplication(&engine, &app);
  mainApplication.load();

  cloudconnection::CloudConfig cconfig(nullptr, "http://192.168.0.104", 80);
  QUuid uuid("0815");
  cconfig.getRandPlace();

  return app.exec();
}
