#include <iostream>
#include <array>
#include <map>
#include <queue>
#include <algorithm>
#include <list>
#include <iterator>
#include <functional>

using namespace std;


int main(int argc, char** argv)
{
    typedef pair<string, uint32_t> TValue;
    vector<string> input = 
        {"apple", "orange", "apple", "apple", "banana",
        "orange", "pear", "pear", "pineapple", "lemon", "lemon", "apple"};   
    map<string, uint32_t> counter;

    for (auto item : input)
    {
        counter[item]++;
    }

    //sort by frequency. use a heap.
    auto comp = [&counter](const TValue& lhs, const TValue& rhs) -> bool
    {
        return counter[lhs.first] < counter[rhs.first];
    };
    priority_queue<TValue, vector<TValue>, decltype(comp)> q(comp);
    for (auto item : counter)
    {
        q.emplace(item.first, item.second);
        //cout << "Fruit: " << item.first << " count: " << item.second << endl;
    }
    while(!q.empty())
    {
        cout << q.top().second << " " << q.top().first << endl;
        q.pop();
    }
}
