#include <iostream>

using namespace std;

double pow(double x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    return x * pow(x, n-1);
}

double fast_pow(double x, int n)
{
    /**
     * Example: 
     * 2^0 = 1
     * 2^1 = 2
     * 2^2 = 2*2
     * 2^3 = 2*2^2 = 2*2^1*2^1
     * 2^4 = 2^2*2^2
     * 2^5 = 2*2^4 = 2*2^2*2^2
     * 2^6 = 2^3*2^3
     * 2^7 = 2*2^6 = 2*2^3*2^3
     */

    if (n == 0) return 1;
    if (n == 1) return x;
    int expo = n;
    if (n < 0)
    {
        expo = -n;
    }
    if (n % 2 == 0)
    {
        double temp = fast_pow(x, expo/2);
        if (n < 0)
            return 1.0/(temp * temp);
        else
            return (temp * temp);
    }
    else
    {
        double temp = fast_pow(x, expo/2);
        if (n < 0)
            return 1.0/(x * temp * temp);
        else
            return (x * temp * temp);
    }
}

int main(int argc, char** argv)
{
    cout << pow(2,4) << endl;
    cout << fast_pow(2,4) << endl;
    cout << fast_pow(2,5) << endl;
    cout << fast_pow(2,-2) << endl;
    cout << fast_pow(2,-3) << endl;
    cout << fast_pow(3,4) << endl;
}
