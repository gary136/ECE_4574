#include "otpcoder.h"

OTPCoder::OTPCoder(int pad0, int pad1, int pad2, int pad3, int pad4, int pad5, int pad6, int pad7, int pad8, int pad9, int pad10, int pad11, int pad12, int pad13, int pad14, int pad15, int pad16) {
    // Initialize your OTP pad with prime numbers or the default values
    pad[0] = pad0;
    pad[1] = pad1;
    pad[2] = pad2;
    pad[3] = pad3;
    pad[4] = pad4;
    pad[5] = pad5;
    pad[6] = pad6;
    pad[7] = pad7;
    pad[8] = pad8;
    pad[9] = pad9;
    pad[10] = pad10;
    pad[11] = pad11;
    pad[12] = pad12;
    pad[13] = pad13;
    pad[14] = pad14;
    pad[15] = pad15;
    pad[16] = pad16;
}

QString OTPCoder::encode(const QString& input) {
    QString encoded;
    int padIndex = 0;

    // Calculate the size of the pad array
    int padSize = sizeof(pad) / sizeof(pad[0]);

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad[padIndex];
            padIndex = (padIndex + 1) % padSize;  // Ensure padIndex is within the valid range

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

    // Calculate the size of the pad array
    int padSize = sizeof(pad) / sizeof(pad[0]);

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad[padIndex];
            padIndex = (padIndex + 1) % padSize;  // Ensure padIndex is within the valid range

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

