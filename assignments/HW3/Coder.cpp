#include "coder.h"

Coder::Coder(const QString& name) : name(name) {
    // Constructor to initialize the 'name' attribute
}

QString Coder::getName() const {
    return name;
}
