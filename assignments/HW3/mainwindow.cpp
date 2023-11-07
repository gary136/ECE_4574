#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "flipcoder.h"
#include "otpcoder.h"
#include "invertcasecoder.h"
#include <iostream>
#include "onetimepad.h"
#include "coderfactory.h"
#include "compositecoder.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    coders.push_back(CoderFactory::createCoder("Flip"));
    coders.push_back(CoderFactory::createCoder("OTP"));
    coders.push_back(CoderFactory::createCoder("InvertCase"));
    coders.push_back(CoderFactory::createCoder("Base64"));
    coders.push_back(CoderFactory::createCoder("Composite"));
    coders.back()->addCoder(CoderFactory::createCoder("Flip"));
    coders.back()->addCoder(CoderFactory::createCoder("OTP"));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::processInput(const std::string& input) {
    QString qInput = QString::fromStdString(input); // Convert std::string to QString

    // Create a QString to hold the concatenated result
    QString result;

    // Append the original input
    result += "<br><b>Input: &lt;" + QString::number(qInput.length()) + "&gt;[" + qInput + "]</b><br>";

    for (Coder* coder : coders) {
        QString coderType = coder->getName();

        // Encode the input using the current coder
        QString encoded = coder->encode(qInput);
        result += "<br>" + coderType + " Encoded: &lt;" + QString::number(encoded.length()) + "&gt;[" + encoded + "]<br>";

        // Decode the encoded input using the same coder
        QString decoded = coder->decode(encoded);
        result += coderType + " Decoded: &lt;" + QString::number(decoded.length()) + "&gt;[" + decoded + "]<br>";
    }

//    // Test FlipCoder
//    Coder* flipCoder = CoderFactory::createCoder("Flip");
//    QString flipped = flipCoder->encode(qInput);
//    result += "<br>Flip Encoded: &lt;" + QString::number(flipped.length()) + "&gt;[" + flipped + "]<br>";
//    QString flippedDecoded = flipCoder->decode(flipped);
//    result += "Flip Decoded: &lt;" + QString::number(flippedDecoded.length()) + "&gt;[" + flippedDecoded + "]<br>";

//    // Test OTPCoder
//    Coder* otpCoder = CoderFactory::createCoder("OTP");
//    QString otpEncoded = otpCoder->encode(qInput);
//    result += "<br>OTP Encoded: &lt;" + QString::number(otpEncoded.length()) + "&gt;[" + otpEncoded + "]<br>";
//    QString otpDecoded = otpCoder->decode(otpEncoded);
//    result += "OTP Decoded: &lt;" + QString::number(otpDecoded.length()) + "&gt;[" + otpDecoded + "]<br>";

//    // Test InvertCaseCoder
//    Coder* invertCaseCoder = CoderFactory::createCoder("InvertCase");
//    QString invertCaseEncoded = invertCaseCoder->encode(qInput);
//    result += "<br>Invert Case Encoded: &lt;" + QString::number(invertCaseEncoded.length()) + "&gt;[" + invertCaseEncoded + "]<br>";
//    QString invertCaseDecoded = invertCaseCoder->decode(invertCaseEncoded);
//    result += "Invert Case Decoded: &lt;" + QString::number(invertCaseDecoded.length()) + "&gt;[" + invertCaseDecoded + "]<br>";

//    // Test Base64Coder
//    Coder* base64Coder(pRESTTalker) = CoderFactory::createCoder("Base64"); // Initialize with your RESTTalker object
//    QString base64Encoded = base64Coder->encode(qInput);
//    result += "<br>Base64 Encoded: &lt;" + QString::number(base64Encoded.length()) + "&gt;[" + base64Encoded + "]<br>";
//    QString base64Decoded = base64Coder->decode(base64Encoded);
//    result += "Base64 Decoded: &lt;" + QString::number(base64Decoded.length()) + "&gt;[" + base64Decoded + "]<br>";

//    Coder* base64Coder = CoderFactory::createCoder("Flip");
//    QString base64Encoded = base64Coder->encode(qInput);
//    result += "<br>Base64 Encoded: &lt;" + QString::number(flipped.length()) + "&gt;[" + flipped + "]<br>";
//    QString base64Decoded = base64Coder->decode(base64Encoded);
//    result += "Base64 Decoded: &lt;" + QString::number(flippedDecoded.length()) + "&gt;[" + flippedDecoded + "]<br>";

//    // Create a CompositeCoder and add the FlipCoder and OTPCoder to it
//    Coder* compositeCoder = CoderFactory::createCoder("Composite");
//    compositeCoder->addCoder(flipCoder);
//    compositeCoder->addCoder(otpCoder);

//    // Test the CompositeCoder
//    QString compositeEncoded = compositeCoder->encode(qInput);
//    result += "<br>Composite Encoded: &lt;" + QString::number(compositeEncoded.length()) + "&gt;[" + compositeEncoded + "]<br>";
//    QString compositeDecoded = compositeCoder->decode(compositeEncoded);
//    result += "Composite Decoded: &lt;" + QString::number(compositeDecoded.length()) + "&gt;[" + compositeDecoded + "]<br>";

    return result;
}


void MainWindow::on_processButton_clicked()
{
    // Get the text entered in ui->textEdit
    QString inputText = ui->textEdit->toPlainText();

    // Convert the QString to std::string
    std::string inputTextStd = inputText.toStdString();

    // Process the input and get the concatenated result
    QString processedText = processInput(inputTextStd);

    // Display the input text in ui->textBrowser
    ui->textBrowser->setHtml(processedText);
}


void MainWindow::on_newOPTButton_clicked()
{
    // Get the OneTimePad instance
    OneTimePad& pad = OneTimePad::getInstance();
    // Generate new pad values
    pad.regeneratePad();

    // Display the new pad values in ui->optBrowser
    QString padDisplay;
    for (int i = 0; i < pad.getPadSize(); i++) {
        padDisplay += QString::number(pad.getPadValue(i));
        if (i < pad.getPadSize() - 1) {
            padDisplay += ", ";
        }
    }
    ui->optBrowser->setHtml(padDisplay);
}
