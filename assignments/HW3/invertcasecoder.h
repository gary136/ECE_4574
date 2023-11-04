#ifndef INVERTCASECODER_H
#define INVERTCASECODER_H
#include "coder.h"

#include <QString>

class InvertCaseCoder : public Coder {
public:
    QString encode(const QString& input);
    QString decode(const QString& input);
};

#endif // INVERTCASECODER_H
