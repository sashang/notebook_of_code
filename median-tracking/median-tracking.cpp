#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    priority_queue<int, vector<int>, function<bool(int,int)>> 
        minq([](int a, int b)->bool{return a > b;});
    priority_queue<int, vector<int>, function<bool(int,int)>>
        maxq([](int a, int b) -> bool { return a < b; });
    
    while (cin.good())
    {
        int x;
        cin >> x;
        if (minq.empty() && maxq.empty())
        {
            minq.emplace(x);
            continue;
        }
        if (x > minq.top())
        {
            minq.emplace(x);
        }
        else
        {
            maxq.emplace(x);
        }
        //balance queues
        //when total number of elements is odd, minq will contain the overflow.
        if (minq.size() > maxq.size() + 1)
        {
            maxq.emplace(minq.top());
            minq.pop();
        }
        else if (maxq.size() > minq.size())
        {
            minq.emplace(maxq.top());
            maxq.pop();
        }
        cout << "median is " << (minq.size() == maxq.size() ? ((minq.top() + maxq.top()) * 0.5) : minq.top()) << endl;
    }
    return 0;
}
