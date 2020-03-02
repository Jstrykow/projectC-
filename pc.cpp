#include <iostream>
#include "komputer.h"
#include "pc.h"
#include <string>

void Pc::setmotherboard(std::string motherboard1)
{
    motherboard = motherboard1;
}
std::string Pc::getmotherboard()
{
    return motherboard;
}
std::string Pc:: typ()
{
    return "P";
}
Pc::Pc(int benchmark1,  std::string uzytkownik = "M",std::string  motherboard1  = "U")
    :Komputer(benchmark1, uzytkownik)
{
     motherboard = motherboard1 ;
}
Pc::Pc()
	:Komputer()
{
}

void Pc::pokaz()
{
	std::cout << "PC o ktory prosiles: " << std::endl;
	std::cout << "motherboard: " << motherboard << std::endl;
	show();///<funkcja odziedziczona z komputer
	std::cout << std::endl;
}

Pc::~Pc()
{
}

void Pc::set()
{
	std::cout<<"Podaj motherboard: ";
	std::cin >> motherboard;
	set_komputer();
}
void Pc::zapisz_komputer(std::string n = "test")
{
	std::fstream plik;
	plik.open(n, std::fstream::out | std::fstream::app);
	plik << (*this);
	plik.close();
}

std::ostream & operator << (std::ostream& out2, const Pc &P)
{
	out2 << "Motherboard: " << P.motherboard << std::endl;
	out2 << "Uzytkownik: " << P.user << std::endl;
	out2 << P.processor_komputer;
	return out2;
}
