#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Given a grid where each cell represents a cost find the minimum cost to get to the lower
 * right cell. We can only move down and right.
 *
 * For example, given the following grid,
 *
 * 10  2 30  2
 * 22 -2  9 -2
 *  2  3  3  0
 *
 * the minimum cost to get from top left to bottom right is
 * 10 + 2 + -2 + 3 + 3 + 0 = 16
 */

int min_cost_path(vector<vector<int>>& grid, size_t row, size_t col)
{
    if (row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1)
        return numeric_limits<int>::max();

    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }
    else
    {
        return grid[row][col] + min(min_cost_path(grid, row-1, col), min_cost_path(grid, row, col-1));
    }
}


int min_cost_dynamic(vector<vector<int>>& grid)
{
    vector<vector<int>> cost_table(grid.size(), vector<int>(grid[0].size(), numeric_limits<int>::max()));

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (i == 0 && j == 0)
            {
                cost_table[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                cost_table[i][j] = grid[i][j] + cost_table[i][j-1];
            }
            else if (j == 0)
            {
                cost_table[i][j] = grid[i][j] + cost_table[i-1][j];
            }
            else
            {
                cost_table[i][j] = grid[i][j] + min(cost_table[i-1][j], cost_table[i][j-1]);
            }
        }
    }
    for_each(cost_table.begin(), cost_table.end(),
            [](vector<int>& row) 
            {
                for_each(row.begin(), row.end(), [](int& value)
                        {cout << value  << " ";});
                cout << endl;
            });
    cout << endl;
    return cost_table[grid.size() - 1][grid[0].size() - 1];
}

int main(int argc, char** argv)
{
    vector<vector<int>> grid({
            {10,12,30,2},
            {1,-2,0,-10},
            {2,3,3,0}
            });
    cout << "min = " << min_cost_path(grid, grid.size() - 1, grid[0].size() - 1) << endl;
    cout << "min using dynamic = " << endl << min_cost_dynamic(grid) << endl;
    return 0;
}
