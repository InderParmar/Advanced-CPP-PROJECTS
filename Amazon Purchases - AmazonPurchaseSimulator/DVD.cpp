
#include <iostream>
#include <iomanip>
#include "DVD.h"
DVD::DVD(const std::string _title, const int _numAuthors, const double _price) : Item(_title, _numAuthors, _price)
{
}

double DVD::CalculateCost() const
{
    /* the book will add a 10% penalty to the price for using
paper and 13% of the price for the harmonized sales tax. */
    double cost = (0.05 * Item::CalculateCost()) + Item::CalculateCost();
    cost = cost + (0.13 * Item::CalculateCost()); // cost +(0.13*cost);
    return cost;
}
void DVD::getInformation(std::ostream &os) const
{
    Item::getInformation(os);
    os << "There is a 5% penalty for using plastic.\n";
    os << "The real cost is " << CalculateCost() << "\n\n";
}

std::ostream &operator<<(std::ostream &os, const DVD &dvd)
{
    dvd.getInformation(os);
    return os;
}