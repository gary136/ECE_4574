#ifndef FLIPCODER_H
#define FLIPCODER_H

#include <QString>

class FlipCoder {
public:
    QString encode(const QString& input);
    QString decode(const QString& input);
};

#endif // FLIPCODER_H
