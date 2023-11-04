#include "otpcoder.h"
#include "onetimepad.h"
#include <QDebug>

OTPCoder::OTPCoder() {
//    padSize = 0;
//    initializePad();
//    No need to initialize the pad here; it will be managed by OneTimePad
}

//void OTPCoder::initializePad() {
//    padSize = QRandomGenerator::global()->bounded(16, 33);

//    for (int i = 0; i < padSize; i++) {
//        pad[i] = QRandomGenerator::global()->bounded(0, 127);
//    }
//}

//void OTPCoder::regeneratePad() {
//    initializePad();
//}

//int OTPCoder::getPadSize() {
//    return padSize;
//}

//int OTPCoder::getPadValue(int i) {
//    if (i >= 0 && i < padSize) {
//        return pad[i];
//    }
//    return -1;
//}

QString OTPCoder::encode(const QString& input) {
//    Each character in the string is encoded by adding the corresponding offset to the character’s ASCII code;
//    for example
//    int pad[] = {14, 32, 6, 8, 0, 24, 43, 8, 62, 7, 29}
//    the first character has 14 added to it, the second has 32 added to it, etc.
//    When you reach the end of the pad, go back to the beginning.
//    If the addition results in a value greater than 0x7E,
//    subtract the proper constant to bring it back into the range 0x20 to 0x7E
//    – so 0x70 + 15 = 0x7F should become 0x20, etc.
//    Nonprintable characters should be unchanged by this encoding.

    QString encoded;
    int padIndex = 0;
    OneTimePad& pad = OneTimePad::getInstance(); // Get the Singleton pad instance

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad.getPadValue(padIndex);
            padIndex = (padIndex + 1) % pad.getPadSize();  // Ensure padIndex is within the valid range

            int encodedAscii = ascii + offset;
            while (encodedAscii > 0x7E) {
                encodedAscii -= 0x5E; // Bring it back into the range 0x20 to 0x7E
            }
            encoded += QChar(encodedAscii);
            qDebug() << "Character: " << c << " Encoded as: " << QChar(encodedAscii);
        } else {
            encoded += c;
            qDebug() << "Nonprintable Character: " << c << " Unchanged";
        }
    }
    return encoded;
}

QString OTPCoder::decode(const QString& input) {
    QString decoded;
    int padIndex = 0;
    OneTimePad& pad = OneTimePad::getInstance(); // Get the Singleton pad instance

    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E) {
            int offset = pad.getPadValue(padIndex);
            padIndex = (padIndex + 1) % pad.getPadSize();  // Ensure padIndex is within the valid range

            int decodedAscii = ascii - offset;
            while (decodedAscii < 0x20) {
                decodedAscii += 0x5E; // Bring it back into the range 0x20 to 0x7E
            }
            decoded += QChar(decodedAscii);
//            qDebug() << "Character: " << c << " Decoded as: " << QChar(decodedAscii);
        } else {
            decoded += c;
//            qDebug() << "Nonprintable Character: " << c << " Unchanged";
        }
    }
    return decoded;
}

