#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sdds
{
	int noOfPop;
	Population * population;
	void sort()
	{
		int i, j;
		Population temp;
		for (i = noOfPop - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (population[j].m_pop > population[j + 1].m_pop)
				{
					temp = population[j];
					population[j] = population[j + 1];
					population[j + 1] = temp;
				}
			}
		}
	}
	bool load(Population & st)
	{
		bool ok = false;
		char name[128];
		if (1)
		{
			ok = read(name);
			ok = ok && read(st.m_pop);
			st.m_postalcode = new char[strlen(name) + 1];
			strcpy(st.m_postalcode, name);
		}
		return ok;
	}
	bool load(const char* filename)
	{
		bool ok = false;
		int i = 0;
		if (openFile(filename))
		{
			ok = true;
			noOfPop = noOfRecords();
			population = new Population[noOfPop];
			for (i = 0; ok && i < noOfPop; i++)
			{
				ok = load(population[i]);
			}
			if (!ok)
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
			}
			else
			{
				ok = true;
			}
			closeFile();
		}
		return ok;
	}
	// TODO: Implementation for the display functions go here
	void display(Population & st)
	{
		cout << st.m_postalcode << ": " << st.m_pop << endl;
	}
	void display()
	{
		sort();
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		int i, j;
		long total = 0;
		for (i = 0, j = 1; i < noOfPop; i++)
		{
			cout << j++ << "- ";
			display(population[i]);
			total += population[i].m_pop;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << total << endl;
	}
	// TODO: Implementation for the deallocateMemory function goes here
	void deallocateMemory()
	{
		int i = 0;
		while (i < noOfPop) 
		{
			delete[] population[i].m_postalcode;
			population[i].m_postalcode = nullptr;
			i++;
		}
		delete[] population;
		return;
	}
}