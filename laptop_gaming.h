#pragma once
#include "laptop.h"///syn naszego laptopa
#include <iostream>
#include <string>

class Laptop_gaming
	:public Laptop
{
	/** rozszerza klase laptop o karte graficzna*/
	std::string karta_grafiki;
public:
    std::string getkarta_grafiki();
    void setkarta_grafiki(std::string);
	friend void test_laptop_gaming();
	void pokaz();
    Laptop_gaming(int/*processr*/, std::string/*user*/, std::string /*model*/, std::string /** karta graficzna*/);
	friend std::ostream & operator << (std::ostream& out2, const Laptop_gaming &K);
	~Laptop_gaming();
	Laptop_gaming();
    std::string typ();
	void zapisz_komputer(std::string);
	void set();
};
