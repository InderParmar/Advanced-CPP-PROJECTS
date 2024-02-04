
#ifndef _DVD_H_
#define _DVD_H_

#include "Item.h"

class DVD : public Item
{
public:
    DVD(const std::string _title, const int _numAuthors, const double _price);
    double CalculateCost()const;
    void getInformation(std::ostream &os)const override;
    friend std::ostream &operator<<(std::ostream &os, const DVD &dvd);
};
#endif