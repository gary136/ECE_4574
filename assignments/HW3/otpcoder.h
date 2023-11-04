#ifndef OTPCODER_H
#define OTPCODER_H
#include "coder.h"

#include <QString>

class OTPCoder : public Coder {
public:
    OTPCoder();
    QString encode(const QString& input);
    QString decode(const QString& input);
//    void regeneratePad();
//    int getPadSize();
//    int getPadValue(int i);

//private:
//    int padSize;
//    int pad[32];
//    void initializePad();
};

#endif // OTPCODER_H
