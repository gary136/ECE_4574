#ifndef CODERFACTORY_H
#define CODERFACTORY_H

#include "coder.h"
#include "base64coder.h" // Include the necessary coder headers
#include "flipcoder.h"
#include "invertcasecoder.h"
#include "otpcoder.h"

class CoderFactory {
public:
    static Coder* createCoder(const QString& coderType);
};

#endif // CODERFACTORY_H
