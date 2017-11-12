#include <iostream>
#include <vector>

using namespace std;

int count_step_combinations(int steps, int max)
{
    int result = 0;
    if (steps < 0)
        return 0;
    if (steps == 0)
        return 1;

    for (int i = 1; i <= max; ++i)
    {
        result += count_step_combinations(steps - i, max);
    }
    return result;
}

//fixed at 3 steps
int count_ways(int n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return count_ways(n - 1) + count_ways(n-2) + count_ways(n - 3);
}

int main(int argc, char** argv)
{
    cout << count_step_combinations(5, 3) << endl;
    cout << count_ways(5) << endl;
    return 0;
}
