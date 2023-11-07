#include "base64coder.h"
#include <QUrl>
#include <QEventLoop>
#include <QCoreApplication>
#include "resttalker.h"
#include <QJsonDocument>
#include <QJsonObject>

Base64Coder::Base64Coder(const QString& name) : Coder(name) {
    pRestTalker = new RestTalker(this);
    connect(pRestTalker, &RestTalker::replyReceived, this, &Base64Coder::handleRestResponse);
}

QString Base64Coder::encode(const QString& input) {
    QString urlstring = encodeUrlString(input);

    QEventLoop loop;
    connect(pRestTalker, &RestTalker::replyReceived, &loop, &QEventLoop::quit);
    pRestTalker->tryRest(urlstring);
    loop.exec();
    result = parseResponse(pRestTalker->getResponse());
    return result;
}

QString Base64Coder::decode(const QString& input) {
    // Implement Base64 decoding logic here if needed

//    return input;
    // Decode the Base64-encoded input
    QByteArray encodedData = QByteArray::fromBase64(input.toUtf8());

    // Convert the decoded data back to a QString
    QString decodedString = QString::fromUtf8(encodedData);

    return decodedString;
}

QString Base64Coder::getName() const {
    return Coder::getName();
}

QString Base64Coder::encodeUrlString(const QString& input) {
    QString encodedInput = QUrl::toPercentEncoding(input);
    return "https://networkcalc.com/api/encoder/" + encodedInput + "?encoding=base64";
}

QString Base64Coder::parseResponse(const QByteArray& response) {
    // Print the response for debugging
    // qDebug() << "Response:" << QString::fromUtf8(response);
    // return QString(response);

    // Parse the JSON response
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);

    if (jsonResponse.isObject()) {
        QJsonObject jsonObject = jsonResponse.object();
        if (jsonObject.contains("encoded") && jsonObject["encoded"].isString()) {
            return jsonObject["encoded"].toString();
        }
    }

    // If parsing or field extraction fails, return an empty string or handle the error as needed
    return QString(); // Empty string to indicate an error
}

void Base64Coder::handleRestResponse(const QByteArray& response) {
    result = parseResponse(response);
    emit requestCompleted();
}
