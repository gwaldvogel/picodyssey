#include <src/bl/MainApplication.h>
#include <Place.h>
#include <PlacesModel.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  qmlRegisterType<Place>("picodyssey", 1, 0, "Place");
  qRegisterMetaType<Place>();
  qmlRegisterType<PlacesModel>("picodyssey", 1, 0, "PlacesModel");
  qRegisterMetaType<PlacesModel>();

  QQmlApplicationEngine engine;
  MainApplication mainApplication(&engine, &app);
  mainApplication.load();

  return app.exec();
}
