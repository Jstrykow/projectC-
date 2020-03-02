#include <iostream>
#include "laptop.h"
#include "laptop_gaming.h"
#include <string>
#include <fstream>

std::string Laptop_gaming::getkarta_grafiki()
{
    return karta_grafiki;
}
void Laptop_gaming::setkarta_grafiki(std::string  karta_grafiki1)
{
   karta_grafiki =  karta_grafiki1;
}
std::string Laptop_gaming::typ()
{
    return "G";
}
Laptop_gaming::Laptop_gaming()///kostruktor
{
}

Laptop_gaming::~Laptop_gaming()//dekostruktor
{
}

Laptop_gaming::Laptop_gaming( int benchmark1, std::string uzytkownik = "Domyslny", std::string model1 = "model", std::string karta1= "karta")
    :Laptop(benchmark1, uzytkownik, model1)
{
    karta_grafiki = karta1;
}
void Laptop_gaming::pokaz()
{
	std::cout << "laptop gamingowy o ktory prosiles: " << std::endl; 
	std::cout << "karta grafiki: " << karta_grafiki << std::endl;///funckjonalnosc doddana w laptop gamingowy
	Laptop::pokaz();/// odziedziczona po laptop ktory dizedziczy z komputer
	std::cout << std::endl;
}

void Laptop_gaming::set()
{
	std::cout << "podaj karte graficzna: ";
	std::cin >> karta_grafiki;
	std::cout << "podaj model: ";
	std::cin >> model;
	set_komputer();
}
std::ostream & operator << (std::ostream& out2, const Laptop_gaming &K)
{
	out2 << "karta grafiki: " << K.karta_grafiki << std::endl;
	out2 << (Laptop)K;
	//if (!L.antywirus.empty())
	//out2 << L.antywirus;
	return out2;
}

void Laptop_gaming::zapisz_komputer(std::string n = "test")
{
	std::fstream plik;
	plik.open(n, std::fstream::out | std::fstream::app);
	plik << (*this);
	plik.close();
}
