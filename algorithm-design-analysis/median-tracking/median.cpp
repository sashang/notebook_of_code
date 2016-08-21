#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <fstream>
#include <map>
#include <memory>
#include <array>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;

//the min of all maximum values
priority_queue<int, vector<int>, greater<int>> min_heap;

//the max of all minimum values
priority_queue<int> max_heap;

void print_heap(priority_queue<int, vector<int>, greater<int>>& heap)
{
    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
    cout << endl;
}
void print_heap(priority_queue<int>& heap)
{
    while (!heap.empty())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    multiset<long> numbers;
    queue<long> target;
    if (argc < 2)
    {
        printf("Usage: ./median <filename>\n");
        return 1;
    }
    fstream f(argv[1]);
    string line;
    int total = 0;
    while (getline(f, line))
    {
        int u;
        stringstream ss(line);
        ss >> u;
        if (min_heap.empty() && max_heap.empty())
        {
            min_heap.push(u);
            total += u;
        }
        else if (!min_heap.empty() && max_heap.empty())
        {
            if (min_heap.top() < u)
            {
                int v = min_heap.top();
                min_heap.pop();
                min_heap.push(u);
                max_heap.push(v);
                total += max_heap.top();
            }
            else
            {
                max_heap.push(u);
                total += u;
            }
        }
        else
        {
            if (min_heap.size() == max_heap.size())
            {
                if (u < max_heap.top())
                {
                    max_heap.push(u);
                    total += max_heap.top();
                }
                else
                {
                    min_heap.push(u);
                    total += min_heap.top();
                }
            }
            else if (min_heap.size() < max_heap.size())
            {
                if (u < max_heap.top())
                {
                    max_heap.push(u);
                    int temp = max_heap.top();
                    max_heap.pop();
                    min_heap.push(temp);
                    assert(min_heap.size() == max_heap.size());
                }
                else
                {
                    min_heap.push(u);
                    assert(min_heap.size() == max_heap.size());
                }
                total += max_heap.top();
            }
            else //min_heap has more elements
            {
                if (u < max_heap.top())
                {
                    max_heap.push(u);
                    assert(min_heap.size() == max_heap.size());
                }
                else
                {
                    min_heap.push(u);
                    int temp = min_heap.top();
                    min_heap.pop();
                    max_heap.push(temp);
                    assert(min_heap.size() == max_heap.size());
                }
                total += max_heap.top();
            }
        }
    }
    cout << "result: " << total % 10000 << endl;

}
