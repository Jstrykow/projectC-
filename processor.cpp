#include <iostream>
#include <fstream>
#include <string>
#include "processor.h"

Processor::Processor()
{
processor_benchmark = 5;///<<wartosc domylsnie przypisywana processorowi
}

//teraz metody
int Processor::get_proccesor2()
{
   return processor_benchmark;
}
///metoda pokazujaca processor
void Processor:: show_processor()
{
std::cout<< "Benchmark_processora: " << processor_benchmark << std::endl;
}

void Processor::set_processor2(int benchmark1 )
{
    processor_benchmark = benchmark1;
}

std::ostream& operator << (std::ostream &out, const Processor &P)
{
	out << "Benchmark: "<< P.processor_benchmark << std::endl;
	return out;
}

