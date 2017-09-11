#include <iostream>
#include <array>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
    list<int> window;
    const int window_size = 3;
    array<int, 10> arr{11,2,0,192,-1,-2,33,3,4,4};


    for (auto item : arr)
    {
        cout << item << ", ";
    }
    cout << endl;
    //find the max in the window
    //basically make sure that the front/head of the window has the max value.
    for (int i = 0; i < window_size; ++i)
    {
        while (!window.empty() && arr[i] >= arr[window.back()])
        {
            window.pop_back();   
        }
        window.push_back(i);
    }
    cout << arr[window.front()] << ", ";
    //slide the window.
    for (int i = window_size; i < arr.size(); ++i)
    {
        while (!window.empty() && arr[i] >= arr[window.back()])
        {
            window.pop_back();
        }
        
        if (!window.empty() && window.front() <= i - window_size)
        {
            window.pop_front();
        }
        window.push_back(i);

        cout << arr[window.front()] << ", ";
    }

    cout << endl;
}
