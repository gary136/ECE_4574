#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "flipcoder.h"
#include "otpcoder.h"
#include "invertcasecoder.h"
#include <iostream>

int MainWindow::pad0 = 52;
int MainWindow::pad1 = 27;
int MainWindow::pad2 = 75;
int MainWindow::pad3 = 103;
int MainWindow::pad4 = 94;
int MainWindow::pad5 = 17;
int MainWindow::pad6 = 11;
int MainWindow::pad7 = 89;
int MainWindow::pad8 = 40;
int MainWindow::pad9 = 6;
int MainWindow::pad10 = 78;
int MainWindow::pad11 = 99;
int MainWindow::pad12 = 15;
int MainWindow::pad13 = 24;
int MainWindow::pad14 = 44;
int MainWindow::pad15 = 13;
int MainWindow::pad16 = 48;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

    // Test FlipCoder
    FlipCoder flipCoder;
    QString flipped = flipCoder.encode(qInput);
    result += "<br>Flip Encoded: &lt;" + QString::number(flipped.length()) + "&gt;[" + flipped + "]<br>";

    QString flippedDecoded = flipCoder.decode(flipped);
    result += "Flip Decoded: &lt;" + QString::number(flippedDecoded.length()) + "&gt;[" + flippedDecoded + "]<br>";

    // Test OTPCoder
    OTPCoder otpCoder(pad0, pad1, pad2, pad3, pad4, pad5, pad6, pad7, pad8, pad9, pad10, pad11, pad12, pad13, pad14, pad15, pad16);
    QString otpEncoded = otpCoder.encode(qInput);
    result += "<br>OTP Encoded: &lt;" + QString::number(otpEncoded.length()) + "&gt;[" + otpEncoded + "]<br>";

    QString otpDecoded = otpCoder.decode(otpEncoded);
    result += "OTP Decoded: &lt;" + QString::number(otpDecoded.length()) + "&gt;[" + otpDecoded + "]<br>";

    // Test InvertCaseCoder
    InvertCaseCoder invertCaseCoder;
    QString invertCaseEncoded = invertCaseCoder.encode(qInput);
    result += "<br>Invert Case Encoded: &lt;" + QString::number(invertCaseEncoded.length()) + "&gt;[" + invertCaseEncoded + "]<br>";

    QString invertCaseDecoded = invertCaseCoder.decode(invertCaseEncoded);
    result += "Invert Case Decoded: &lt;" + QString::number(invertCaseDecoded.length()) + "&gt;[" + invertCaseDecoded + "]<br>";

    // Test Base64Coder
//    Base64Coder base64Coder(pRESTTalker); // Initialize with your RESTTalker object
//    QString base64Encoded = base64Coder.encode(qInput);
//    result += "<br>Base64 Encoded: &lt;" + QString::number(base64Encoded.length()) + "&gt;[" + base64Encoded + "]<br>";

//    QString base64Decoded = base64Coder.decode(base64Encoded);
//    result += "Base64 Decoded: &lt;" + QString::number(base64Decoded.length()) + "&gt;[" + base64Decoded + "]<br>";

//    Base64Coder base64Coder(pRESTTalker); // Initialize with your RESTTalker object
//    QString base64Encoded = base64Coder.encode(qInput);
    result += "<br>Base64 Encoded: &lt;" + QString::number(flipped.length()) + "&gt;[" + flipped + "]<br>";

//    QString base64Decoded = base64Coder.decode(base64Encoded);
    result += "Base64 Decoded: &lt;" + QString::number(flippedDecoded.length()) + "&gt;[" + flippedDecoded + "]<br>";

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
    // Generate new pad values
    pad0 = arc4random_uniform(127);
    pad1 = arc4random_uniform(127);
    pad2 = arc4random_uniform(127);
    pad3 = arc4random_uniform(127);
    pad4 = arc4random_uniform(127);
    pad5 = arc4random_uniform(127);
    pad6 = arc4random_uniform(127);
    pad7 = arc4random_uniform(127);
    pad8 = arc4random_uniform(127);
    pad9 = arc4random_uniform(127);
    pad10 = arc4random_uniform(127);
    pad11 = arc4random_uniform(127);
    pad12 = arc4random_uniform(127);
    pad13 = arc4random_uniform(127);
    pad14 = arc4random_uniform(127);
    pad15 = arc4random_uniform(127);
    pad16 = arc4random_uniform(127);

    // Display the new pad values in ui->optBrowser
    QString padDisplay = QString::number(pad0) + ", " + QString::number(pad1) + ", " + QString::number(pad2) + ", " + QString::number(pad3) + ", " +
                         QString::number(pad4) + ", " + QString::number(pad5) + ", " + QString::number(pad6) + ", " + QString::number(pad7) + ", " +
                         QString::number(pad8) + ", " + QString::number(pad9) + ", " + QString::number(pad10) + ", " + QString::number(pad11) + ", " +
                         QString::number(pad12) + ", " + QString::number(pad13) + ", " + QString::number(pad14) + ", " + QString::number(pad15) + ", " +
                         QString::number(pad16);
    ui->optBrowser->setHtml(padDisplay);
}
