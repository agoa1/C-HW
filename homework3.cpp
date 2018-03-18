#include <iostream>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int numbers[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (numbers[j] > numbers[j+1])
        {
           swap(&numbers[j], &numbers[j+1]);
           swapped = true;
        }
     }


     if (swapped == false)
        break;
   }
}


void printArray(int numbers[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std:: printf("%d ", numbers[i]);

}


int main()
{
    int numbers[] = {4,9,2,1,3,4,7,8,5,0,6};
    int n = sizeof(numbers)/sizeof(numbers[0]);
    bubbleSort(numbers, n);
    std:: printf("Sorted array: \n");
    printArray(numbers, n);
    return 0;
}