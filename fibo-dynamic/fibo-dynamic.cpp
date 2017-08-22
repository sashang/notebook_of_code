#include <iostream>

using namespace std;

int fibbo(int n)
{
    int table[n+1];
        
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main(int argc, char* argv[])
{
    cout << "fibbo(2) = " << fibbo(2) << endl;
    cout << "fibbo(3) = " << fibbo(3) << endl;
    cout << "fibbo(4) = " << fibbo(4) << endl;
    cout << "fibbo(6) = " << fibbo(6) << endl;
    cout << "fibbo(8) = " << fibbo(8) << endl;
    cout << "fibbo(9) = " << fibbo(9) << endl;
    return 0;
}
