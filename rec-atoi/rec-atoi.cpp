#include <iostream>

using namespace std;

int rec_atoi(const char* s, uint32_t len, uint32_t multiplier)
{
    if (len == 1)
        return (s[len-1] - '0') * multiplier;
    int value = s[len - 1] - '0';
    return (value * multiplier) + rec_atoi(s, len - 1, multiplier*10);
}

int main(int argc, char** argv)
{
    int value = rec_atoi("1234", 4, 1);
    cout << value << endl;
    return 0;
}
