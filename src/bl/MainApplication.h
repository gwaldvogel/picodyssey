#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>

class MainApplication : public QObject
{
  Q_OBJECT
public:
  explicit MainApplication(QQmlApplicationEngine* pEngine, QObject *pParent = 0);

  void load();

signals:
private:
  QQmlApplicationEngine* m_pEngine;
};

#endif // MAINAPPLICATION_H
