#include <stdio.h>
#include <stdlib.h>
#include "callbacks.h"
#include "lib.h"

/*
    Implement the callback that will be passed to your bubble_sort function to sort 
    the elements in ascending numerical order.
*/
int sorted_order(int a, int b)
{
    return a > b ? 1 : 0;
}

/*
    Implement the callback that will be passed to your bubble_sort function to sort
    the elements in descending (reverse) numerical order.
*/
int reverse_order(int a, int b)
{
    return a < b ? 1 : 0;
}

/*
    Receives an array of numbers to be sorted, the number of elements in the array,
    and a callback that specifies the order in which the numbers will be sorted.
    Your function should allocate memory to hold the sorted data and return the 
    sorted data. Call the callback as you would any other function. 
*/
int *bubble_sort(int *numbers, int n, compare_cb cmp)
{
    int swaped_position = 1;
    // int control = 1;

    while (swaped_position)
    {
        swaped_position = 0;
        int comparison;

        printf("\n\n");
        for (int i = 1; i < n; ++i)
        {
            comparison = cmp(*(numbers + i - 1), *(numbers + i));

            if (comparison == 1)
            {
                printf("\n%d %d - ", *(numbers + i - 1), *(numbers + i));
                int temp = *(numbers + i - 1);
                *(numbers + i - 1) = *(numbers + i);
                *(numbers + i) = temp;
                swaped_position = 1;
                printf("%d %d\n", *(numbers + i - 1), *(numbers + i));
            }
        }
        n--;
    }
    return numbers;
}

#ifndef TESTING
int main(void)
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int count = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr;
    printf("\nBEFORE SORT: %d %d\n", sorted_arr, count);

    sorted_arr = bubble_sort(arr, count, sorted_order);
    // sorted_arr = bubble_sort(arr, count, reverse_order);
    printf("\nAFTER SORT: %d %d\n", sorted_arr, count);

    for (int i = 0; i < count; i++)
    {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    return 0;
}
#endif
