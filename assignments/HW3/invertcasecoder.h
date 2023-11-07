#ifndef INVERTCASECODER_H
#define INVERTCASECODER_H
#include "coder.h"

#include <QString>

class InvertCaseCoder : public Coder {
public:
    InvertCaseCoder(const QString& name);
    QString encode(const QString& input);
    QString decode(const QString& input);
    QString getName() const;
};

#endif // INVERTCASECODER_H
