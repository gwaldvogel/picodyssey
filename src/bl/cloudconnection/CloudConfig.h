#ifndef CLOUDCONFIG_H
#define CLOUDCONFIG_H

#include <QObject>
#include <QString>
#include <QUuid>
#include <QUrl>
#include <QNetworkAccessManager>

#include <memory>

namespace cloudconnection
{
  /**
   * @brief CloudConfig holds all necessery information to connect to a cloud
   *
   * Every property is also exposed to QML and since CloudConfig inherits from QObject
   * it is already registered in the Qt meta-object system
   */
  class CloudConfig : public QObject
  {
    Q_OBJECT

    Q_PROPERTY(QString cloudAddress READ getCloudAddress WRITE setCloudAddress NOTIFY cloudAddressChanged)
    Q_PROPERTY(int cloudPort READ getCloudPort WRITE setCloudPort NOTIFY cloudPortChanged)
    Q_PROPERTY(bool useSSL READ getUseSsl WRITE setUseSsl NOTIFY useSslChanged)

  public:
    /**
     * @brief CloudConfig constructor
     *
     * @param[in] parent        parent for the QObject child-parent system
     * @param[in] cloudAddress  ip or dns address to the cloud
     * @param[in] cloudPort     port of the cloud
     * @param[in] useSsl        is the cloud connection encrypted
     */
    explicit CloudConfig(QObject *parent = 0, QString cloudAddress = "localhost", int cloudPort = 80, bool useSsl = false);

    /**
     * @brief getCloudAddress
     * @return the currently set ip or dns address
     */
    QString getCloudAddress();

    /**
     * @brief setCloudAddress
     * @param[in] cloudAddress  ip or dns address to the cloud
     */
    void setCloudAddress(QString cloudAddress);

    /**
     * @brief getCloudPort
     * @return the currently set cloud port
     */
    int getCloudPort();

    /**
     * @brief setCloudPort
     * @param[in] cloudPort port of the cloud
     */
    void setCloudPort(int cloudPort);

    /**
     * @brief getUseSsl
     * @return current encryption setting
     */
    bool getUseSsl();

    /**
     * @brief setUseSsl
     * @param[in] useSsl  new encryption setting
     */
    void setUseSsl(bool useSsl);

    void getPlace();
    void getPlace(QUuid const& uuid);
    void getUser(QUuid const& uuid);

    void getPlaces();
    void getUserPlaces(QUuid const& uuid);

  public slots:
    void replyFinished(QNetworkReply* reply);

  signals:
    void cloudAddressChanged();
    void cloudPortChanged();
    void useSslChanged();

  private:

    QString const kRequestPlace = "/getPlace/";
    QString const kRequestUser = "/getUser/";

    QString const kRequestPlaces = "/getPlaces/";
    QString const kRequestUserPlaces = "/getUserPlaces/";

    std::unique_ptr<QNetworkAccessManager> m_networkManager;
    QUrl m_cloudUrl;
    bool m_bUseSsl;

    QObject* m_parent;

    void sendGetRequest(QString const& requestPath);
  };
}

#endif // CLOUDCONFIG_H
