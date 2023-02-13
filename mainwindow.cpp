#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->But_0, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_1, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_2, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_3, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_4, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_5, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_6, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_7, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_8, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_9, SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->But_PlusMinus, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->But_Percent, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->But_Divide, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->But_multi, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->But_Plus, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->But_Minus, SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->But_Plus->setCheckable(true);
    ui->But_Minus->setCheckable(true);
    ui->But_multi->setCheckable(true);
    ui->But_Divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString label_number;

    if (ui->result_show->text().contains(".") && button->text() == "0"){
        label_number = ui->result_show->text() + button->text();
    } else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        label_number = QString::number(all_numbers, 'g',15);
    }
    ui->result_show->setText(label_number);
}


void MainWindow::on_But_Dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString label_number;

    if(button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        label_number = QString::number(all_numbers, 'g',15);

        ui->result_show->setText(label_number);
    } else if(button->text() == "%") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= 0.01;
        label_number = QString::number(all_numbers, 'g',15);

        ui->result_show->setText(label_number);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_ButAC_clicked()
{
    ui->But_Plus->setChecked(false);
    ui->But_Minus->setChecked(false);
    ui->But_Divide->setChecked(false);
    ui->But_multi->setChecked(false);

    ui->result_show->setText("0");
}


void MainWindow::on_ButRavno_clicked()
{
    double labelNumber, num_second;
    QString label_number;

    num_second = ui->result_show->text().toDouble();

    if (ui->But_Plus->isChecked())
    {
        labelNumber = num_first + num_second;
        label_number = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(label_number);
        ui->But_Plus->setChecked(false);
    }else if (ui->But_Minus->isChecked())
    {
        labelNumber = num_first - num_second;
        label_number = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(label_number);
        ui->But_Plus->setChecked(false);
    } else if (ui->But_Divide->isChecked())
    {
        if (num_second == 0)
            ui->result_show->setText("0");
        else {
            labelNumber = num_first / num_second;
            label_number = QString::number(labelNumber, 'g',15);

            ui->result_show->setText(label_number);
        }
        ui->But_Plus->setChecked(false);
    }else if (ui->But_multi->isChecked())
    {
        labelNumber = num_first * num_second;
        label_number = QString::number(labelNumber, 'g',15);

        ui->result_show->setText(label_number);
        ui->But_Plus->setChecked(false);
    }
}

