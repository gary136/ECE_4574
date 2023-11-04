#ifndef ONETIMEPAD_H
#define ONETIMEPAD_H

#include <QRandomGenerator>

class OneTimePad {
public:
    static OneTimePad& getInstance(); // Singleton instance accessor
    void regeneratePad();
    int getPadSize();
    int getPadValue(int i);

private:
    OneTimePad(); // Private constructor to prevent direct instantiation
    OneTimePad(const OneTimePad&) = delete; // Disable copy constructor
    OneTimePad& operator=(const OneTimePad&) = delete; // Disable copy assignment
    int padSize;
    int pad[32];
    void initializePad();
};

#endif // ONETIMEPAD_H
