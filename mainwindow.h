#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include "dialog.h"
#include "sportowiec.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_Dodaj_clicked();
    void dodajSportowca(QString nazwisko,int wiek,int punkty);

    void on_podium_clicked();



private:
    Ui::MainWindow *ui;
    QList<Sportowiec> listaSportowcow;
    Dialog* okno;
};
#endif // MAINWINDOW_H
