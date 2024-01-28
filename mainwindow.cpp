#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap zdjecie("M:/Mariusz Zywar/Ja/Chorwacja 2021/jezyk.jpg");
    ui->label->setPixmap(zdjecie.scaled(400,400,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dodajSportowca(QString nazwisko,int wiek,int punkty)
{
    listaSportowcow.append(Sportowiec(nazwisko,wiek,punkty));

    int rowPosition = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowPosition);
    ui->tableWidget->setItem(rowPosition, 0, new QTableWidgetItem(nazwisko));
    ui->tableWidget->setItem(rowPosition, 1, new QTableWidgetItem(QString::number(wiek)));
    ui->tableWidget->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(punkty)));
    ui->tableWidget->sortItems(2, Qt::DescendingOrder);

}

void MainWindow::on_Dodaj_clicked()
{
    Dialog* Formularz = new Dialog(this);
    Formularz->show();

    connect(Formularz, SIGNAL(dodajSportowca(QString,int,int)), this, SLOT(dodajSportowca(QString,int,int)));
}

void MainWindow::on_podium_clicked()
{
    ui->Podium->setRowCount(0);
    int size=listaSportowcow.size();
    for(int i=0;i<size;i++)
    {
        int rowPosition =ui->Podium->rowCount();
        ui->Podium->insertRow(rowPosition);
        ui->Podium->setItem(rowPosition, 0, new QTableWidgetItem(listaSportowcow[i].getNazwisko()));
        ui->Podium->setItem(rowPosition, 1, new QTableWidgetItem(QString::number(listaSportowcow[i].getWiek())));
        ui->Podium->setItem(rowPosition, 2, new QTableWidgetItem(QString::number(listaSportowcow[i].getPunkty())));
        ui->Podium->sortItems(2, Qt::DescendingOrder);
    }
    while (ui->Podium->rowCount()>3) {
        ui->Podium->removeRow(ui->Podium->rowCount()-1);
    }

}




