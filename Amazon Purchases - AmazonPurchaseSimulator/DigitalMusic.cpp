
#include <iostream>
#include <iomanip>
#include "DigitalMusic.h"

DigitalMusic::DigitalMusic(const std::string _title, const int _numAuthors, const double _price) : Item(_title, _numAuthors, _price)
{
}

double DigitalMusic::CalculateCost() const
{
    /* the book will add a 10% penalty to the price for using
paper and 13% of the price for the harmonized sales tax. */
    double cost = Item::CalculateCost() + (0.13 * Item::CalculateCost()); // cost +(0.13*cost);
    return cost;
}
void DigitalMusic::getInformation(std::ostream &os) const
{
    Item::getInformation(os);
    os << "The real cost is " << CalculateCost() << "\n\n";
}
std::ostream &operator<<(std::ostream &os, const DigitalMusic &digitalMusic)
{
    digitalMusic.getInformation(os);
    return os;
}
