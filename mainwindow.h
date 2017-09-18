#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtWidgets/QLabel>
#include "httprequestworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBoxRefreshTime_currentIndexChanged(int index);
    void on_buttonRefresh_clicked();
    void with_autoRefreshTime_timesUp();
    void handle_result(HttpRequestWorker *worker);

private:
    Ui::MainWindow *ui;
    int autoRefreshTime;
    QString url_str;
    QTimer *refreshTimer;
    HttpRequestWorker *worker;
    QList<QByteArray> seatStatus;
    QList<QLabel*> seatIco_F4;
    QList<int> seatStatus_F4;
    QList<QLabel*> seatIco_F3;
    QList<int> seatStatus_F3;
    QList<QLabel*> seatIco_Sun;
    QList<int> seatStatus_Sun;
    void changeSeatStatus(QLabel *seatLabel, int status);
};

#endif // MAINWINDOW_H
