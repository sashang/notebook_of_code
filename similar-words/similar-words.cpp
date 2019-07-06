/*
Given a list of words (all words in the list are anagrams), return the count
of the groups of similar words. A word is similar to another if it can be
transformed with one swap of a pair of letters, to the other word For example
"arts" and "rats" are similar (swap a and r), "rast" and "rats" are similar,
therefore all 3 words can be placed in a single group. Assume all words are unique (no duplicates)

For example:
input: ["arts", "rats", "rast"]
output: 1

input: ["arts", "rats", "rast", "star"]
output: 2
 */

#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>

using namespace std;

bool is_one_swap(const string& a, const string& b)
{
    //can assume words are equal length since they are anagrams.
    string::size_type i = 0;
    string::size_type mark = 0;
    bool has_mark = false;
    bool maybe = false;

    for (i = 0; i < a.size(); ++i)
    {
        if (!maybe)
        {
            if (a[i] != b[i] && !has_mark)
            {
                mark = i;
                has_mark = true;
            }
            else if (a[i] != b[i] && has_mark)
            {
                if (a[i] == b[mark] && b[i] == a[mark])
                {
                    maybe = true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
    }
    return true;
}

unordered_map<string, vector<string>> graph;

void build_graph(const vector<string>& input)
{
    for (auto item : input)
    {
        vector<string> children;
        for (auto word : input)
        {
            if (word != item)
            {
                if (is_one_swap(item, word))
                {
                    children.push_back(word);
                }
            }
        }
        graph[item] = children;
    }
}

uint32_t count_connected(const vector<string>& input)
{
    uint32_t count = 0;
    unordered_set<string> mark;
    for (auto w : input)
    {
        if (!mark.count(w))
        {
            mark.insert(w);
            queue<string> q;
            q.push(w);
            while (!q.empty())
            {
                auto word = q.front();
                q.pop();
                auto children = graph[word];
                for (auto item : children)
                {
                    if (!mark.count(item))
                    {
                        mark.insert(item);
                        q.push(item);
                    }
                }
            }
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    vector<string> input({"arts", "rats", "star", "tras"});
    build_graph(input);
    cout << count_connected(input) << endl;
    return 0;
}