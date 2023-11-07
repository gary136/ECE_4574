#ifndef BASE64CODER_H
#define BASE64CODER_H

#include "coder.h"
#include "resttalker.h"
#include <QObject>

class Base64Coder : public Coder {
    Q_OBJECT
public:
    Base64Coder(const QString& name);
    QString encode(const QString& input);
    QString decode(const QString& input);
    QString getName() const;

private:
    RestTalker* pRestTalker; // Add a pointer to the RESTTalker
    QString encodeUrlString(const QString& input);
    QString parseResponse(const QByteArray& response);
    QString result;

private slots:
    void handleRestResponse(const QByteArray& response);

signals:
    void requestCompleted();
};

#endif // BASE64CODER_H
