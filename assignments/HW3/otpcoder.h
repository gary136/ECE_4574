#ifndef OTPCODER_H
#define OTPCODER_H
#include "coder.h"

#include <QString>

class OTPCoder : public Coder {
public:
    OTPCoder(const QString& name);
    QString encode(const QString& input);
    QString decode(const QString& input);
    QString getName() const;
//    void regeneratePad();
//    int getPadSize();
//    int getPadValue(int i);

//private:
//    int padSize;
//    int pad[32];
//    void initializePad();
};

#endif // OTPCODER_H
