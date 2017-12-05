#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int x = 0x3f; 
    int count = 0;
    //this flips the rightmost (lowest bit) i.e. makes it 0
    int x_minus_1 = x - 1;
    //make the rightmost bit 1
    int complement = ~x_minus_1;
    while (x & complement)
    {
        count++;
        //remove this bit from x
        x ^= (x & complement);
        x_minus_1 = x - 1;
        complement = ~x_minus_1;
        cout << "x = " << x << endl;
    }
    return count;
}
