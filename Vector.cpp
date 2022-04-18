#include "Vector.h"
#include <iostream>
Vector::Vector()
{
	n = 0;
	data = nullptr;
}

Vector::Vector(int _cap)
{
	n = _cap;
	cap = _cap;
	data = new double[cap];
	for (size_t i = 0; i < cap; i++)
		data[i] = 0.;

}

Vector::Vector(const Vector& other)
{
	cap = other.cap;
	n = other.n;
	data = new double[cap];
	for (size_t i = 0; i < cap; i++)
		data[i] = other.data[i];
}

inline Vector& Vector::operator=(const Vector& other)
{
	if (this == &other) return *this;

	delete[] data;

	cap = other.cap;
	n = other.n;
	data = new double[cap];
	for (size_t i = 0; i < cap; i++)
		data[i] = other.data[i];

	return *this;
}

void Vector::changeCapacity(int newCap)
{
	int minCap = cap < newCap ? cap : newCap;
	cap = newCap;
	double* newData = new double[newCap];
	for (size_t i = 0; i < minCap; i++)
		newData[i] = data[i];

	for (size_t i = minCap; i < cap; i++)
		newData[i] = 0.;

	delete[] data;
	data = newData;
}

void Vector::resize(int newSize)
{
	if (newSize > cap) changeCapacity(newSize);
	n = newSize;
}

void Vector::push_back(double elem)
{
	if (++n >= cap) changeCapacity(n * coeff);
	data[n] = elem;
}

void Vector::insert(int index, double elem)
{
	if ((n + 1) >= cap) cap = (n + 1) * coeff;
	double* newData = new double[cap];


	for (size_t i = 0; i < index; i++)
		newData[i] = data[i];

	newData[index] = elem;
	for (size_t i = index; i < n; i++)
		newData[i + 1] = data[i];

	for (size_t i = n + 1; i < cap; i++)
		newData[i] = 0.;

	n++;

	delete[] data;
	data = newData;
}

void Vector::erase(int index)
{
	if ((n + 1) >= cap) cap = (n + 1) * coeff;
	double* newData = new double[cap];


	for (size_t i = 0; i < index; i++)
		newData[i] = data[i];

	for (size_t i = index ; i < n; i++)
		newData[i] = data[i + 1];

	for (size_t i = n; i < cap; i++)
		newData[i] = 0.;

	n++;

	delete[] data;
	data = newData;
}




