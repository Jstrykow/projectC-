#pragma once
#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED
#include <string>
#include "komputer.h"
#include "user.h"

class Pc : public Komputer///laptop dziedziczy publicznie z klasy komputer
{
	std::string motherboard;
public:
	void zapisz_komputer(std::string );
	virtual void pokaz();
	void set();
    std::string typ();
    std::string getmotherboard();
    Pc(int, std::string, std::string);///konstruktor Pc
    void setmotherboard(std::string);
	friend std::ostream & operator << (std::ostream &out2, const Pc &P);
	~Pc();
    Pc();
};
#endif
