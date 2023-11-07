#include "invertcasecoder.h"

InvertCaseCoder::InvertCaseCoder(const QString& name) : Coder(name) {
}

QString InvertCaseCoder::encode(const QString& input) {
    QString encoded;
    for (const QChar& c : input) {
        if (c.isUpper()) {
            encoded += c.toLower();
        } else if (c.isLower()) {
            encoded += c.toUpper();
        } else {
            encoded += c;
        }
    }
    return encoded;
}

QString InvertCaseCoder::decode(const QString& input) {
    return encode(input); // Decoding is the same as encoding for invert case
}

QString InvertCaseCoder::getName() const {
    return Coder::getName();
}
