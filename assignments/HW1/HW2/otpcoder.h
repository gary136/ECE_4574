#ifndef OTPCODER_H
#define OTPCODER_H

#include <QString>

class OTPCoder {
public:
    OTPCoder();
    QString encode(const QString& input);
    QString decode(const QString& input);

private:
    int pad[11]; // Your pad values go here
};

#endif // OTPCODER_H
