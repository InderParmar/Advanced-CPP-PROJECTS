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

#ifndef _ITEM_H_
#define _ITEM_H_
#include <iostream>
class Item
{
    std::string title;
    std::string *list_of_authors;
    int number_of_authors;
    double price;
public:
    Item();
    Item(std::string _title, int _number_of_authors, double _price);
    double CalculateCost()const;
    virtual void getInformation(std::ostream& os)const;
    ~Item();
};
#endif 