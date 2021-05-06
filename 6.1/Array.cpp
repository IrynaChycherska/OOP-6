//Array.cpp
#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;
Array::Array(const size_t& n)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new double[Size];
	for (unsigned int i = 0; i < Size; i++)
		elems[i] = 0;
}
Array::Array(const double* first, const double* last)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const size_t first, const size_t last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new double[Size])
{
	for (unsigned int i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}
Array& Array::operator =(const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}
Array::~Array()
{
	delete[]elems;
	elems = 0;
}
void Array::push_back(const double& v)
{
	if (Count == Size) // no space
		resize(Size * 2); // increase capacity
	elems[Count++] = v;
}
double& Array::operator [](size_t index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}
const double& Array::operator [](size_t index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}
void Array::resize(size_t newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		double* data = new double[newsize];
		for (size_t i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}
void Array::swap(Array& other)
{
	std::swap(elems, other.elems); // standart func of exchange
	std::swap(Size, other.Size);
}
size_t Array::capacity() const
{
	return Size;
}
size_t Array::size() const
{
	return Count;
}
bool Array::empty() const
{
	return Count == 0;
}
ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		out << tmp[j] << " ";
	out << endl;
	return out;
}
istream& operator >>(istream& in, const Array& tmp)
{
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << "arr[" << i << "] = ";
		in >> tmp[i];
	}
	return in;
}
void Array::pop_back() throw(bad_alloc)
{
	if (size() > 0)
	{
		double* tmp = new double[size() - 1];
		for (size_t i = 0; i < size() - 1; ++i)
			tmp[i] = elems[i];
		delete[] elems;
		elems = tmp;
		Size = size() - 1;
	}
}
double Array::Sum() const
{
	int sum = 0;

	for (int i = 0; i < size(); i++)
		sum += elems[i];

	return sum;
}
double Array::arithmetic() const
{
	return abs(Sum() / capacity());
}
void Array::Print()
{
	for (int i = 0; i < size(); i++)
		cout << elems[i] << " ";
	cout << " ";
}
double Array::Min() 
{
	double Min = elems[0];

	for (int i = 0; i < size(); i++)
	{
		if (elems[i] < Min)
		{
			Min = elems[i];
		}
	}
	return Min;
}
void Array::Mul()
{
	double min = this->Min();
	for ( int i = 0; i < size(); i++)
	{
			elems[i] = elems[i] * min;
	}
}
void Array::generalTask() throw(bad_alloc)
{
	push_back(Min());
	push_back(Sum());//add sum to the back
	push_back(arithmetic());
}