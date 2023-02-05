#include "Population.h"
using namespace sdds;
int main()
{
	if (load("PCpopulations.csv"))
	{
		display();
	}
	deallocateMemory();
	return 0;
}