/* The Generic Item

This contains everything that is common to all types of purchases.

By default generic item will create an object with the title set to an empty string, the list of authors to
 a nullptr, the number of authors to 0, and the price to $0.00.
The generic item can also be created with the following data - the title, the number of authors, and the
price. The constructor will prompt the user for the authors. Since the number of authors is not known before
runtime, dynamic memory allocation will have to be used to get the list of authors.
When asked to calculate the cost, generic item will simply return the price.
When asked to get information, generic item will stream out the title, a list of authors, and the price to
 2 decimal places.
Be sure to cleanup on object destruction.
 */
#include "Item.h"
#include <iomanip>
#include <iostream>
Item::Item()
{
    title = "";
    list_of_authors = nullptr;
    number_of_authors = 0;
    price = 0.0;
}
Item::Item(std::string _title, int _number_of_authors, double _price)
{
    title = _title;
    number_of_authors = _number_of_authors;
    price = _price;
    list_of_authors = new std::string[number_of_authors];
    for (int i = 0; i < number_of_authors; i++)
    {
        // Ignore the newline left in the buffer by the previous input
        if (i == 0)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter the name of author " << i + 1 << " : ";
        std::getline(std::cin, list_of_authors[i]);
    }
    std::cout << std::endl;
}
Item::~Item()
{
    title = "";
    delete[] list_of_authors;
    list_of_authors = nullptr;
    number_of_authors = 0;
    price = 0.0;
}

double Item::CalculateCost() const
{
    // When asked to calculate the cost, generic item will simply return the price.
    return price;
}

void Item::getInformation(std::ostream &os) const
{
    os << "Title: " << title << std::endl;
    os << "Authors: ";
    if (list_of_authors != nullptr && number_of_authors > 0)
    {
        for (int i = 0; i < number_of_authors; ++i)
        {
            os << list_of_authors[i];
            if (i < number_of_authors - 1)
            {
                os << ", ";
            }
        }
    }
    else
    {
        os << "None";
    }
    os << ".";
    os << std::endl;
    os << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
}
