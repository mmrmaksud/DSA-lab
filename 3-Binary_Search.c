// 2. Write a program to search an element in an array using binary search algorithm.

/*
Algorithm: BINARY (DATA, LB, UB, ITEM, LOC)
Step 1: Set BEG: = LB, END: = UB and MID = INT ((BEG + END)/2)
Step 2: Repeat steps 3 and 4 while BEG≤END and DATA[MID]≠ITEM.
Step 3: If ITEM<DATA[MID], then:
                Set END: =MID-1
        Else:
            Set BEG: =MID+1
Step 4: Set MID: =INT((BEG+END)/2)
Step 5: If DATA [MID] = ITEM, then:
                Set LOC: =MID
        Else:
            Set LOC: = NULL
Step 6: Exit
*/

// Source code:

#include <stdio.h>
int main()
{
    int c, first, last, mid, n, search, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (c = 0; c < n; c++)
        scanf("%d", &a[c]);
    printf("Enter value to find: ");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    mid = (first + last) / 2;
    while (first <= last)
    {
        if (a[mid] < search)
            first = mid + 1;
        else if (a[mid] == search)
        {
            printf("%d found at location %d.\n", search, mid + 1);
            break;
        }
        else
            last = mid - 1;
        mid = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d is not present in the list.\n", search);

    return 0;
}