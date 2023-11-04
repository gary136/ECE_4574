#include <iostream>
#include <QString>
#include <string> 
#include "flipcoder.h"
#include "otpcoder.h"
#include "invertcasecoder.h"

void processInput(const std::string& input) {
    QString qInput = QString::fromStdString(input); // Convert std::string to QString

    // Display the original input
    std::cout << "Input: <" << qInput.length() << ">[" << qInput.toStdString() << "]\n";

    // Test FlipCoder
    FlipCoder flipCoder;
    QString flipped = flipCoder.encode(qInput);
    std::cout << "Flip Encoded: <" << flipped.length() << ">[" << flipped.toStdString() << "]\n";

    QString flippedDecoded = flipCoder.decode(flipped);
    std::cout << "Flip Decoded: <" << flippedDecoded.length() << ">[" << flippedDecoded.toStdString() << "]\n";

    // Test OTPCoder
    OTPCoder otpCoder;
    QString otpEncoded = otpCoder.encode(qInput);
    std::cout << "OTP Encoded: <" << otpEncoded.length() << ">[" << otpEncoded.toStdString() << "]\n";

    QString otpDecoded = otpCoder.decode(otpEncoded);
    std::cout << "OTP Decoded: <" << otpDecoded.length() << ">[" << otpDecoded.toStdString() << "]\n";

    // Test InvertCaseCoder
    InvertCaseCoder invertCaseCoder;
    QString invertCaseEncoded = invertCaseCoder.encode(qInput);
    std::cout << "Invert Case Encoded: <" << invertCaseEncoded.length() << ">[" << invertCaseEncoded.toStdString() << "]\n";

    QString invertCaseDecoded = invertCaseCoder.decode(invertCaseEncoded);
    std::cout << "Invert Case Decoded: <" << invertCaseDecoded.length() << ">[" << invertCaseDecoded.toStdString() << "]\n";
}


int main() {
    std::string input;
    std::cout << "Enter a text string (up to 1000 characters): ";
    std::getline(std::cin, input); // Read input as a std::string
    processInput(input);
    std::cout << "\n";
    input = "Hung-Ting Lee";
    processInput(input);
    std::cout << "\n";
    input = "In a hole in the ground there lived a hobbit. 1234567890~ !@#$%^&*()";
    processInput(input);
    std::cout << "\n";
    input = "Virginia Tech is a public university and one of Virginia's two land-grant institutions";
    processInput(input);

    return 0;
}
