#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flipcoder.h"
#include "otpcoder.h"
#include "invertcasecoder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Declare the processInput function
    QString processInput(const std::string& input);

    static int pad0;
    static int pad1;
    static int pad2;
    static int pad3;
    static int pad4;
    static int pad5;
    static int pad6;
    static int pad7;
    static int pad8;
    static int pad9;
    static int pad10;
    static int pad11;
    static int pad12;
    static int pad13;
    static int pad14;
    static int pad15;
    static int pad16;

private slots:
    void on_processButton_clicked();

    void on_newOPTButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
