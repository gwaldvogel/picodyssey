#include <src/bl/MainApplication.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  MainApplication mainApplication(&engine, &app);
  mainApplication.load();

  return app.exec();
}
