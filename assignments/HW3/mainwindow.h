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

    // initiate an otpcoder

private slots:
    void on_processButton_clicked();

    void on_newOPTButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
