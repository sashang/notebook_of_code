// cake-thief.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

class CakeType
{
public:
    size_t size;
    uint32_t value;

    CakeType(size_t w = 0, uint32_t v = 0) :
        size(w),
        value(v)
    {
    }
};

uint32_t max_value(const vector<CakeType>& cake_types, uint32_t capacity)
{
    if (capacity == 0)
    {
        return 0;
    }
    uint32_t value = 0;
    for (auto item : cake_types)
    {
        if (item.size <= capacity)
        {
            value = std::max(value, item.value + max_value(cake_types, capacity - item.size));
        }
    }
    return value;
}

uint32_t max_value_memo(const vector<CakeType>& cake_types, uint32_t capacity)
{
    static vector<int> memo(capacity + 1, -1);

    if (capacity == 0)
    {
        memo[0] = 0;
        return memo[0];
    }
    if (memo[capacity] != -1)
    {
        return memo[capacity];
    }
    uint32_t value = 0;
    for (auto item : cake_types)
    {
        if (item.size <= capacity)
        {
            value = std::max(value, item.value + max_value(cake_types, capacity - item.size));
        }
    }
    memo[capacity] = value;
    return value;
}


int main()
{
    vector<CakeType> cake_types({ CakeType(7, 160), CakeType(3,90),
            CakeType(2,15) , CakeType(5,20), CakeType(10,100), CakeType(2,20)
            });
    cout << max_value(cake_types, 20) << endl;
    cout << max_value_memo(cake_types, 20) << endl;
    cin.get();
    return 0;
}

