#include <iostream>
#include <map>
#include <algorithm>
#include <list>
#include <memory>

using namespace std;

class LRUCache
{
    private:

        //order in this list represents the usage order. head is the most recently used, head - 1 is the 2nd
        //last used ... tail is the least recently used.
        list<int> _cache;
        map<int, int> _map;
        unsigned _capacity;

    public:
        LRUCache(unsigned capacity) : _capacity(capacity)
        {

        }

        int get(int key)
        {
            auto it_key_val = _map.find(key);
            if (it_key_val == _map.end())
            {
                //can't find the key so return -1
                return -1;
            }

            //in this case  it's in the map, so the key should be in the list
            auto it = find(_cache.begin(), _cache.end(), key);
            if (it != _cache.end())
            {
                _cache.erase(it);
                _cache.emplace_back(key);
            }
            return it_key_val->second;
        }

        void put(int key, int val)
        {
            auto it_key_val = _map.find(key);
            if (it_key_val != _map.end())
            {
                //key already exists so remove the existing key from the list.
                auto it = find(_cache.begin(), _cache.end(), key);
                _cache.erase(it);
                //insert it with the new value
                _map[key] = val;
                //place the key at the back.
                _cache.emplace_back(key);
            }
            else
            {
                while (_capacity <= _cache.size())
                {
                    //evict least recently used. This is the item at the beginning of the list.
                    int key_to_erase = _cache.front();
                    _cache.pop_front();
                    _map.erase(key_to_erase);
                }
                auto it_key_val = _map.find(key);
                //key not in map so insert it with the new value
                _map[key] = val;
                //place the key at the back.
                _cache.emplace_back(key);
            }
        }

        void print_cache()
        {
            for (auto item : _cache)
            {
                //cout << "(key = " << item.first << " val = " << item.second << ") ";
                cout << "key = " << item;
            }
            cout << endl;
        }
};

int main(int argc, char** argv)
{
    LRUCache lru(2);

    cout << lru.get(2) << endl;
    lru.put(2,6);
    lru.print_cache();
    cout << lru.get(1) << endl;
    lru.put(1,5);
    lru.print_cache();
    lru.put(1,2);
    lru.print_cache();
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;


    return 0;
}
