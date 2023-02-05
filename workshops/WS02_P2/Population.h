#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
	struct Population
	{
		char* m_postalcode;
		int m_pop;
	};
	void sort();
	bool load(Population & st);
	bool load(const char*);
	void display(Population & st);
	void display();
	void deallocateMemory();
}
#endif	// SDDS_POPULATION_H_