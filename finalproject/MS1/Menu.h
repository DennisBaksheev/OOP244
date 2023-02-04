#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;

namespace sdds
{
	class Menu;
	class MenuItem
	{
		friend Menu;
	private:
		char* nameTitle;
		MenuItem(); 
		MenuItem(const char*); 
		ostream& display(std::ostream&) const; 
		~MenuItem(); 
	};

	class Menu
	{
		const int MAX_NO_OF_ITEMS = 10;
		char* title;
		MenuItem* menuItem;
		int idt;
		int noItem;
public:
    void clear();
		Menu(); 
		Menu(const char*, int indent = 0); 
		Menu(const Menu&); 
		Menu& operator=(const Menu&); 
		~Menu(); 
		void setTitle(const char*); 
		void setItems(const MenuItem*, int); 
		void add_arguments(const char*, const MenuItem*, int, int); 
		operator bool() const; 
		operator int() const;
		bool isEmpty() const; 
		void display() const; 
		void add(const char*); 	
		int run() const; 
		Menu& operator=(const char*); 
		Menu& operator<<(const char*);	
	};
	void indent(std::ostream&, int); 
}

#endif 