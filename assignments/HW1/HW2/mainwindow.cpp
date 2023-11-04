#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the buttons to slots
    connect(ui->runCodersButton, SIGNAL(clicked()), this, SLOT(runCoders()));
    connect(ui->regenerateOTPButton, SIGNAL(clicked()), this, SLOT(regenerateOTP()));

    // Set default text in QTextEdit
    ui->inputTextEdit->setPlainText("THESE are the times that try men's souls.");

    // Initialize OTPCoder and display the initial OTP pad
    otpCoder = new OTPCoder();
    regenerateOTP();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runCoders() {
    // Get the input text from QTextEdit
    QString inputText = ui->inputTextEdit->toPlainText();

    // Encode and decode using FlipCoder
    FlipCoder flipCoder;
    QString flipped = flipCoder.encode(inputText);
    QString flippedDecoded = flipCoder.decode(flipped);

    // Encode and decode using OTPCoder
    QString otpEncoded = otpCoder->encode(flippedDecoded);
    QString otpDecoded = otpCoder->decode(otpEncoded);

    // Encode and decode using InvertCaseCoder
    InvertCaseCoder invertCoder;
    QString inverted = invertCoder.encode(otpDecoded);
    QString invertedDecoded = invertCoder.decode(inverted);

    // Call the Base64 web service for encoding
    callBase64WebService(invertedDecoded);
}

void MainWindow::regenerateOTP() {
    // Generate a new OTP pad with random values
    otpCoder->regenerateOTP();

    // Display the current OTP pad
    ui->otpPadLabel->setText("Current OTP Pad: " + otpCoder->getCurrentOTP());
}

void MainWindow::callBase64WebService(const QString& text) {
    // Create a QNetworkAccessManager
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // Create the request URL
    QUrl url("https://networkcalc.com/api/encoder/" + text);
    QUrlQuery query;
    query.addQueryItem("encoding", "base64");
    url.setQuery(query);

    // Send the GET request
    QNetworkReply *reply = manager->get(QNetworkRequest(url));

    // Connect slots for handling the response
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Parse and display the response
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QString base64Encoded = jsonResponse.object()["encoded"].toString();
            ui->resultsTextBrowser->setPlainText("Input (in bold):\n<b>" + text + "</b>\n\nBase64 Encoded:\n" + base64Encoded);
        } else {
            // Handle the error
            ui->resultsTextBrowser->setPlainText("Error: " + reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}
