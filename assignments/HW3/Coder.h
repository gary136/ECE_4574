#ifndef CODER_H
#define CODER_H

#include <QString>

class Coder {
public:
    virtual QString encode(const QString& input) = 0;
    virtual QString decode(const QString& input) = 0;
    virtual ~Coder() {}
};

#endif // CODER_H
