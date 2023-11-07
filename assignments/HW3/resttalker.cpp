#include "resttalker.h"

RestTalker::RestTalker(QObject* parent) : QObject(parent) {
    connect(&networkManager, &QNetworkAccessManager::finished, this, &RestTalker::handleNetworkReply);
}

void RestTalker::tryRest(const QString& url) {
    QUrl requestUrl(url);
    QNetworkRequest request(requestUrl);

    QNetworkReply* reply = networkManager.get(request);
    // You can handle errors related to sending the request here
    // For example, by checking reply->error()

    // Store the QNetworkReply for future use
    // The response will be processed in the handleNetworkReply slot
}

void RestTalker::handleNetworkReply(QNetworkReply* reply) {
    if (reply->error() == QNetworkReply::NoError) {
        response = reply->readAll();
        emit replyReceived(response);
    } else {
        // Handle network errors here
        // You can access the error information using reply->error() and reply->errorString()
    }

    reply->deleteLater();
}

QByteArray RestTalker::getResponse() const {
    return response;
}
