//Source.cpp
#include <iostream>
#include <string>
using namespace std;
template <class T> 
class massif
{
	T* v; 
	int size; 
public:
	massif(int newsize); 
	massif(massif&);
	~massif(); 
	T& operator [] (int index); // індексування
	massif& operator = (const massif&); // присвоєння
	friend ostream& operator << <>(ostream&, massif&); 
	friend istream& operator >> <>(istream&, massif&); 
};
template <class T>
massif<T>::massif(int newsize) 
{
	v = new T[size = newsize]; 
	for (int i = 0; i < size; i++) 
		v[i] = T();
}
template <class T>
massif<T>::massif(massif<T>& x) 
{
	v = new T[size = x.size]; 
	for (int i = 0; i < size; i++) 
		v[i] = x.v[i];
}
template <class T>
massif<T>::~massif()
{delete[] v; }
template <class T>
T& massif<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];
}
template <class T>
massif<T>& massif<T>::operator = (const massif<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, massif<T>& x)
{
	cout << "Input " << x.size << " elements of massif" << endl;
	for (int i = 0; i < x.size; i++) 
	    {cout << "element[" << i << "] = ? "; is >> x.v[i];}
	return is;
}
template <class T>
ostream& operator << (ostream& os, massif<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	    os << endl;
    return os;
}
int main()
{
	try
	{
		massif<int> V(5), U(5);
		cin >> V;
		cin >> U;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
