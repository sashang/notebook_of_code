#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <array>

using namespace std;

template<int size>
vector<int> comp_ordering(array<array<int, size>, size>& grid)
{
    vector<int> result;
    array<array<int, 2>, 4> shift = {{{0,1}, {1,0}, {0,-1}, {-1,0}}};
    int dir = 0;
    int x = 0;
    int y = 0;
    result.resize(size*size);
    for (int i = 0; i < size*size; i++)
    {
        result[i] = grid[x][y];
        grid[x][y] = 0; //mark that we have used this location.
        x += shift[dir][0];
        y += shift[dir][1];
        if (x < 0 || x >= size || y < 0 || y >= size || grid[x][y] == 0)
        {
            //reset x and y
            x -= shift[dir][0];
            y -= shift[dir][1];
            //change dir
            dir = (dir + 1)%4;
            //using the new direction
            x += shift[dir][0];
            y += shift[dir][1];
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    array<array<int, 5>, 5> grid = {{{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20},
        {21,22,23,24,25}}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> ordering = comp_ordering<5>(grid);
    for (auto item : ordering)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
