#include "coderfactory.h"

Coder* CoderFactory::createCoder(const QString& coderType) {
//    if (coderType == "Base64") {
//        return new Base64Coder();
//    } else if (coderType == "Flip") {
    if (coderType == "Flip") {
        return new FlipCoder();
    } else if (coderType == "InvertCase") {
        return new InvertCaseCoder();
    } else if (coderType == "OTP") {
        return new OTPCoder();
    } else {
        // Return a default coder or handle the case for unknown coderType
        return nullptr;
    }
}
