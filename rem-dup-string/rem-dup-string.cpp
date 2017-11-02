#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    string s("aaabddd");
    string::iterator it_read;
    string::iterator it_write;
    set<char> letters;

    it_read = s.begin();
    it_write = s.begin();
    while (it_read != s.end())
    {
        if (letters.find(*it_read) != letters.end())
        {
            s.erase(it_read);
        }
        else
        {
            letters.insert(*it_read);
            it_read++;
        }
    }
    cout << s << endl;
}
