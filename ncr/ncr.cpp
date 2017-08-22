#include <iostream>

using namespace std;

int ncr_map[201][201];

int n_choose_r(int n, int r)
{
    if (n > 200 || r > 200)
        return -1;
    if (r < 0 || n < 0)
        return -1;

    //if we have already computed it the value will not be -1
    if (ncr_map[n][r] != -1)
        return ncr_map[n][r];

    cout << "calculation (" << n << "," << r << ")" << endl;
    //compute the value
    int i = 0;
    int j = 0;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= r; j++)
        {
            if (ncr_map[i][j] != -1)
                continue;

            if (i == 0 || j > i)
                ncr_map[i][j] = 0;
            else if (i == 1 || j == 0)
                ncr_map[i][j] = 1;
            else if (j == 1)
            {
                ncr_map[i][j] = i;
            }
            else 
            {
                ncr_map[i][j] = ncr_map[i-1][j-1] + ncr_map[i-1][j];
            }
        }
    }
    return ncr_map[n][r];
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            ncr_map[i][j] = -1;
        }
    }
    cout << "0 c 0 = " << n_choose_r(0,0) << endl;
    cout << "0 c 1 = " << n_choose_r(0,1) << endl;
    cout << "0 c 2 = " << n_choose_r(0,2) << endl;
    cout << "1 c 0 = " << n_choose_r(1,0) << endl;
    cout << "2 c 1 = " << n_choose_r(2,1) << endl;


    cout << "5 c 1 = " << n_choose_r(5,1) << endl;
    cout << "5 c 2 = " << n_choose_r(5,2) << endl;
    cout << "5 c 5 = " << n_choose_r(5,5) << endl;
    cout << "15 c 5 = " << n_choose_r(15,5) << endl;
    return 0;
}
