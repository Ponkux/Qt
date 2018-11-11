#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "convert.h"

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
    void on_btn_euler2q_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    convert cal;
    bool warning_flag;
};

#endif // MAINWINDOW_H
