#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),refreshTimer(new QTimer),worker(new HttpRequestWorker)
{
    autoRefreshTime = 5000;
    url_str = "https://api.bmob.cn/1/classes/seat";
    connect(refreshTimer,SIGNAL(timeout()),this,SLOT(with_autoRefreshTime_timesUp()));
    connect(worker,SIGNAL(on_execution_finished(HttpRequestWorker*)),this,SLOT(handle_result(HttpRequestWorker*)));

    seatStatus_F4.append(67);
    seatStatus_F4.append(0);
    seatStatus_F4.append(0);
    seatStatus_F4.append(0);
    seatStatus_F4.append(0);

    seatStatus_F3.append(60);
    seatStatus_F3.append(0);
    seatStatus_F3.append(0);
    seatStatus_F3.append(0);
    seatStatus_F3.append(0);

    seatStatus_Sun.append(32);
    seatStatus_Sun.append(0);
    seatStatus_Sun.append(0);
    seatStatus_Sun.append(0);
    seatStatus_Sun.append(0);

    ui->setupUi(this);

    seatIco_F4.append(ui->labelSeat_F4_1);
    seatIco_F4.append(ui->labelSeat_F4_2);
    seatIco_F4.append(ui->labelSeat_F4_3);
    seatIco_F4.append(ui->labelSeat_F4_4);
    seatIco_F4.append(ui->labelSeat_F4_5);
    seatIco_F4.append(ui->labelSeat_F4_6);
    seatIco_F4.append(ui->labelSeat_F4_7);
    seatIco_F4.append(ui->labelSeat_F4_8);
    seatIco_F4.append(ui->labelSeat_F4_9);
    seatIco_F4.append(ui->labelSeat_F4_10);
    seatIco_F4.append(ui->labelSeat_F4_11);
    seatIco_F4.append(ui->labelSeat_F4_12);
    seatIco_F4.append(ui->labelSeat_F4_13);
    seatIco_F4.append(ui->labelSeat_F4_14);
    seatIco_F4.append(ui->labelSeat_F4_15);
    seatIco_F4.append(ui->labelSeat_F4_16);
    seatIco_F4.append(ui->labelSeat_F4_17);
    seatIco_F4.append(ui->labelSeat_F4_18);
    seatIco_F4.append(ui->labelSeat_F4_19);
    seatIco_F4.append(ui->labelSeat_F4_20);
    seatIco_F4.append(ui->labelSeat_F4_21);
    seatIco_F4.append(ui->labelSeat_F4_22);
    seatIco_F4.append(ui->labelSeat_F4_23);
    seatIco_F4.append(ui->labelSeat_F4_24);
    seatIco_F4.append(ui->labelSeat_F4_25);
    seatIco_F4.append(ui->labelSeat_F4_26);
    seatIco_F4.append(ui->labelSeat_F4_27);
    seatIco_F4.append(ui->labelSeat_F4_28);
    seatIco_F4.append(ui->labelSeat_F4_29);
    seatIco_F4.append(ui->labelSeat_F4_30);
    seatIco_F4.append(ui->labelSeat_F4_31);
    seatIco_F4.append(ui->labelSeat_F4_32);
    seatIco_F4.append(ui->labelSeat_F4_33);
    seatIco_F4.append(ui->labelSeat_F4_34);
    seatIco_F4.append(ui->labelSeat_F4_35);
    seatIco_F4.append(ui->labelSeat_F4_36);
    seatIco_F4.append(ui->labelSeat_F4_37);
    seatIco_F4.append(ui->labelSeat_F4_38);
    seatIco_F4.append(ui->labelSeat_F4_39);
    seatIco_F4.append(ui->labelSeat_F4_40);
    seatIco_F4.append(ui->labelSeat_F4_41);
    seatIco_F4.append(ui->labelSeat_F4_42);
    seatIco_F4.append(ui->labelSeat_F4_43);
    seatIco_F4.append(ui->labelSeat_F4_44);
    seatIco_F4.append(ui->labelSeat_F4_45);
    seatIco_F4.append(ui->labelSeat_F4_46);
    seatIco_F4.append(ui->labelSeat_F4_47);
    seatIco_F4.append(ui->labelSeat_F4_48);
    seatIco_F4.append(ui->labelSeat_F4_49);
    seatIco_F4.append(ui->labelSeat_F4_50);
    seatIco_F4.append(ui->labelSeat_F4_51);
    seatIco_F4.append(ui->labelSeat_F4_52);
    seatIco_F4.append(ui->labelSeat_F4_53);
    seatIco_F4.append(ui->labelSeat_F4_54);
    seatIco_F4.append(ui->labelSeat_F4_55);
    seatIco_F4.append(ui->labelSeat_F4_56);
    seatIco_F4.append(ui->labelSeat_F4_57);
    seatIco_F4.append(ui->labelSeat_F4_58);
    seatIco_F4.append(ui->labelSeat_F4_59);
    seatIco_F4.append(ui->labelSeat_F4_60);
    seatIco_F4.append(ui->labelSeat_F4_61);
    seatIco_F4.append(ui->labelSeat_F4_62);
    seatIco_F4.append(ui->labelSeat_F4_63);
    seatIco_F4.append(ui->labelSeat_F4_64);
    seatIco_F4.append(ui->labelSeat_F4_65);
    seatIco_F4.append(ui->labelSeat_F4_66);
    seatIco_F4.append(ui->labelSeat_F4_67);

    seatIco_F3.append(ui->labelSeat_F3_1);
    seatIco_F3.append(ui->labelSeat_F3_2);
    seatIco_F3.append(ui->labelSeat_F3_3);
    seatIco_F3.append(ui->labelSeat_F3_4);
    seatIco_F3.append(ui->labelSeat_F3_5);
    seatIco_F3.append(ui->labelSeat_F3_6);
    seatIco_F3.append(ui->labelSeat_F3_7);
    seatIco_F3.append(ui->labelSeat_F3_8);
    seatIco_F3.append(ui->labelSeat_F3_9);
    seatIco_F3.append(ui->labelSeat_F3_10);
    seatIco_F3.append(ui->labelSeat_F3_11);
    seatIco_F3.append(ui->labelSeat_F3_12);
    seatIco_F3.append(ui->labelSeat_F3_13);
    seatIco_F3.append(ui->labelSeat_F3_14);
    seatIco_F3.append(ui->labelSeat_F3_15);
    seatIco_F3.append(ui->labelSeat_F3_16);
    seatIco_F3.append(ui->labelSeat_F3_17);
    seatIco_F3.append(ui->labelSeat_F3_18);
    seatIco_F3.append(ui->labelSeat_F3_19);
    seatIco_F3.append(ui->labelSeat_F3_20);
    seatIco_F3.append(ui->labelSeat_F3_21);
    seatIco_F3.append(ui->labelSeat_F3_22);
    seatIco_F3.append(ui->labelSeat_F3_23);
    seatIco_F3.append(ui->labelSeat_F3_24);
    seatIco_F3.append(ui->labelSeat_F3_25);
    seatIco_F3.append(ui->labelSeat_F3_26);
    seatIco_F3.append(ui->labelSeat_F3_27);
    seatIco_F3.append(ui->labelSeat_F3_28);
    seatIco_F3.append(ui->labelSeat_F3_29);
    seatIco_F3.append(ui->labelSeat_F3_30);
    seatIco_F3.append(ui->labelSeat_F3_31);
    seatIco_F3.append(ui->labelSeat_F3_32);
    seatIco_F3.append(ui->labelSeat_F3_33);
    seatIco_F3.append(ui->labelSeat_F3_34);
    seatIco_F3.append(ui->labelSeat_F3_35);
    seatIco_F3.append(ui->labelSeat_F3_36);
    seatIco_F3.append(ui->labelSeat_F3_37);
    seatIco_F3.append(ui->labelSeat_F3_38);
    seatIco_F3.append(ui->labelSeat_F3_39);
    seatIco_F3.append(ui->labelSeat_F3_40);
    seatIco_F3.append(ui->labelSeat_F3_41);
    seatIco_F3.append(ui->labelSeat_F3_42);
    seatIco_F3.append(ui->labelSeat_F3_43);
    seatIco_F3.append(ui->labelSeat_F3_44);
    seatIco_F3.append(ui->labelSeat_F3_45);
    seatIco_F3.append(ui->labelSeat_F3_46);
    seatIco_F3.append(ui->labelSeat_F3_47);
    seatIco_F3.append(ui->labelSeat_F3_48);
    seatIco_F3.append(ui->labelSeat_F3_49);
    seatIco_F3.append(ui->labelSeat_F3_50);
    seatIco_F3.append(ui->labelSeat_F3_51);
    seatIco_F3.append(ui->labelSeat_F3_52);
    seatIco_F3.append(ui->labelSeat_F3_53);
    seatIco_F3.append(ui->labelSeat_F3_54);
    seatIco_F3.append(ui->labelSeat_F3_55);
    seatIco_F3.append(ui->labelSeat_F3_56);
    seatIco_F3.append(ui->labelSeat_F3_57);
    seatIco_F3.append(ui->labelSeat_F3_58);
    seatIco_F3.append(ui->labelSeat_F3_59);
    seatIco_F3.append(ui->labelSeat_F3_60);

    seatIco_Sun.append(ui->labelSeat_Sun_1);
    seatIco_Sun.append(ui->labelSeat_Sun_2);
    seatIco_Sun.append(ui->labelSeat_Sun_3);
    seatIco_Sun.append(ui->labelSeat_Sun_4);
    seatIco_Sun.append(ui->labelSeat_Sun_5);
    seatIco_Sun.append(ui->labelSeat_Sun_6);
    seatIco_Sun.append(ui->labelSeat_Sun_7);
    seatIco_Sun.append(ui->labelSeat_Sun_8);
    seatIco_Sun.append(ui->labelSeat_Sun_9);
    seatIco_Sun.append(ui->labelSeat_Sun_10);
    seatIco_Sun.append(ui->labelSeat_Sun_11);
    seatIco_Sun.append(ui->labelSeat_Sun_12);
    seatIco_Sun.append(ui->labelSeat_Sun_13);
    seatIco_Sun.append(ui->labelSeat_Sun_14);
    seatIco_Sun.append(ui->labelSeat_Sun_15);
    seatIco_Sun.append(ui->labelSeat_Sun_16);
    seatIco_Sun.append(ui->labelSeat_Sun_17);
    seatIco_Sun.append(ui->labelSeat_Sun_18);
    seatIco_Sun.append(ui->labelSeat_Sun_19);
    seatIco_Sun.append(ui->labelSeat_Sun_20);
    seatIco_Sun.append(ui->labelSeat_Sun_21);
    seatIco_Sun.append(ui->labelSeat_Sun_22);
    seatIco_Sun.append(ui->labelSeat_Sun_23);
    seatIco_Sun.append(ui->labelSeat_Sun_24);
    seatIco_Sun.append(ui->labelSeat_Sun_25);
    seatIco_Sun.append(ui->labelSeat_Sun_26);
    seatIco_Sun.append(ui->labelSeat_Sun_27);
    seatIco_Sun.append(ui->labelSeat_Sun_28);
    seatIco_Sun.append(ui->labelSeat_Sun_29);
    seatIco_Sun.append(ui->labelSeat_Sun_30);
    seatIco_Sun.append(ui->labelSeat_Sun_31);
    seatIco_Sun.append(ui->labelSeat_Sun_32);

    refreshTimer->start(autoRefreshTime);
}

