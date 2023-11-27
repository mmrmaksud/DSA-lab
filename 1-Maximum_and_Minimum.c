// 1. Write a program to find the maximum and minimum values from a given array.

/*
Algorithm:
Largest Element in Array
Step 1: Set K: = 1, LOC: = 1 and MAX: = DATA [1]
Step 2: Set K: = K+1
Step 3: If K>N, then:
            Write: LOC, MAX and Exit.
Step 4: If MAX<DATA[K], then:
            Set LOC: = K and MAX: =DATA[K]
Step 5: Go to Step 2.

Smallest Element in Array
Step 1: Set K: = 1, LOC: = 1 and MIN: = DATA [1]
Step 2: Set K: = K+1
Step 3: If K>N, then:
            Write: LOC, MIN and Exit.
Step 4: If MIN>DATA[K], then:
            Set LOC: = K and MIN: =DATA[K]
Step 5: Go to Step 2.
*/

// Source Code:

#include <stdio.h>
int main()
{
    int a[1000], i, n, min, max;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    printf("Enter elements in array : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    min = max = a[0];
    for (i = 1; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }
    printf("Minimum of array is : %d", min);
    printf("\nMaximum of array is : %d", max);

    return 0;
}