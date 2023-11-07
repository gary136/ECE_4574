#ifndef RESTTALKER_H
#define RESTTALKER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

class RestTalker : public QObject {
    Q_OBJECT
public:
    RestTalker(QObject* parent = nullptr);

    void tryRest(const QString& url);

    QByteArray getResponse() const;

signals:
    void replyReceived(const QByteArray& response);

private slots:
    void handleNetworkReply(QNetworkReply* reply);

private:
    QNetworkAccessManager networkManager;
    QByteArray response;
};

#endif // RESTTALKER_H
