//Name       : Inderpreet Singh Canada
//Student Id : 164132219
//Mail Id    : iparmar1@myseneca.ca
//Date       : 29 July 2022
#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void reorderIT(int arr1[], int arr2[])
{
	Stack _stack;
	Queue _queue;
	for (int i = 0; i < 18; ++i)
	{
		if (arr2[i] == 0)
		{
			do
			{
				_queue.enqueue(_stack.top());
				_stack.pop();
			} while (!_stack.isEmpty());
		}
		else
			if (arr2[i] < 0)
			{
				_queue.enqueue(arr2[i]);
			}
		if (arr2[i] > 0)
			{
				_stack.push(arr2[i]);
			}
	}
	do
	{
		_queue.enqueue(_stack.top());
		_stack.pop();
	} while (!_stack.isEmpty());

	for (int i = 0; i < 18; ++i)
	{
		arr1[i] = _queue.front();
		_queue.dequeue();
	}

}

struct compareIT
{
	bool operator()(int const& j, int const& k) const 
	{
		return j > k;
	}
};
int main() 
{
	int Array1[] = { -3,2,-1,5,1,-4,0,11,12,13,-11,-12,0,-1,-2,6,8,7 };
	int array2[18] = { 0 };

	cout << "array:    ";
	for (int i = 0; i < 18; ++i)
	{
		cout << Array1[i] << " ";
	}
	cout << endl;
	reorderIT(array2, Array1);
	cout << "newArray: ";
	for (int i = 0; i < 18; ++i) 
	{
		cout << array2[i] << " ";
	}
	cout << endl;
	sort(begin(array2), end(array2), compareIT());
	cout << "newArray sorted: ";
	for (int i = 0; i < 18; ++i) 
	{
		cout << array2[i] << " ";
	}
	cout << endl;

	return 0;
}