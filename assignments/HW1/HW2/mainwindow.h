#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include "../HW1/flipcoder.h"
#include "../HW1/otpcoder.h"
#include "../HW1/invertcasecoder.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void runCoders();
    void regenerateOTP();
    void callBase64WebService(const QString& text);

private:
    Ui::MainWindow *ui;
    OTPCoder* otpCoder;
};

#endif // MAINWINDOW_H
