#include "mainwindow.h"
#include <QCoreApplication>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    // Test with the first string
    QString input1 = "In a hole in the ground there lived a Hobbit 1234567890 ~1@#$%^＆*0+=\"";
    mainWindow.ui->inputTextEdit->setPlainText(input1);
    mainWindow.runCoders();

    // Output a separator
    std::cout << "\n";

    // Test with the second string
    QString input2 = "England expects every man will do his duty";
    mainWindow.ui->inputTextEdit->setPlainText(input2);
    mainWindow.regenerateOTP(); // Regenerate OTP for the second test
    mainWindow.runCoders();
    return a.exec();
}
