#include <iostream>
#include <array>
#include <bitset>

using namespace std;

template <int size> 
array<int, size> gen_array()
{
    array<int, size> result;
    for (int i = 0; i < size; i++) 
    {
        result[i] = rand()%(size/100);
    }
    return result;
}

int main(int argc, char* argv[])
{
    array<int, 1000> arr = gen_array<1000>();
    bitset<1000> bs;

    for (auto item : arr) 
    {
        if (bs[item])
        {
            cout << "duplicate value " << item << endl;
        }
        else
        {
            bs[item] = 1;
        }
    }
}
