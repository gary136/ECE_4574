#ifndef INVERTCASECODER_H
#define INVERTCASECODER_H

#include <QString>

class InvertCaseCoder {
public:
    QString encode(const QString& input);
    QString decode(const QString& input);
};

#endif // INVERTCASECODER_H
