#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void rem_dup_string2(string& s)
{
    //remove duplicate chars from the input string.
    //using a hash table
    unordered_map<char, uint32_t> table;
    for (string::iterator it = s.begin(); it != s.end();)
    {
        if (table.find(*it) == table.end())
        {
            //char not in table
            table[*it] = 1;
            ++it;
        }
        else
        {
            //char already in table so remove from string
            it = s.erase(it);
        }
    }
}

//remove duplicated chars using a set
void rem_dup_string_set(string& s)
{
    unordered_set<char> table;
    for (string::iterator it = s.begin(); it != s.end();)
    {
        if (table.find(*it) == table.end())
        {
            table.insert(*it);
            ++it;
        }
        else
        {
            //it is in the table
            it = s.erase(it);
        }
    }
}

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
    string s1("apples and bananas");
    rem_dup_string2(s1);
    cout << s1 << endl;
    s1 = "strawberry and banana";
    rem_dup_string_set(s1);
    cout << s1 << endl;
}
