// House.h - class declaration for a house

#ifndef _HOUSE_H_
#define _HOUSE_H_

class House
{
	char *owner;
	char *address;
	double rooms;
	double bathrooms;
	double price;
	

public:
	House();// Default constructor
	House(const char *_owner, const char *_address, const double _rooms, const double _bathrooms, const double _price); // Data for the house object
	House(const House &house);// Copy constructor
	House &operator=(const House &house);// Copy assignment
	House(House &&house) noexcept;// Move constructor
	House &operator=(House &&house) noexcept;// Move assignment
	bool ChangeAddress(const char *newAddress);																				// Change the owner

	bool ChangeOwner(const char *newOwner);		// Change the owner
	bool ChangePrice(double newPrice);		// Change the price
	void ChangeRooms(double newRooms);
	void ChangeBathrooms(double newBathrooms);
	const House &operator+=(double amount); // increment/decrement the price of the house
	char *GetOwner() const;
	char *GetAddress() const;
	double GetRooms() const;
	double GetBathrooms() const;
	double GetPrice() const;
	void DisplayInfo() const; // Display the owner, address, rooms, bathrooms, and price

	~House(); // Destructor
};

bool operator==(const House &house1, const House &house2); // Do the two houses have the same owner?
void operator>>(House &house1, House &house2);			   // Move contents from the house1 object to the house2 object

#endif // _HOUSE_H_