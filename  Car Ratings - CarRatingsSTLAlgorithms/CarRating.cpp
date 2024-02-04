//Name : Inderpreet Singh Parmar
//Student Id : 164132219
//Mail Id : iparmar1@myseneca.ca
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <numeric>
#include <vector>
using namespace std;

struct Rate_Cars {
	string Car_Name;
	string Country_Origin;
	double Car_Fuel_Mileage;
	double HP;
	double Car_Reliability;
};

void processCars(vector<Rate_Cars>& Car) {
	{
		sort(Car.begin(), Car.end(), [&](const auto& car1, const auto& car2) {
			return car1.Car_Reliability > car2.Car_Reliability;
			});
		cout << "\n";
		cout << "SORTED BY RELIABILITY:" << "\n";
		for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
			cout << _car.Car_Name << ", " << _car.Country_Origin << "," << " reliabilty: " << _car.Car_Reliability << "\n";
			});
		cout << "\n";
	}
	{
		sort(Car.begin(), Car.end(), [&](const auto& car_0, const auto& car_1) {
			return car_0.Car_Fuel_Mileage < car_1.Car_Fuel_Mileage;
			});
		cout << "SORTED BY FUEL EFFICIENCY:" << "\n";
		for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
			cout << _car.Car_Name << ", " << _car.Country_Origin << "," << " fuel efficiency: " << _car.Car_Fuel_Mileage << "\n";
			});
		cout << "\n";
	}
	{
		sort(Car.begin(), Car.end(), [&](const auto& car0, const auto& car1) {
			return car0.HP > car1.HP;
			});
		cout << "SORTED BY HORSE POWER:" << "\n";
		for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
			cout << _car.Car_Name << ", " << _car.Country_Origin << "," << " horse power: " << _car.HP << "\n";
			});
	}
	{
		int div = 0;
		auto Total = accumulate(Car.begin(), Car.end(), 0.0, [&](double tot, const auto& car1) {

			if (car1.Country_Origin == "Germany")
			{
				++div;
				tot = tot + car1.HP;
				return tot;
			}
			});
		cout << "\n";
		cout << "The average horse power of all German cars is " << Total / div << "\n";
		cout << "\n";
	}
	{
		cout << "HIGH RELIABILITY CARS:" << "\n";
		for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
			if (_car.Car_Reliability > 8.0)
			{

				cout << _car.Car_Name << ", " << _car.Country_Origin << "," << " reliabilty: " << _car.Car_Reliability << "\n";
			}
			});
	}
	{
		transform(Car.begin(), Car.end(), Car.begin(), [](Rate_Cars& _car) {
			if (_car.Country_Origin == "USA")
			{
				_car.Country_Origin = "United States";
			}
			return _car;
			});
	}
	{
		sort(Car.begin(), Car.end(), [](const auto& car0, const auto& car1) {
			double Car_Rating = 2 * (car0.Car_Reliability - 4.1) + 2 * (12.1 - car0.Car_Fuel_Mileage) + (car0.HP - 130) / 37;
			double Car_rating = 2 * (car1.Car_Reliability - 4.1) + 2 * (12.1 - car1.Car_Fuel_Mileage) + (car1.HP - 130) / 37;
			return Car_Rating > Car_rating;
			});
	}
}
int main() {
	//setting up the data
	vector<Rate_Cars> Car({
		{"Toyota Corolla", "Japan",8,130,9.1},
		{"Honda Civic", "Japan",7.8,138,8.8 },
		{"Dodge Charger", "USA",10.8,300,6.5},
		{"BMW 330x", "Germany",8.9,260,7.2},
		{"Chevrolet Impala", "USA", 9.9,280,8.1},
		{"BMW 240", "Germany",9.2,320,7.4},
		{"Ford Fusion", "USA",9.7,210,6.8},
		{"Subaru Impreza", "Japan",8.5,150,7.9},
		{"BMW M5", "Germany",12.1,500,6.9},
		{"Toyota Camry Hybrid", "Japan",7.0,205,9.3},
		{"Audi A4", "Germany",8.8,255,8.9},
		{"Dodge P.O.S.", "USA", 11.7,233.0,4.1}
		});

	cout << "LIST OF CARS:" << "\n";
	for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
		cout << _car.Car_Name << ", " << _car.Country_Origin << "." << "\n";
		});
	cout << "\n";

	processCars(Car);

	cout << "\n";
	cout << "LIST OF CARS ORDERED BY RATING:" << "\n";
	for_each(Car.begin(), Car.end(), [](const Rate_Cars& _car) {
		cout << _car.Car_Name << ", " << _car.Country_Origin << "." << "\n";
		});

	return 0;
}