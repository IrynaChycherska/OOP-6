#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

void print_container(const vector<int>& c)
{
    for (auto& i : c) {
        cout << i << " ";
    }
    cout << '\n';
}
bool is_odd(int i)
{
    return (i % 2) != 0;
}
bool Negative(int i)
{
    return i < 0;
}
int main()
{
    vector<int> c{ -2,-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "array:";
    print_container(c);
    c.erase(c.begin() + 2); cout << "Zero:" << endl;
    print_container(c);
    c.erase(remove_if(c.begin(), c.end(), Negative), c.end());
    cout << "Negative:" << endl;
    print_container(c);
    c.erase(remove_if(c.begin(), c.end(), is_odd), c.end());
    cout << "erase_if:" << endl;
    print_container(c);
    cout << "delete all elements";
    c.erase(c.begin(), c.end());
    print_container(c);
}