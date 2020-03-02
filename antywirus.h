#ifndef ANTYWIRUS_H_INCLUDED
#define ANTYWIRUS_H_INCLUDED
#include <string>
#include <fstream>

class Antivirus
{
	int anti_index;///<data konca subskrybcji
	std::string anti_name;
public:
	void set_antivirus();
	void print_antivirus();
	Antivirus(int, std::string);
	friend std::ostream& operator << (std::ostream& out1, Antivirus &anty);
	Antivirus();
};

#endif // ANTYWIRUS_H_INCLUDED
