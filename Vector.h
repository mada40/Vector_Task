#pragma once
class Vector
{
private:
	double* data = nullptr;
	int n = 0;
	int cap = 0;
	const int coeff = 2;

public:
	Vector();
	Vector(int _cap);
	Vector(const Vector& other);

	~Vector() { delete[] data; }

	inline Vector& operator = (const Vector& other);
	inline double operator[] (int i) const { return data[i]; }
	inline double& operator[] (int i) { return data[i]; }

	inline int size() const { return n; }
	inline int capacity() const { return cap; }
	inline void clear() { n = 0; }

	inline double front() const { if (n < 1) throw "ERROR";  return data[0]; }
	inline double back() const { if (n < 1) throw "ERROR";  return data[n - 1]; }

	inline bool empty() const{ return n == 0; }
	inline void pop_back() { if (n > 0) --n; }

	void changeCapacity(int newCap);
	void resize(int newSize);

	void push_back(double elem);
	void push_front(double elem) { insert(0, elem); }

	void insert(int i, double elem);
	void erase(int i);




};

