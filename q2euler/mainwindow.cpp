#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    warning_flag = true;
    setFixedSize(479,222);
    ui->setupUi(this);
    setWindowTitle(tr("四元数欧拉角转换工具"));
    setWindowIcon(QIcon(":/icon/icon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_euler2q_clicked()
{
    double yaw   = ui->lineEdit_y->text().toDouble();
    double pitch = ui->lineEdit_p->text().toDouble();
    double roll  = ui->lineEdit_r->text().toDouble();
    cal.seteuler(yaw,pitch,roll);
    cal.convert2q();
    ui->lineEdit_x->setText(QString::number(cal.q.x,'f',10));
    ui->lineEdit_y_2->setText(QString::number(cal.q.y,'f',10));
    ui->lineEdit_z->setText(QString::number(cal.q.z,'f',10));
    ui->lineEdit_w->setText(QString::number(cal.q.w,'f',10));
}



void MainWindow::on_pushButton_clicked()
{
    double x = ui->lineEdit_x->text().toDouble();
    double y = ui->lineEdit_y_2->text().toDouble();
    double z = ui->lineEdit_z->text().toDouble();
    double w = ui->lineEdit_w->text().toDouble();
    bool q_real = !cal.setq(x,y,z,w);
    if(q_real){
        ui->lineEdit_x->setText(QString::number(cal.q.x,'f',10));
        ui->lineEdit_y_2->setText(QString::number(cal.q.y,'f',10));
        ui->lineEdit_z->setText(QString::number(cal.q.z,'f',10));
        ui->lineEdit_w->setText(QString::number(cal.q.w,'f',10));
    }
    cal.convert2euler();
    ui->lineEdit_p->setText(QString::number(cal.angle.pitch,'f'));
    ui->lineEdit_y->setText(QString::number(cal.angle.yaw,'f'));
    ui->lineEdit_r->setText(QString::number(cal.angle.roll,'f'));
    if(warning_flag && q_real){
       QMessageBox warningbox;
       warningbox.setWindowTitle(tr("四元数未归一化！"));
       warningbox.setIcon(QMessageBox::Warning);
       warningbox.setText(tr("已将四元数归一化处理"));
       warningbox.addButton(tr("确定(&Y)"),QMessageBox::YesRole);
       QPushButton *close = warningbox.addButton(tr("不再显示"),QMessageBox::RejectRole);
       warningbox.exec();
       if(warningbox.clickedButton() == close){
           warning_flag = false;
       }
    }
}
