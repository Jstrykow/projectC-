#ifndef LAPTOP_H_INCLUDED
#define LAPTOP_H_INCLUDED
#include "antywirus.h"
#include "user.h"
#include <string>
#include "komputer.h"
#include <fstream>

class Laptop : public Komputer///laptop dziedziczy publicznie z klasy komputer
{
//User user;
protected:
	std::string model;
public:
	void pokaz();
	void set();
    std::string typ();
    std::string getmodel();
    void setmodel(std::string);
    Laptop(int/*bednchmark*/, std::string/*user*/, std::string/*model*/);///konstruktor laptopa
	void zapisz_komputer(std::string);
	Laptop();
	~Laptop();
	friend std::ostream & operator << (std::ostream &out2, const Laptop &L);

};
#endif // LAPTOP_H_INCLUDED