MainWindow::~MainWindow()
{
    refreshTimer->stop();
    delete ui;
}

void MainWindow::on_comboBoxRefreshTime_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        autoRefreshTime = 5000;
        qDebug() << "刷新时间5s";
        break;
    case 1:
        autoRefreshTime = 10000;
        qDebug() << "刷新时间10s";
        break;
    case 2:
        autoRefreshTime = 30000;
        qDebug() << "刷新时间30s";
        break;
    case 3:
        autoRefreshTime = 60000;
        qDebug() << "刷新时间60s";
        break;
    case 4:
        autoRefreshTime = 300000;
        qDebug() << "刷新时间5min";
        break;
    case 5:
        autoRefreshTime = 600000;
        qDebug() << "刷新时间10min";
        break;
    default:
        autoRefreshTime = 0;
        qDebug() << "手动刷新";
    }
    if (autoRefreshTime)
    {
        refreshTimer->start(autoRefreshTime);
    }
    else
    {
        refreshTimer->stop();
    }
}

void MainWindow::on_buttonRefresh_clicked()
{
    //TODO 网络请求数据从而刷新数据列表
    HttpRequestInput input(url_str, "GET");
    input.add_var("limit","500");
    worker->execute(&input);
    qDebug() << "已刷新";
}

void MainWindow::with_autoRefreshTime_timesUp()
{
    //TODO 网络请求数据从而刷新数据列表
    HttpRequestInput input(url_str, "GET");
    input.add_var("limit","500");
    worker->execute(&input);
    qDebug() << "已自动刷新";
}

