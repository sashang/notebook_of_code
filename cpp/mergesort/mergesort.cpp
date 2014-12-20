#include <iostream>
#include <stdint.h>
#include <stdio.h>

using namespace std;

void print_array(int* arr, uint32_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergesort_helper(int* arr, const uint32_t p, const uint32_t q, const uint32_t r)
{
    uint32_t lower_len = q - p + 1;
    uint32_t upper_len = r - q;
    int* lower = new int[lower_len];
    int* upper = new int[upper_len];
    
    for (int i = 0; i < lower_len; i++)
    {
        lower[i] = arr[i + p];
    }
    for (int j = 0; j < upper_len; j++)
    {
        upper[j] = arr[j + q + 1];
    }
    int k = 0;
    int i = 0;
    int j = 0;
    printf("upper = "); print_array(upper, upper_len);
    printf("lower = "); print_array(lower, lower_len);
    while (k < lower_len + upper_len)
    {
        if (i < lower_len && (j >= upper_len || lower[i] < upper[j]))
        {
            arr[p + k] = lower[i];
            i++;
        }
        else
        {
            arr[p + k] = upper[j];
            j++;
        }
        k++;
    }
    
    delete lower;
    delete upper;
}


void mergesort(int* arr, uint32_t start_idx, uint32_t end_idx)
{
    if (start_idx == end_idx)
    {
        return;
    }
    uint32_t size = end_idx - start_idx + 1;
    uint32_t mid = (start_idx + end_idx)/2;
    mergesort(arr, start_idx, mid);
    print_array(arr, size);
    mergesort(arr, mid + 1, end_idx);
    print_array(arr, size);
    mergesort_helper(arr, start_idx, mid, end_idx);
}

int main(int argc, char** argv)
{
    int arr[] = {3,2,-1,8,10,-7,1,0,-2,-3,9};
    uint32_t size = sizeof(arr)/sizeof(int);
    mergesort(arr, 0, size - 1);
    print_array(arr, size);
}

