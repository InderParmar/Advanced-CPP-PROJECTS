
#include <iostream>
#include <iomanip>
#include "Book.h"
Book::Book(const std::string _title, const int _numAuthors, const double _price) : Item(_title, _numAuthors, _price)
{
}

double Book::CalculateCost()const
{
    double cost = (0.10 * Item::CalculateCost()) + Item::CalculateCost();
    cost = cost + (0.13 * Item::CalculateCost());
    return cost;
}
void Book::getInformation(std::ostream &os) const
{
    Item::getInformation(os);
    os << "There is a 10% penalty for using paper.\n";
    os<<"The real cost is " << CalculateCost()<<"\n\n";
}
std::ostream& operator<<(std::ostream &os, const Book &book) {
    book.getInformation(os);
    return os;
}