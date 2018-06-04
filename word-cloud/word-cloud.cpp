#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

unordered_map<string, uint32_t> table;

bool is_punctuation_or_whitespace(char c)
{
    return ispunct(c) || isspace(c);
}

uint32_t scan_to_word_end(const string& words, uint32_t current)
{
    while (current < words.size() && !is_punctuation_or_whitespace(words[current]))
    {
        current++;
    }
    return current;
}

uint32_t scan_to_word_start(const string& words, uint32_t current)
{
    while (current < words.size() && is_punctuation_or_whitespace(words[current]))
    {
        current++;
    }
    return current;
}

void build_word_cloud(const string& words)
{
    uint32_t begin = 0;
    uint32_t end = 0;
    while (begin < words.size())
    {
        begin = scan_to_word_start(words, begin);
        end = scan_to_word_end(words, begin);
        string word(words.substr(begin, end - begin));
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        table[word]++;
        begin = end;
        begin++;
    }


}
int main(int argc, char** argv)
{
    vector<string> test_strings({
            {"After beating eggs, Dana read the next step."},
            {"Add milk and eggs, then add flour and sugar."},
            {"We came, we saw, we conquered...then we ate Bill's (Mille-Feuille) cake."},
            {"The bill came to five dollars."}
            });
    
    for_each(test_strings.begin(), test_strings.end(), build_word_cloud);
    for (auto item : table)
    {
        cout << item.first << ": " << item.second << endl;
    }
    return 0;
}
