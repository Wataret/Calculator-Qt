#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_Resault->setText("");
    ui->radioButton_Sum->setChecked(true);
    ui->label_OP1->setText("Слагаемое 1");
    ui->label_OP2->setText("Слагаемое 2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_Sum_clicked()
{
    ui->label_OP1->setText("Слагаемое 1");
    ui->label_OP2->setText("Слагаемое 2");
    ui->label_OP2->show();
    ui->lineEdit_OP2->show();
    ui->pushButton_Resault->setText("Сумма");
}

void MainWindow::on_radioButton_Sub_clicked()
{
    ui->label_OP1->setText("Уменьшаемое");
    ui->label_OP2->setText("Вычитаемое");
    ui->label_OP2->show();
    ui->lineEdit_OP2->show();
    ui->pushButton_Resault->setText("Разность");
}

void MainWindow::on_radioButton_Mul_clicked()
{
    ui->label_OP1->setText("Множитель 1");
    ui->label_OP2->setText("Множитель 2");
    ui->label_OP2->show();
    ui->lineEdit_OP2->show();
    ui->pushButton_Resault->setText("Произведение");
}

void MainWindow::on_radioButton_Div_clicked()
{
    ui->label_OP1->setText("Делимое");
    ui->label_OP2->setText("Делитель");
    ui->label_OP2->show();
    ui->lineEdit_OP2->show();
    ui->pushButton_Resault->setText("Частное");
}

void MainWindow::on_radioButton_Sqrt_clicked()
{
    ui->label_OP1->setText("Число");
    ui->label_OP2->hide();
    ui->lineEdit_OP2->hide();
    ui->pushButton_Resault->setText("Корень");
}

void MainWindow::on_pushButton_Resault_clicked()
{
    QString str1,str2;

    str1.clear();
    str1.append(ui->lineEdit_OP1->text());
    str2.clear();
    str2.append(ui->lineEdit_OP2->text());

    long double oper1,oper2;
    bool ok;
    oper1=str1.toDouble(&ok);
    if (ok)
    {
        oper2=str2.toDouble(&ok);
        if (ok)
        {
            //Операции
            double result;
            if (ui->radioButton_Sum->isChecked())
                result=oper1+oper2;

            if (ui->radioButton_Sub->isChecked())
                result=oper1-oper2;

            if (ui->radioButton_Mul->isChecked())
                result=oper1*oper2;

            if (ui->radioButton_Sqrt->isChecked())
                result=sqrt(oper1);

            if(oper2 != 0)
            {
                if (ui->radioButton_Div->isChecked())
                    result=oper1/oper2;
            }

            str1.setNum(result);

            //Проверка на деление на 0

            if (!(ui->radioButton_Div->isChecked() && oper2 == 0))
                ui->label_Resault->setText(str1);
            else
                ui->label_Resault->setText("На ноль делить нельзя");

            //Огранечение выводимых данных
            if(result > std::numeric_limits<qreal>::max())
            {
                ui->label_Resault->setText("Превышено максимальное возможное значение");
            }
            if(result < -std::numeric_limits<qreal>::max())
            {
                ui->label_Resault->setText("Пренижено минимально возможное значение");
            }

            //Проверка отрицательного корня
            if(result != result)
            {
                ui->label_Resault->setText("Корень из отрицательного числа не существует");
            }



        }
        else
        {
            // Проверка корректного значения oper2
            if (ui->radioButton_Sum->isChecked())
                ui->label_Resault->setText("Неверное значение слагаемого 2");

            if (ui->radioButton_Sub->isChecked())
                ui->label_Resault->setText("Неверное значение вычитаемого");

            if (ui->radioButton_Mul->isChecked())
                ui->label_Resault->setText("Неверное значение множителя");

            if (ui->radioButton_Div->isChecked())
                ui->label_Resault->setText("Неверное значение делителя");
        }

    }
    else
    {
        // Проверка корректного значения oper1
        if (ui->radioButton_Sum->isChecked())
            ui->label_Resault->setText("Неверное значение слагаемого 1");

        if (ui->radioButton_Sub->isChecked())
            ui->label_Resault->setText("Неверное значение уменьшаемого");

        if (ui->radioButton_Mul->isChecked())
            ui->label_Resault->setText("Неверное значение множиемого");

        if (ui->radioButton_Div->isChecked())
            ui->label_Resault->setText("Неверное значение делимого");
    }

}

