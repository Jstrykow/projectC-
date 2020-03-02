#pragma once
#include <iostream>
#include <string>
#include <fstream>

/** klasa processor jest podklasa komputera i bedzie dziedziczona w wszystkich potomkach*/
class Processor
{

	int processor_benchmark;///<ocena processor'a od 1 do 10;
public:
	Processor();
    int get_proccesor2();
    void set_processor2(int b);///<wykozystujemy set w konstruktorze komputera
    friend void test_processor();///test procesora w pliku test
	void show_processor();
	friend std::ostream &operator << (std::ostream &out, const Processor &P);
	
}; 
