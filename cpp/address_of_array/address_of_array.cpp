#include <stdio.h>

//shows that taking the address of the array is the same
//as using it as a pointer.
int main(int argc, char** argv)
{
	int arr[10];
	printf("%p\n", arr);
	printf("%p\n", &arr);
}

