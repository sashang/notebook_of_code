#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> gen_sets(int idx, vector<int> input_set)
{
    int current = 0;

    if (idx == 0)
    {
        vector<int> empty;
        return vector<vector<int>>({empty});
    }
    vector<vector<int>> sets_below;
    sets_below = gen_sets(idx-1, input_set);
    vector<vector<int>> all_sets(sets_below);
    for (auto item : sets_below)
    {
        item.emplace_back(input_set[idx-1]);
        all_sets.emplace_back(item);
    }
    return all_sets;
}

int main(int argc, char* argv[])
{
    vector<int> sets = {1,2,3,4};
    vector<vector<int>> all_subsets = gen_sets(4, sets);
    for (auto item : all_subsets)
    {
        if (item.empty())
        {
            cout << "{}";
        }
        else
        {
            cout << "{";
            for (auto elem : item)
            {
                cout << elem << ", ";
            }
            cout << "}";
        }
        cout << endl;
    }
    return 0;
}
