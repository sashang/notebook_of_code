#include <iostream>
#include <array>
#include <bitset>

using namespace std;

class Bitset
{
    private:
        int _size;
        int* _arr;

    public: 
        Bitset(int size) : _size(size)
        {
            int bits_in_int = sizeof(int)*8;
            _arr = new int[size/bits_in_int];
        }

        ~Bitset()
        {
            delete[] _arr;
        }

        void clear(int position)
        {
            int bits_in_int = sizeof(int)*8;
            int idx = position/bits_in_int;
            int offset = position % bits_in_int;
            int mask = ~(0x1 << offset);
            _arr[idx] = _arr[idx] & mask;
        }

        void set(int position)
        {
            int bits_in_int = sizeof(int)*8;
            int idx = position/bits_in_int;
            int offset = position % bits_in_int;
            int mask = 0x1 << offset;
            _arr[idx] = _arr[idx] | mask;
        }

        bool get(int position) 
        {
            int bits_in_int = sizeof(int)*8;
            int idx = position/bits_in_int;
            int offset = position % bits_in_int;
            int mask = 0x1 << offset;
            return _arr[idx] & mask;
        }
};

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

    Bitset mybs(10);
    cout << "pos 4: " << mybs.get(4) << endl;
    mybs.set(4);
    cout << "pos 4: " << mybs.get(4) << endl;
    mybs.clear(4);
    cout << "pos 4: " << mybs.get(4) << endl;
}
