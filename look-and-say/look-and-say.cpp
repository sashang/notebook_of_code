#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>


//look and say sequence is starts with 1 and then the next string in the sequence is
//one 1 [11], the next is two one [21] because you say that you saw two ones in the previous
//sequence (ignore the one/ones plural that we use in english). The next is one 2 one 1 [1211] etc..
//

using namespace std;

string scan_string(string start)
{
    string result = "";
    uint32_t count = 0;

    for (int j = 0; j < start.size(); ++j)
    {
        count = 1;
        while (j + 1 < start.size() && start[j] == start[j+1])
        {
            count++;
            j++;
        }
        result += to_string(count) + start[j];
    }
    return result;
}

string look_and_say(uint32_t n)
{
    string result = "1";
    for (int i = 0; i < n; ++i)
    {
        result = scan_string(result);
    }
    return result;
}

int main(int argc, char** argv)
{
    string result = look_and_say(8);
    cout << result << endl;
    return 0;
}
