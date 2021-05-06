//Array.h
#pragma once
#include <iostream>
using namespace std;
class Array
{
public:
private:
	static const size_t minsize = 10; //min size
	size_t Size; 
	size_t Count; //kiskist element
	size_t First; 
	double* elems; 
public:
	Array(const size_t& n = minsize)	throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const double* first, const double* last) throw(bad_alloc, invalid_argument);
	Array(const size_t first, const size_t last) throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);
	// iteratory
	double* begin() { return elems; }
	const double* begin() const { return elems; }
	double* end() { return elems + Count; }
	const double* end() const { return elems + Count; }
	size_t size() const; 
	bool empty() const;
	size_t capacity() const; 
	void resize(size_t newsize) 
		throw(bad_alloc);
	// dostyp elements
	double& operator[](size_t) throw(out_of_range);
	const double& operator[](size_t) const throw(out_of_range);
	double& front() { return elems[0]; }
	const double& front() const { return elems[0]; }
	double& back() { return elems[size() - 1]; }
	const double& back() const { return elems[size() - 1]; }
	void push_back(const double& v); //add
	void pop_back(); //delete
	void clear() { Count = 0; } 
	void swap(Array& other); 
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);
    void generalTask() throw(bad_alloc);
	void Mul();
	void Print();
	double Min() ;
	double Sum() const;
	double arithmetic() const;
};

