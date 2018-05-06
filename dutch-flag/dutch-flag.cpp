#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

typedef tuple<vector<int>, int> TInput;

vector<int> dnf_partition(TInput&& input)
{
    vector<int> arr;
    int pivot_idx;
    tie(arr, pivot_idx) = input;
    vector<int> result(arr);
    if (arr.size() <= 1)
        return result;

    int start = 0;
    int end = arr.size() - 1;
    int idx = 0;

    while (idx < arr.size())
    {
        if (arr[idx] < arr[pivot_idx])
            result[start++] = arr[idx++];
        else if (arr[idx] > arr[pivot_idx])
            result[end--] = arr[idx++];
        else
            idx++;
    }
    while (start <= end)
    {
        result[start++] = arr[pivot_idx];
    }
    return result;
}


int main(int argc, char** argv)
{
    vector<TInput> input = {make_tuple(vector<int>({3,1,2,2,4,1}), 2),
        make_tuple(vector<int>({1}),0), make_tuple(vector<int>({1,2,3}), 2),
        make_tuple(vector<int>({1,33,45,6,7}), 0)};
    function<vector<int>(TInput)> f(dnf_partition);
    vector<vector<int>> result(input.size());
    transform(input.begin(), input.end(), result.begin(), f);

    for (auto item : result)
    {
        for (auto elem : item)
            cout << elem << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
