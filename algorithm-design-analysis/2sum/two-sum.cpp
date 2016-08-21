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

using namespace std;

void print_numbers(const multiset<long>& numbers)
{
    for (auto n : numbers)
    {
        cout << n << endl;
    }
}

void gen_target(queue<long>& target, int range_min, int range_max)
{
    for (int i = range_min; i < range_max + 1; i++)
    {
        target.push(i);
    }
}

int count_two_sums(multiset<long>& numbers, queue<long>& target)
{
    //find starting indices i and j
    int i =0;
    int j = numbers.size() - 1;
    int result = 0;
    bool flag_i = false;
    bool flag_j = false;
    int i_mark = 0;
    int j_mark = j;
    while (!target.empty())
    {
        long t = target.front();
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            long x = *it;
            long y = t - x;
            auto search = numbers.find(y);
            if (search != numbers.end() && search != it)
            {
                cout << x << " + " << y << " = "  << t << endl;
                result++;
                //numbers.erase(it);
                break;
            }
        }
        target.pop();
    }
    return result;
}


void check_numbers(multiset<long>& numbers)
{
    for (auto n : numbers)
    {
        if (n >= -10000 && n <= 10000)
        {
            cout << "yes" << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    multiset<long> numbers;
    queue<long> target;
    if (argc < 4)
    {
        printf("Usage: ./two-sum <filename> range-min range-max\n");
        return 1;
    }
    fstream f(argv[1]);
    string line;
    int range_min;
    int range_max;
    stringstream ss1(argv[2]);
    stringstream ss2(argv[3]);
    ss1 >> range_min;
    ss2 >> range_max;
    cout << "[" << range_min << "," << range_max << "]" << endl;
    while (getline(f, line))
    {
        long u;
        stringstream ss(line);
        ss >> u;
        numbers.insert(u);
    }
    gen_target(target, range_min, range_max);
    int result = count_two_sums(numbers, target);
    cout << "result: " << result << endl;
}
