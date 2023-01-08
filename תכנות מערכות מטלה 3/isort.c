/*
8.1.2023
Neta Cohen
325195774
WH3
*/

#include <stdio.h>

#define ARR_SIZE 50


// This function assumes that arr points on i+1 more values
void shift_elements(int* arr, int i)
{
    for (int j = i-1; j >= 0; j--)
    {
        *(arr + j + 1) = *(arr + j);
    }
}


void insertion_sort(int *arr, int len)
{
     for (int i = 0; i < len ; i++)
     {
        int temp = *(arr+i);
        int j = 0;
          while (*(arr+j) < temp && j < i){
            j++;
          }
            shift_element(arr+j, i-j);
            *(arr+j) = temp;
     }
}

int main() 
{
	int arr[ARR_SIZE] = {0};
    // Getting the array values
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d",(arr + i));
    }
    
	//sorting the array
	insertion_sort(arr, ARR_SIZE);

    // Printing the array
	for(int i = 0; i<ARR_SIZE; i++) 
    {
		printf("%d,", *(arr + i));
	}
	printf("\n");

    return 0;
}