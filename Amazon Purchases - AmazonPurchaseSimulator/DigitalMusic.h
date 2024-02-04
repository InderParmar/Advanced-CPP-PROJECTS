#ifndef _DIGITALMUSIC_H_
#define _DIGITALMUSIC_H_
#include "Item.h"

class DigitalMusic : public Item
{
public:
    DigitalMusic(const std::string _title, const int _numAuthors, const double _price);
    double CalculateCost() const;
    void getInformation(std::ostream &os) const override;
    friend std::ostream &operator<<(std::ostream &os, const DigitalMusic &digitalMusic);
};
#endif