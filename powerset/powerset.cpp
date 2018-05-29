#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


//compute the powerset subsets of a set
//[a,b,c] -> [[], [a], [b], [c], [a,b], [a,c], [b,c], [a,b,c]]

using namespace std;

vector<vector<uint32_t>> powerset(vector<uint32_t> input, int idx)
{
    if (idx == -1)
    {
        return vector<vector<uint32_t>>({{}});
    }
    vector<vector<uint32_t>> prev_set = powerset(input, idx - 1);
    vector<vector<uint32_t>> new_set(prev_set);
    for (auto item : prev_set)
    {
        item.emplace_back(input[idx]);
        new_set.emplace_back(item);
    }
    return new_set;
}

int main(int argc, char** argv)
{
    vector<uint32_t> input({1,2,3});
    vector<vector<uint32_t>> result = powerset(input, 2);
    for_each(result.begin(), result.end(),
            [](const vector<uint32_t>& subset)
            {
                for_each(subset.begin(), subset.end(), [](const uint32_t& item) { cout << item << " ";});
                cout << endl;
            });
    return 0;
}
