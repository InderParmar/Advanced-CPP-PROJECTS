/* char* owner;
    char* address;
    double rooms;
    double bathrooms;
    double price;
 */
#include <iostream>
#include "House.h"
#include <iomanip>
using namespace std;
House::House() // Default constructor
{
    owner = nullptr;
    address = nullptr;
    rooms = 0.0;
    bathrooms = 0.0;
    price = 0.0;
}
House::House(const char *_owner, const char *_address, const double _rooms, const double _bathrooms, const double _price) // Data for the house object
{
    owner = new char[strlen(_owner) + 1];
    strcpy(owner, _owner);
    address = new char[strlen(_address) + 1];
    strcpy(address, _address);
    rooms = _rooms;
    bathrooms = _bathrooms;
    price = _price;
}
House::House(const House &house) // Copy constructor
{
    *this = house;
}
House &House::operator=(const House &house) // Copy assignment
{
    if (this != &house)
    {
        if (this->owner != nullptr)
            delete[] this->owner;
        if (house.owner != nullptr)
        {
            this->owner = new char[strlen(house.owner) + 1];
            strcpy(owner, house.owner);
        }
        if (this->address != nullptr)
            delete[] this->address;
        if (house.address != nullptr)
        {
            this->address = new char[strlen(house.address) + 1];
            strcpy(address, house.address);
        }
        this->rooms = house.rooms;
        this->bathrooms = house.bathrooms;
        this->price = house.price;
    }
    return *this;
}
House::House(House &&house) noexcept // Move constructor
{
    *this = std::move(house);
}
House &House::operator=(House &&house) noexcept // Move assignment
{
    if (this != &house)
    {
        if (this->owner != nullptr)
            delete[] this->owner;
        this->owner = house.owner;
        if (this->address != nullptr)
            delete[] this->address;
        this->address = house.address;
        this->rooms = house.rooms;
        this->bathrooms = house.bathrooms;
        this->price = house.price;
        house.owner = "none";
        house.address = "none";
        house.rooms = 0.0;
        house.bathrooms = 0.0;
        house.price = 0.0;
    }
    return *this;
}

bool House::ChangeOwner(const char *newOwner) // Change the owner
{
    bool retval = false;
    if (this->owner != nullptr)
        delete[] this->owner;
    if (newOwner != nullptr)
    {
        this->owner = new char[strlen(newOwner) + 1];
        strcpy(this->owner, newOwner);
        retval = true;
    }
    return retval;
}

bool House::ChangeAddress(const char *newAddress) // Change the owner
{
    bool retval = false;
    if (this->address != nullptr)
        delete[] this->address;
    if (newAddress != nullptr)
    {
        retval = true;
        this->address = new char[strlen(newAddress) + 1];
        strcpy(this->address, newAddress);
    }
    return retval;
}
bool House::ChangePrice(double newPrice) // Change the price
{
    bool retval = false;
    if (newPrice >= 0)
    {
        retval = true;
        this->price = newPrice;
    }
    return retval;
}
void House::ChangeRooms(double newRooms)
{
    this->rooms = newRooms;
}
void House::ChangeBathrooms(double newBathrooms)
{
    this->bathrooms = newBathrooms;
}
const House &House::operator+=(double amount) // increment/decrement the price of the house
{
    this->price += amount;
    return *this;
}
void House::DisplayInfo() const // Display the owner, address, rooms, bathrooms, and price
{
    cout << left << setw(10) << "Owner:" << this->owner << endl;

    cout << left << setw(10) << "Address:" << this->address << endl;
    cout << left << setw(10) << "Rooms:" << fixed << setprecision(2) << this->rooms << endl;

    cout << left << setw(10) << "Bathrooms:" << fixed << setprecision(2) << this->bathrooms << endl;
    cout << left << setw(10) << "Price:"
         << "$" << fixed << setprecision(2) << this->price << endl;
    cout << endl;
}
char *House::GetOwner() const
{
    return owner;
}
char *House::GetAddress() const
{
    return address;
}
double House::GetRooms() const
{
    return this->rooms;
}
double House::GetBathrooms() const
{
    return this->bathrooms;
}
double House::GetPrice() const
{
    return this->price;
}
House::~House() // Destructor
{
    if (owner != nullptr)
    {
        delete[] owner;
        owner = nullptr;
    }
    if (address != nullptr)
    {
        delete[] address;
        address = nullptr;
    }
    rooms = 0.0;
    bathrooms = 0.0;
    price = 0.0;
}

bool operator==(const House &house1, const House &house2) // Do the two houses have the same owner?
{
    if (!house1.GetOwner() || !house2.GetOwner()) {
        return false; // If either owner is nullptr, they can't be equal
    }

    bool retval = false;
    if (strcmp(house1.GetOwner(), house2.GetOwner()) == 0)
    {
        retval = true;
    }
    return retval;
}
void operator>>(House &house1, House &house2) // Move contents from the house1 object to the house2 object
{
    house2.ChangeOwner(house1.GetOwner());
    house2.ChangeAddress(house1.GetAddress());
    house2.ChangeRooms(house1.GetRooms());
    house2.ChangeBathrooms(house1.GetBathrooms());
    house2.ChangePrice(house1.GetPrice());
    house1.ChangeOwner("none");
    house1.ChangeAddress("none");

    house1.ChangePrice(0.0);
    house1.ChangeBathrooms(0.0);
    house1.ChangeRooms(0.0);
}