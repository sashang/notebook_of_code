#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
    list<int> l = {1,2,1};
    l.unique();
    for(auto item:l)
    {
        cout << item;
    }
    cout << endl;
    return 0;
}
