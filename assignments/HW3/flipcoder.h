#ifndef FLIPCODER_H
#define FLIPCODER_H
#include "coder.h"

#include <QString>

class FlipCoder : public Coder {
public:
    QString encode(const QString& input);
    QString decode(const QString& input);
};

#endif // FLIPCODER_H
