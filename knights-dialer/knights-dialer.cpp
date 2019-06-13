#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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

int main(int argc, char* argv[])
{
    cout << count_sequences(6, 2) << endl;
    cout << count_sequences(5, 2) << endl;
    auto seq = build_sequence(6, 2);
    for (auto item1 : seq)
    {
        for (auto item2 : item1)
        {
            cout << item2 << " ";
        }
        cout << endl;
    }
    return 0;
}