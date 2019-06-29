#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int min_dist(string word1, string word2) {
    std::vector<std::vector<int>> arr;
    arr.resize(word1.size());
    for (auto& item : arr)
    {
        item.resize(word2.size());
    }


    if (word1[0] == word2[0])
    {
        arr[0][0] = 0;
    }
    else
    {
        arr[0][0] = 1;
    }

    for (int i = 1; i < word1.size(); i++)
    {
        if (word1[i] == word2[0])
            arr[i][0] = arr[i-1][0];
        else
            arr[i][0] = arr[i-1][0] + 1;
    }

    for (int j = 1; j < word2.size(); j++)
    {
        if (word1[0] == word2[j])
            arr[0][j] = arr[0][j-1];
        else
            arr[0][j] = arr[0][j-1] + 1;
    }

    for (int i = 1; i < word1.size(); i++)
    {
        for (int j = 1; j < word2.size(); j++)
        {
            if (word1[i] == word2[j])
            {
                arr[i][j] = arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = std::min(arr[i-1][j-1], std::min(arr[i-1][j], arr[i][j-1])) + 1;
            }
        }
    }

    return arr[word1.size()-1][word2.size()-1];
}

int min_dist_recurse(string word1, int idx1, string word2, int idx2)
{
    if (idx1 >= word1.size() && idx2 >= word2.size())
        return 0;
    else if (idx1 >= word1.size())
        return word2.size() - idx2;
    else if (idx2 >= word2.size())
        return word1.size() - idx1;

    if (word1[idx1] == word2[idx2])
        return min_dist_recurse(word1, idx1 + 1, word2, idx2 + 1);

    return 1 + std::min(min_dist_recurse(word1, idx1, word2, idx2 + 1), std::min(min_dist_recurse(word1, idx1+1, word2, idx2), min_dist_recurse(word1, idx1+1, word2, idx2+1)));
}

int main(int argc, char**)
{
    cout << min_dist("a", "c") << endl;
    cout << min_dist("a", "a") << endl;
    cout << min_dist("a", "ab") << endl;
    cout << min_dist("ac", "ab") << endl;
    cout << min_dist("ab", "ab") << endl;
    cout << min_dist("abc", "abd") << endl;
    cout << min_dist("abz", "abgh") << endl;

    cout << endl << "Using recursive function" << endl;
    cout << min_dist_recurse("a", 0, "c", 0) << endl;
    cout << min_dist_recurse("a", 0, "a", 0) << endl;
    cout << min_dist_recurse("a", 0, "ab", 0) << endl;
    cout << min_dist_recurse("ac",0, "ab", 0) << endl;
    cout << min_dist_recurse("ab", 0, "ab", 0) << endl;
    cout << min_dist_recurse("abc", 0, "abd", 0) << endl;
    cout << min_dist_recurse("abz", 0, "abgh", 0) << endl;
    return 0;
}

