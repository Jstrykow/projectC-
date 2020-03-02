#include "proe.h"
#include "ui_proe.h"
#include <QLineEdit>
#include <QIntValidator>

extern std::vector <Komputer*> komputery;
/*
void proe::iterator()
{
    it = komputery.begin();
}
*/
proe::proe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::proe)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(0, 100, this);
   // QLineEdit *processor_in = new QLineEdit(this);
    ui->processor_in->setValidator(validator);
}

proe::~proe()
{
    delete ui;
}


void proe::on_PCButton_clicked()
{
    ui->motherboardin->setEnabled(1);
    ui->modelin->setDisabled(1);
    ui->karta_graficznain->setDisabled(1);
}

void proe::dodajLaptop()
{
QString model1 = ui->modelin->text();
QString uzytkownik = ui->user_in->text();
int processor = ui->processor_in->text().toInt();
Laptop* pomoc = new Laptop;
pomoc->setmodel(model1.toStdString());
pomoc->setUser(uzytkownik.toStdString());
pomoc->set_processor(processor);
komputery.push_back(pomoc);
it = komputery.end() - 1;
pokaz();
}
void proe::dodajLaptopG()
{
QString model1 = ui->modelin->text();
QString uzytkownik = ui->user_in->text();
QString karta = ui->karta_graficznain->text();
int processor = ui->processor_in->text().toInt();
Laptop_gaming* pomoc = new Laptop_gaming;
pomoc->setmodel(model1.toStdString());
pomoc->setUser(uzytkownik.toStdString());
pomoc->set_processor(processor);
pomoc->setkarta_grafiki(karta.toStdString());
komputery.push_back(pomoc);
it = komputery.end() - 1;
pokaz();
}
void proe::dodajPc()
{
    QString motherboard1 = ui->motherboardin->text();
    QString uzytkownik = ui->user_in->text();
    int processor = ui->processor_in->text().toInt();
    Pc* pomoc = new Pc;
    pomoc->setmotherboard(motherboard1.toStdString());
    pomoc->setUser(uzytkownik.toStdString());
    pomoc->set_processor(processor);
    komputery.push_back(pomoc);
    it = komputery.end() - 1;
    pokaz();
}
void proe::pokaz()
{
        if((*it)->typ() == "P")
        {
        Pc *wsk;
        wsk = dynamic_cast<Pc*>((*it));
        ui->processorout->setText(QString::number(wsk->get_processor()));
        ui->userout->setText(QString::fromStdString(wsk->get_user()));
        ui->motherboardout->setText(QString::fromStdString(wsk->getmotherboard()));
        ui->motherboardout->setEnabled(1);
        ui->modelout->setDisabled(1);
        ui->karta_graficznaout->setDisabled(1);
        par_zdjecie = 1;

        }
        if((*it)->typ() == "L")
        {
            Laptop *wsk;
            wsk = dynamic_cast<Laptop*>((*it));
            ui->processorout->setText(QString::number(wsk->get_processor()));
           ui->userout->setText(QString::fromStdString(wsk->get_user()));
            ui->modelout->setText(QString::fromStdString(wsk->getmodel()));
            ui->motherboardout->setDisabled(1);
            ui->modelout->setEnabled(1);
            par_zdjecie = 2;
        }
        if((*it)->typ() == "G")
        {
            Laptop_gaming *wsk;
            wsk = dynamic_cast<Laptop_gaming*>((*it));
            ui->processorout->setText(QString::number(wsk->get_processor()));
            ui->userout->setText(QString::fromStdString(wsk->get_user()));
            ui->modelout->setText(QString::fromStdString(wsk->getmodel()));
            ui->karta_graficznaout->setText(QString::fromStdString(wsk->getkarta_grafiki()));
            ui->motherboardout->setDisabled(1);
            par_zdjecie = 3;
        }
show_zdjecie();
}



void proe::on_Dodaj_clicked()
{
    if(ui->PCButton->isChecked()==true)
    {
    dodajPc();
    ui->motherboardin->setEnabled(1);
    ui->prevButton->setEnabled(1);
    }
    else if(ui->LaptopButton_2->isChecked()==true)
    {
    dodajLaptop();
    ui->prevButton->setEnabled(1);
    }
    else if(ui->Laptop_gamingButton->isChecked()==true)
    {
    dodajLaptopG();
    ui->prevButton->setEnabled(1);
    }
}

void proe::on_prevButton_clicked()
{

    if(it == komputery.begin())
    {
    ui->prevButton->setDisabled(1);
    }
    else if(!komputery.empty())
    {
    ui->nextButton->setEnabled(1);
    it--;
    pokaz();
    }
}

void proe::on_nextButton_clicked()
{

    if(it == komputery.end()-1)
    {
    ui->nextButton->setDisabled(1);
    }
    else if(!komputery.empty())
    {
    ui->prevButton->setEnabled(1);//moze nie dziala
    it++;
    pokaz();
    }
}

void proe::on_nowyButton_clicked()
{
    it = komputery.begin();
    pokaz();
}


void proe::on_usunButton_clicked()
{

    if(!komputery.empty())
    {
       komputery.erase(it);
        if(!komputery.empty())
        {
       it = komputery.begin();
       if(komputery.size()>1)
       {
           ui->nextButton->setEnabled(1);
       }
       else
       {
           ui->nextButton->setDisabled(1);
       }
       pokaz();
        }
    }
}

void proe::on_LaptopButton_2_clicked()
{
    ui->motherboardin->setDisabled(1);
    ui->modelin->setEnabled(1);
    ui->karta_graficznain->setDisabled(1);
}

void proe::on_Laptop_gamingButton_clicked()
{
    ui->motherboardin->setDisabled(1);
    ui->modelin->setEnabled(1);
    ui->karta_graficznain->setEnabled(1);
}

void proe::show_zdjecie()
{
    switch(par_zdjecie)
    {
    case 1:
    {
        QPixmap pix(":/img/img/pc.png");
        ui->zdj->setPixmap(pix);
    }break;
    case 2:
    {
        QPixmap pix(":/img/img/laptop_1.png");
        ui->zdj->setPixmap(pix);
    }break;
    case 3:
    {
        QPixmap pix(":/img/img/gaming_1.png");
        ui->zdj->setPixmap(pix);
    }break;
    }
}
