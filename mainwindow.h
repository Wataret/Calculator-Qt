#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_radioButton_Sum_clicked();

    void on_pushButton_Resault_clicked();

    void on_radioButton_Sub_clicked();

    void on_radioButton_Mul_clicked();

    void on_radioButton_Div_clicked();

    void on_radioButton_Sqrt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
