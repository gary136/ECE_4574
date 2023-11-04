#include "otpcoder.h"

OTPCoder::OTPCoder() {
    // Initialize your OTP pad with prime numbers
    pad[0] = 17;
    pad[1] = 29;
    pad[2] = 5;
    pad[3] = 12;
    pad[4] = 6;
    pad[5] = 22;
    pad[6] = 11;
    pad[7] = 30;
    pad[8] = 8;
    pad[9] = 18;
    pad[10] = 15;
}

QString OTPCoder::encode(const QString& input) {
    QString encoded;
    int padIndex = 0;

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad[padIndex];
            padIndex = (padIndex + 1) % 11;

            int encodedAscii = ascii + offset;
            if (encodedAscii > 0x7E) {
                encodedAscii -= 0x5F; // Bring it back into the range 0x20 to 0x7E
            }
            encoded += QChar(encodedAscii);
        } else {
            encoded += c;
        }
    }
    return encoded;
}

QString OTPCoder::decode(const QString& input) {
    QString decoded;
    int padIndex = 0;

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad[padIndex];
            padIndex = (padIndex + 1) % 11;

            int decodedAscii = ascii - offset;
            if (decodedAscii < 0x20) {
                decodedAscii += 0x5F; // Bring it back into the range 0x20 to 0x7E
            }
            decoded += QChar(decodedAscii);
        } else {
            decoded += c;
        }
    }
    return decoded;
}
