#include <iostream>
#include "antywirus.h"
#include <string>
#include <fstream>

Antivirus::Antivirus()
{
	anti_index = 2901;///<data konca subskrybcji
	anti_name = "super";
}
Antivirus:: Antivirus(int index, std::string name)
{
	anti_index = index;///<data konca subskrybcji
	anti_name = name;
}
void Antivirus::set_antivirus()
{
	std::cout << "podaj nazwe antywirusa: " << std::endl;
	std::cin >> anti_name;
	std::cout << "podaj rok konca subskrybjci koniec subskrybcji antywirusa: "<<std::endl;
	std::cin >> anti_index;
}
void Antivirus::print_antivirus()
{
	std::cout << "Koniec subskrybcji antywirusa w roku: " << anti_index << std::endl;
	std::cout << "Nazwa antywirusa: " << anti_name << std::endl;
}
std::ostream& operator << (std::ostream& out1, Antivirus &anty)
{
	out1 << "Nazwa antywirusa: " << anty.anti_name << std::endl;
	out1 << "Rok konca subskrybcji: " << anty.anti_index << std::endl;
	return out1;
}

