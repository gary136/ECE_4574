#ifndef FLIPCODER_H
#define FLIPCODER_H
#include "coder.h"

#include <QString>

class FlipCoder : public Coder {
public:
    FlipCoder(const QString& name); // Constructor with a name parameter
    QString encode(const QString& input);
    QString decode(const QString& input);
    QString getName() const;
};

#endif // FLIPCODER_H
