#include <iostream>
#include <utility>
#include <sstream>
#include <map>
#include <array>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> cave;

class Coordinate
{
    public:
        int _row, _col;
        Coordinate(int x, int y) : _row(x), _col(y) {}
        Coordinate(const Coordinate& c) : _row(c._row), _col(c._col) {}
        bool operator==(const Coordinate& rhs)
        {
            return _row == rhs._row && _col == rhs._col;
        }

        Coordinate operator+(const Coordinate& rhs)
        {
            return Coordinate(_row + rhs._row, _col + rhs._col);
        }
};

bool is_coordinate_valid(const Coordinate& c)
{
    return (c._row >= 0 && c._row < cave.size() &&
            c._col >= 0 && c._col < cave[c._row].size()
            && cave[c._row][c._col] > 0);
}

void print_cave()
{
    for (auto row : cave)
    {
        for (auto number : row)
        {
            cout << number << " ";
        }
        cout << endl;
    }
}

void print_locations(const map<int, Coordinate>& locations)
{
    for (auto item : locations)
    {
        cout << item.first << " at " << item.second._row << "," << item.second._col << endl;
    }
}

void make_location_map(map<int, Coordinate>& locations)
{
    for (int i = 0; i < cave.size(); ++i)
    {
        for (int j = 0; j < cave[i].size(); ++j)
        {
            if (cave[i][j] > 1)
            {
                Coordinate c(i, j);
                locations.insert(make_pair(cave[i][j], c));
            }
        }
    }
}

int find_shortest_path(Coordinate start, Coordinate target)
{
    int cost = 0;
    //use a que to store the neighbouring chambers
    queue<Coordinate> locations_to_visit;
    stack<Coordinate> path;
    const array<Coordinate, 4> delta{{{1,0}, {-1,0}, {0,1}, {0,-1}}};
    locations_to_visit.emplace(start);
    path.emplace(start);
    int next_count_neighbours = 0;
    int current_count_neighbours = 1;
    while (!locations_to_visit.empty())
    {
        Coordinate current(locations_to_visit.front());
        locations_to_visit.pop();
        if (current == target)
        {
            return cost;
        }
        for (const auto& item : delta)
        {
            Coordinate neighbour(current + item);
            if (is_coordinate_valid(neighbour))
            {
                locations_to_visit.emplace(neighbour);
                next_count_neighbours++;
            }
        }
        current_count_neighbours--;
        if (current_count_neighbours == 0)
        {
            cost++;
            current_count_neighbours = next_count_neighbours;
            next_count_neighbours = 0;
        }
    }
}

int main(int argc, char** argv)
{
    int rows = 0;
    for (string line; getline(cin, line);)
    {
        vector<int> row;
        stringstream ss(line);
        while (ss.good())
        {
            int val = 0;
            ss >> val;
            row.emplace_back(val);
        }
        cave.emplace_back(row);
    }
    map<int, Coordinate> locations;
    make_location_map(locations);
    print_locations(locations);
    for (auto item : locations)
    {
        unsigned int cost = 0;
        Coordinate start(0,0);
        unsigned int minimum = 0xffffffff;
        int dist = find_shortest_path(start, item.second); 
        cout << "Distance to (" << item.second._row << ", " << item.second._col << "): " << dist << endl;
    }

    return 0;
}
