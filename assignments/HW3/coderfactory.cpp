#include "coderfactory.h" // Include the necessary header file for CoderFactory
#include "CompositeCoder.h" // Include the header file for CompositeCoder
#include "FlipCoder.h"     // Include the header file for FlipCoder
#include "InvertCaseCoder.h" // Include the header file for InvertCaseCoder
#include "OTPCoder.h"      // Include the header file for OTPCoder
#include "base64Coder.h"

Coder* CoderFactory::createCoder(const QString& name) {
    if (name == "Base64") {
        return new Base64Coder(name);
    } else if (name == "Flip") {
//    if (name == "Flip") {
        return new FlipCoder(name);
    } else if (name == "InvertCase") {
        return new InvertCaseCoder(name);
    } else if (name == "OTP") {
        return new OTPCoder(name);
    } else if (name == "Composite") {
        return new CompositeCoder(name);
    } else {
        // Return a default coder or handle the case for unknown coderType
        return nullptr;
    }
}
