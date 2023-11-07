#include "flipcoder.h"

FlipCoder::FlipCoder(const QString& name) : Coder(name) {
}

QString FlipCoder::encode(const QString& input) {
    QString encoded;
    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E && c != ' ') {
            encoded += QChar(0x7F - (ascii - 0x20));
        } else {
            encoded += c;
        }
    }
    return encoded;
}

QString FlipCoder::decode(const QString& input) {
    QString decoded;
    for (const QChar& c : input) {
        ushort ascii = c.unicode();
        if (ascii >= 0x20 && ascii <= 0x7E && c != ' ') {
            decoded += QChar(0x7F - (ascii - 0x20));
        } else {
            decoded += c;
        }
    }
    return decoded;
}

QString FlipCoder::getName() const {
    return Coder::getName();
}
