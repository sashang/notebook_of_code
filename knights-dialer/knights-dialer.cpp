#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <algorithm>

using namespace std;

/*
Imagine you place a knight chess piece on a phone dial pad. This chess piece
moves in an uppercase “L” shape: two steps horizontally followed by one
vertically, or one step horizontally then two vertically:

￼ Pay no attention to the poorly-redacted star and pound keys Suppose you
dial keys on the keypad using only hops a knight can make. Every time the
knight lands on a key, we dial that key and make another hop. The starting
position counts as being dialed.

How many distinct numbers can you dial in N hops from a particular starting
position?
*/

unordered_map<int, vector<int>> neighbours({
    {1, {6,8}},
    {2, {7,9}},
    {3, {4,8}},
    {4, {3,9,0}},
    {5, {}},
    {6, {1,7,0}},
    {7, {2,6}},
    {8, {1,3}},
    {9, {2,4}},
    {0, {4,6}}
});

int count_sequences(int start, int hops)
{
    if (hops == 0)
        return 1;
    int count = 0;
    for (auto next : neighbours[start])
    {
        count = count + count_sequences(next, hops - 1);
    }
    return count;
}

vector<vector<int>> build_sequence(int start, int hops)
{
    if (hops == 0)
        return {{start}};
 
    vector<vector<int>> new_seq;
    for (auto next : neighbours[start])
    {
        auto prev = build_sequence(next, hops - 1);
        for (auto item : prev)
        {
            item.emplace_back(start);
            new_seq.emplace_back(item);
        }
    }
    return new_seq;
}

void print_seq(const vector<vector<int>>& seq)
{
    for_each(seq.begin(), seq.end(), 
        [](const vector<int>& item)
        {
            copy(item.begin(), item.end(), ostream_iterator<int>(cout, " "));
            cout<<endl;
        });
}

uint32_t count_seq_dyn(int start, int hops)
{
    vector<int> prior(10, 1);
    vector<int> current(10, 0);

    if (hops < 1)
        return 1;

    while (hops)
    {
        current = vector<int>(10, 0);
        for (vector<int>::size_type pos = 0; pos < current.size(); ++pos)
        {
            for (auto item : neighbours[pos])
                current[pos] += prior[item];
        }
        prior = current;
        hops--;
    }
    return current[start];
}

int main(int argc, char* argv[])
{

    cout << "recursive: " << count_sequences(6, 1) << endl;
    cout << "dyn: " << count_seq_dyn(6, 1) << endl;
    auto seq = build_sequence(6, 1);
    print_seq(seq);
    cout << "rec: " << count_sequences(6, 2) << endl;
    cout << "dyn: " <<  count_seq_dyn(6, 2) << endl;
    seq = build_sequence(6, 2);
    print_seq(seq);
    cout << "rec: " << count_sequences(6, 5) << endl;
    cout << "dyn: " <<  count_seq_dyn(6, 5) << endl;

    cout << "rec: " << count_sequences(5, 1) << endl;
    cout << "dyn: " <<  count_seq_dyn(5, 1) << endl;
    return 0;
}