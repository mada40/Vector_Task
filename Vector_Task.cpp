#include <iostream>
#include <vector>
#include "Vector.h"

int main()
{
    Vector v;
	for (int i = 0; i < 32; i++)
	{
		v.push_front(-i);
		v.push_back(i);
	}

	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << std::endl;

	while (!v.empty())
	{
		std::cout << v.back() << std::endl;
		v.pop_back();
	}
}