void MainWindow::changeSeatStatus(QLabel *seatLabel, int status)
{
    switch (status) {
    case 0:
        seatLabel->setStyleSheet("font: 16pt \"Meiryo UI\";"
                                 "image: url(:/map/resources/available.png);");
        break;
    case 1:
        seatLabel->setStyleSheet("font: 16pt \"Meiryo UI\";"
                                 "image: url(:/map/resources/appointed.png);");
        break;
    case 2:
        seatLabel->setStyleSheet("font: 16pt \"Meiryo UI\";"
                                 "image: url(:/map/resources/occupied.png);");
        break;
    case 3:
        seatLabel->setStyleSheet("font: 16pt \"Meiryo UI\";"
                                 "image: url(:/map/resources/saved.png);");
        break;
    case 4:
        seatLabel->setStyleSheet("font: 16pt \"Meiryo UI\";"
                                 "image: url(:/map/resources/banned.png);");
        break;
    default:
        break;
    }
}

void MainWindow::handle_result(HttpRequestWorker *worker)
{
    QString msg,temp;
    int index1 = 0;
    int index2 = 0;
    if (worker->error_type == QNetworkReply::NoError) {
        // clear the counter first
        for (int i = 0; i < 5; i++)
        {
            seatStatus_F3.replace(i,0);
            seatStatus_F4.replace(i,0);
            seatStatus_Sun.replace(i,0);
        }
        // communication was successful
        seatStatus = worker->response.split('{');
        seatStatus.removeFirst();
        seatStatus.removeFirst();
        for (int i = 0; i < seatStatus.length(); i++)
        {
            msg = seatStatus.at(i);
            index1 = msg.indexOf("\"seatid\":\"");
            index2 = msg.indexOf("\",\"status\"");
            temp = msg.mid(index1+10, index2-index1-10);

            index1 = temp.mid(1).toUInt() - 1;
            switch (temp.at(0).toLatin1()) {
            case 'A':
            case 'a':
                if(index1 < seatIco_F4.length())
                {
                    changeSeatStatus(seatIco_F4.at(index1), msg.mid(index2 + 12, 1).toInt());
                    seatStatus_F4[msg.mid(index2 + 12, 1).toInt()]++;
                }

                break;
            case 'c':
            case 'C':
                if(index1 < seatIco_F3.length())
                {
                    changeSeatStatus(seatIco_F3.at(index1), msg.mid(index2 + 12, 1).toInt());
                    seatStatus_F3[msg.mid(index2 + 12, 1).toInt()]++;
                }

                break;
            case 'b':
            case 'B':
                if(index1 < seatIco_Sun.length())
                {
                    changeSeatStatus(seatIco_Sun.at(index1), msg.mid(index2 + 12, 1).toInt());
                    seatStatus_Sun[msg.mid(index2 + 12, 1).toInt()]++;
                }

                break;
            default:
                continue;
            }
        }
        // Update the number of LCD
        ui->lcdNumber_F4_available->display(seatStatus_F4.at(0));
        ui->lcdNumber_F4_appointed->display(seatStatus_F4.at(1));
        ui->lcdNumber_F4_occupied->display(seatStatus_F4.at(2));
        ui->lcdNumber_F4_saved->display(seatStatus_F4.at(3));
        ui->lcdNumber_F4_banned->display(seatStatus_F4.at(4));

        ui->lcdNumber_F3_available->display(seatStatus_F3.at(0));
        ui->lcdNumber_F3_appointed->display(seatStatus_F3.at(1));
        ui->lcdNumber_F3_occupied->display(seatStatus_F3.at(2));
        ui->lcdNumber_F3_saved->display(seatStatus_F3.at(3));
        ui->lcdNumber_F3_banned->display(seatStatus_F3.at(4));

        ui->lcdNumber_Sun_available->display(seatStatus_Sun.at(0));
        ui->lcdNumber_Sun_appointed->display(seatStatus_Sun.at(1));
        ui->lcdNumber_Sun_occupied->display(seatStatus_Sun.at(2));
        ui->lcdNumber_Sun_saved->display(seatStatus_Sun.at(3));
        ui->lcdNumber_Sun_banned->display(seatStatus_Sun.at(4));
    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
        qDebug() << msg;
    }
    qDebug() << "已刷新";
}
