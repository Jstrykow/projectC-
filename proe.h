#ifndef PROE_H
#define PROE_H

#include "pc.h"
#include "laptop.h"
#include "laptop_gaming.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QCloseEvent>
#include <QPixmap>


namespace Ui {
class proe;
}

class proe : public QMainWindow
{
    Q_OBJECT

public:
    explicit proe(QWidget *parent = nullptr);

    ~proe();

private slots:

    void on_PCButton_clicked();

    void on_Dodaj_clicked();

    void on_prevButton_clicked();

    void on_nextButton_clicked();

    void on_nowyButton_clicked();

    void on_usunButton_clicked();

    void on_LaptopButton_2_clicked();

    void on_Laptop_gamingButton_clicked();

private:
    void dodajPc();
    void dodajLaptop();
    void pokaz();
    QGraphicsScene scene;
    QPixmap image;
    int par_zdjecie = 0;
    void dodajLaptopG();
    Ui::proe *ui;
    //void iterator();
    std::vector <Komputer*>::iterator it;
public:
    void show_zdjecie();
};

#endif // PROE_H
