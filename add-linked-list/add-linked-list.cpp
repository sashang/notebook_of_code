#include <iostream>
#include <list>

using namespace std;

list<int> add(list<int>& l1, list<int>& l2)
{
    list<int>::reverse_iterator it1 = l1.rbegin();
    list<int>::reverse_iterator it2 = l2.rbegin();
    list<int> result;
    int carry = 0;

    while (it1 != l1.rend() && it2 != l2.rend())
    {
        int val = *it1 + *it2 + carry;
        carry = val/10;
        int rem = val%10;
        result.push_front(rem);
        ++it1;
        ++it2;
    }
    while (it1 != l1.rend())
    {
        int val = *it1 + carry;
        carry = val/10;
        int rem = val%10;
        result.push_front(rem);
        it1++;
    }
    while (it2 != l2.rend())
    {
        int val = *it2 + carry;
        carry = val/10;
        int rem = val%10;
        result.push_front(rem);
        it2++;
    }
    if (carry)
        result.push_front(1);
    return result;
}

int main(int argc, char** argv)
{
    list<int> l1;
    list<int> l2;
    l1.push_back(1);
    l1.push_back(0);
    l1.push_back(0);
    l2.push_back(9);
    l2.push_back(9);
    list<int> result = add(l1, l2);
    for (auto item : result)
    {
        cout << item;
    }
    return 0;
}