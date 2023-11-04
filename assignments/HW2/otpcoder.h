#ifndef OTPCODER_H
#define OTPCODER_H

#include <QString>

class OTPCoder {
public:
    OTPCoder(int pad0, int pad1, int pad2, int pad3, int pad4, int pad5, int pad6, int pad7, int pad8, int pad9, int pad10, int pad11, int pad12, int pad13, int pad14, int pad15, int pad16);
    QString encode(const QString& input);
    QString decode(const QString& input);

private:
    int pad[17]; // Your pad values go here
};

#endif // OTPCODER_H
