#include <iostream>
#include <string>
#include <fstream>
#include "komputer.h"
#include "processor.h"///kozystamy z tego do wyswietlania processora
#include "antywirus.h"
#include "user.h"

int Komputer::get_processor()
{
    return processor_komputer.get_proccesor2();
}
std::string Komputer::get_user()
{
    return user.get_user2();
}
void Komputer::set_processor(int procesor)
{
    processor_komputer.set_processor2(procesor);
}

void Komputer::setUser(std::string uzytkownik)
{
    user.setUser2(uzytkownik);
}
void Komputer::show()
{	
	processor_komputer.show_processor();///<wykozystuje metody processora
	std::cout << "Uzytkownik: " << user << std::endl;
	if(!antywirus.empty())
	antywirus[0].print_antivirus();
}

Komputer::Komputer(int benchmark/**processor benchmark */, std::string uzytkownik = "Pan_Domylsny" /**uzytkownik */)
{

    user.setUser2(uzytkownik);
    processor_komputer.set_processor2(benchmark);

}


/**
operator strumienniowy << bedziemy go uzywac do obslugi strumini klas potomnych
*/

std::ostream& operator << (std::ostream& out1, Komputer &K)
{
	out1 << "Uzytkownik: " << K.user<<std::endl; 
	out1 << K.processor_komputer;
	if (!K.antywirus.empty())
	out1<<K.antywirus[0];
	return out1;
}

void Komputer:: zapisz_komputer(std::string filename)
{
	std::ofstream plik;
	plik.open(filename);//stworzyc nowy jezeli nie isnieje inaczej blad
	plik << (*this);///obiekt na rzecz ktorego zostala wywolana metoda
	plik.close();
}

void Komputer::dodaj_antywirus(Antivirus &A)
{
	antywirus.clear();
	antywirus.push_back(A);
	antywirus[0].print_antivirus();
}
void Komputer::usun_antywirus()
{
	antywirus.clear();
}

void Komputer::set_komputer()
{
	std::string n;
	int b;
	std::cout << "nazwa processora: ";
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "processor benchmark: ";
	std::cin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	do
	{
		try
		{
			std::cin >> b;
			if (b < 1 || b > 10)
				std::cout << "podaj wartosc od 1 do 10:" << std::endl;
		}
		catch (std::fstream::failure)
		{
			std::cout << "podaj wartosc od 1 do 10:" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	} while (b < 1 || b > 10);
	std::cout << std::endl;
	std::cout << "uzytkownik: ";
    user.print_user();
	std::cout << std::endl;
    processor_komputer.set_processor2(b);
}

Komputer::Komputer()
{
}
