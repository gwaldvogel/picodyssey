#include "MainApplication.h"

MainApplication::MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent)
  : QObject(pParent)
  , m_pEngine(pEngine)
{
}

void MainApplication::load()
{
  m_pEngine->load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
}
