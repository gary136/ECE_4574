#include "compositecoder.h"

CompositeCoder::CompositeCoder(const QString& name) : Coder(name) {
}

void CompositeCoder::addCoder(Coder* coder) {
    coders.push_back(coder);
}

QString CompositeCoder::encode(const QString& input) {
    QString result = input;
    for (Coder* coder : coders) {
        result = coder->encode(result);
    }
    return result;
}

QString CompositeCoder::decode(const QString& input) {
    QString result = input;
    for (auto it = coders.rbegin(); it != coders.rend(); ++it) {
        result = (*it)->decode(result);
    }
    return result;
}

CompositeCoder::~CompositeCoder() {
    for (Coder* coder : coders) {
        delete coder;
    }
}

QString CompositeCoder::getName() const {
    return Coder::getName();
}
