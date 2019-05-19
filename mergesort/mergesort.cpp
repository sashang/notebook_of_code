#include <iostream>
#include <vector>
#include <utility>
#include <vector>

using namespace std;

void print(const vector<int>& input)
{
    for (auto item : input)
    {
        cout << item << " ";
    }
    cout << endl;
}

vector<int> merge(const vector<int>& left, const vector<int>& right)
{
    vector<int> result(left.size() + right.size());
    vector<int>::const_iterator it_left = left.begin();
    vector<int>::const_iterator it_right = right.begin();
    vector<int>::iterator it_result = result.begin();
    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            *it_result++ = *it_left++;
        }
        else
        {
            *it_result++ = *it_right++;
        }
    }
    while (it_left != left.end())
    {
        *it_result++ = *it_left++;
    }
    while (it_right != right.end())
    {
        *it_result++ = *it_right++;
    }
    return result;
}

vector<int> mergesort(const vector<int>& input)
{
    if (input.empty() || input.size() == 1)
    {
        return input;
    }
    int start = 0;
    int end = input.size();
    int mid = (end - start)/2;
    vector<int> left = mergesort(vector<int>(input.begin(), input.begin() + mid));
    vector<int> right = mergesort(vector<int>(input.begin() + mid, input.end()));
    return merge(left, right);
}


int main(int argc, char* argv[])
{
    vector<int> result;
    vector<int> v({1,2,4,5,6});
    result = mergesort(v);
    print(result);
    vector<int> v1({2,1});
    result = mergesort(v1);
    print(result);
    vector<int> v2({2,1,83,22,23});
    result = mergesort(v2);
    print(result);
    return 0;
}
