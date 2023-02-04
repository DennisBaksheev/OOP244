#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"

namespace sdds
{



    MenuItem::MenuItem()
    {
        nameTitle = nullptr;
    }


    MenuItem::MenuItem(const char* name)
    {
        nameTitle = nullptr;
        if (name != nullptr)
        {
            nameTitle = new char[strlen(name) + 1];
            strcpy(nameTitle, name);
        }
    }


    std::ostream& MenuItem::display(std::ostream& os) const
    {
        if (nameTitle != nullptr && strlen(nameTitle) > 0)
            os << nameTitle << endl;
        return os;
    }



    MenuItem::~MenuItem()
    {
        delete[] nameTitle;
        nameTitle = nullptr;
    }



    Menu::Menu()
    {
        title = nullptr;
        menuItem = nullptr;
        idt = 0;
        noItem = 0;
    }


    Menu::Menu(const char* name, int indent)

    {

        menuItem = nullptr;
        title = nullptr;
        idt = indent;
        noItem = 0;
        this->setTitle(name);
    }

    Menu::Menu(const Menu& object)
    {
        idt = 0;
        noItem = 0;
        menuItem = nullptr;
        title = nullptr;
        this->add_arguments(object.title, object.menuItem, object.idt, object.noItem);
    }
    void Menu::clear() {

        delete[] title;
        noItem = 0;
        title = nullptr;
        idt = 0;
        delete[] menuItem;
        menuItem = nullptr;

    }



    void Menu::setTitle(const char* name)
    {
        if (title != nullptr)
        {
            delete[] title;
            title = nullptr;
        }

        if (name != nullptr && name[0] != '\0')
        {
            title = new char[strlen(name) + 1];
            strcpy(title, name);
        }
    }

    void Menu::setItems(const MenuItem* vastu, int size)
    {
        if (menuItem != nullptr)
        {
            delete[] menuItem;
            menuItem = nullptr;
        }

        if (vastu != nullptr && size > 0)
        {
            menuItem = new MenuItem[size];
            for (int i = 0; i < size; i++)
            {
                int len = strlen(vastu[i].nameTitle) + 1;
                menuItem[i].nameTitle = new char[len];
                strcpy(menuItem[i].nameTitle, vastu[i].nameTitle);
            }
        }
    }

    Menu& Menu::operator= (const Menu& source)
    {
        this->add_arguments(source.title, source.menuItem, source.idt, source.noItem);
        return *this;
    }

    void Menu::add_arguments(const char* name, const MenuItem* menuItems, int indent, int numbers)
    {
        idt = indent;
        noItem = numbers;
        setTitle(name);
        setItems(menuItems, numbers);
    }

    Menu::operator bool() const
    {
        bool check;
        if (!isEmpty()) {
            check = true;
        }
        else
        {
            check = false;
        }
        return check;
    }

    bool Menu::isEmpty() const
    {
        return (title == nullptr && menuItem == nullptr && noItem <= 0) ? true : false;
    }

    void Menu::display() const
    {
        if (isEmpty())
        {
            cout << "Invalid Menu!" << endl;
        }
        else if (noItem <= 0 || menuItem == nullptr)
        {
            indent(cout, 0);
            cout << title << endl;
            cout << "No Items to display!" << endl;
        }
        else
        {
            indent(cout, idt);
            cout << title << endl;
            for (int i = 0; i < noItem; i++)
            {
                indent(cout, idt);
                cout << (i + 1) << "- ";
                menuItem[i].display(cout);
            }
            indent(cout, idt);
            cout << "> ";
        }
    }

    Menu& Menu::operator=(const char* name)
    {
        this->setTitle(name);
        return *this;
    }

    void Menu::add(const char* name)

    {
        if (name != nullptr && name[0] != '\0' && noItem < MAX_NO_OF_ITEMS && title != nullptr)
        {

            MenuItem* temp = new MenuItem[noItem + 1];
            for (int i = 0; i < noItem; i++)
            {
                temp[i].nameTitle = new char[strlen(menuItem[i].nameTitle) + 1];
                strcpy(temp[i].nameTitle, menuItem[i].nameTitle);
            }

            temp[noItem].nameTitle = new char[strlen(name) + 1];
            strcpy(temp[this->noItem].nameTitle, name);

            if (menuItem != nullptr)
            {
                delete[] menuItem;
                menuItem = nullptr;
            }
            noItem++;
            menuItem = temp;


        }
        else if (name == nullptr)
        {
            delete[] title;
            delete[] menuItem;
            title = nullptr;
            menuItem = nullptr;
            idt = 0;
            noItem = 0;
        }
    }

    Menu& Menu::operator<<(const char* name)
    {
        this->add(name);
        return *this;
    }

    int Menu::run() const
    {
        int select;
        bool flag = false;
        display();
        if (noItem > 0)
        {

            while (flag == false)
            {
                if (!(cin >> select)) cout << "Invalid Integer, try again: ";
                else if (select <= 0 || select > noItem) cout << "Invalid selection, try again: ";
                else flag = true;
                cin.clear();
                cin.ignore(2000, '\n');
            }

        }
        else select = 0;
        return select;
    }

    Menu::operator int() const
    {
        return run();
    }

    Menu::~Menu()
    {
        delete[] title;
        title = nullptr;


        delete[] menuItem;
        menuItem = nullptr;
    }

    void indent(std::ostream& os, int size)
    {
        int leng = size * 4;
        for (int i = 0; i < leng; i++)
        {
            os << " ";
        }
    }

    void Menu::setIndent(int idtParam)
    {
        this->idt = idtParam;
    }



}