#include <iostream>
#include "laptop.h"
#include "antywirus.h"
#include <string>
#include <cstdlib>
#include <fstream>

std::string Laptop::getmodel()
{
    return model;
}
void Laptop::setmodel(std::string model1)
{
  model = model1;
}
std::string Laptop::typ()
{
    return "L";
}
void Laptop::zapisz_komputer(std::string n = "test")
{
	std::fstream plik;
	plik.open(n, std::fstream::out | std::fstream::app);
	plik << (*this);
	plik.close();
}
Laptop::Laptop()///kostruktor
{

}
Laptop::~Laptop()//dekostruktor
{

}

Laptop::Laptop( int benchmark1 , std::string uzytkownik = "Domyslny", std::string model1 = "O")
    :Komputer(benchmark1, uzytkownik)
{
    model = model1;
}
void Laptop::pokaz()
{
	std::cout << "laptop o ktory prosiles: " << std::endl;
	std::cout << "Model: " << model << std::endl;///funckjonalnosc doddana w laptopie
	show();///<funkcja odziedziczona z komputer
	std::cout << std::endl;
}

std::ostream & operator << (std::ostream& out2, const Laptop &L)
{
	out2 << "Model: " << L.model << std::endl;
	out2 << "Uzytkownik: " << L.user << std::endl;
	out2 << L.processor_komputer;
	return out2;
}

void Laptop::set()
{
	std::cout << "podaj model: ";
	std::cin >> model;
	set_komputer();
}

