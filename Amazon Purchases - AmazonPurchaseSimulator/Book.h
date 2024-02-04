/* Book.
#include "Item.h"
This contains information specific to a book purchase.

When asked to calculate the cost, the book will add a 10% penalty to the price for using
paper and 13% of the price for the harmonized sales tax.
When asked to get information, book will stream out information from the generic item that
it is derived from. It will also stream out one line specifying: "There is a 10% penalty for using paper." */

#ifndef _BOOK_H_
#define _BOOK_H_

#include "Item.h"

class Book : public Item
{
public:
    Book(const std::string _title, const int _numAuthors, const double _price);
    double CalculateCost() const;
    void getInformation(std::ostream &os) const override;
    friend std::ostream& operator<<(std::ostream &os, const Book &book);
};
#endif