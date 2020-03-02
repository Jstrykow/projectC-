#pragma once
#include <iostream>
#include "processor.h"
#include "string.h"
#include <fstream>
#include "antywirus.h"
#include "user.h"
#include <vector>


class Komputer
{
protected:

	Processor processor_komputer;
    User user;
    std::vector <Antivirus> antywirus;///<obiekt dynamiczny


public:
    Komputer( int/**processor benchmark */, std::string/**uzytkownik */);
	Komputer();
	void show();
    virtual std::string typ() = 0;
    void set_processor(int);
    int get_processor();
    std::string get_user();
    void setUser(std::string);
	virtual void pokaz()= 0;
	void set_komputer();
	virtual void set() = 0;///uzywamy set komputer w klasach potomnych
	void dodaj_antywirus(Antivirus&);
	void usun_antywirus();
	friend std::ostream & operator << (std::ostream &out1, Komputer &K);
	virtual void zapisz_komputer(std::string) = 0;///<zapisz do pliku
};
