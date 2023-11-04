#include "onetimepad.h"

OneTimePad::OneTimePad() {
    padSize = 0;
    initializePad();
}

OneTimePad& OneTimePad::getInstance() {
    static OneTimePad instance; // This ensures a single instance is created
    return instance;
}

void OneTimePad::initializePad() {
    padSize = QRandomGenerator::global()->bounded(16, 33);

    for (int i = 0; i < padSize; i++) {
        pad[i] = QRandomGenerator::global()->bounded(0, 127);
    }
}

void OneTimePad::regeneratePad() {
    initializePad();
}

int OneTimePad::getPadSize() {
    return padSize;
}

int OneTimePad::getPadValue(int i) {
    if (i >= 0 && i < padSize) {
        return pad[i];
    }
    return -1;
}
