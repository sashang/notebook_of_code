#include <iostream>
#include <set>
#include <string>

using namespace std;

char s[256]="all greek to me";

int main(int argc, char** argv)
{
    char* rp = s;
    char* wp = s;
    cout << s << endl;
    while (*rp != 0)
    {
        if (*rp == ' ')
        {
            rp++;
        }
        else
        {
            *wp = *rp;
            rp++; wp++;
        }
    }
    *wp = 0;
    cout << s << endl;
}
