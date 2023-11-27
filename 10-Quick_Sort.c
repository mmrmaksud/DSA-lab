// 7.Write a program to implement the Quick Sort algorithm.

/*
Algorithm: This algorithm sorts an array A with N elements
Step 1: TOP := NULL
Step 2: If N>1, then: TOP := TOP + 1, LOWER[1], UPPER[1] := N
Step 3: Repeat Steps 4 to 7 while TOP ≠ NULL
Step 4: Set BEG := LOWER[TOP], END := UPPER[TOP],
        TOP := TOP – 1
Step 5: Call QUICK (A, N, BEG, END, LOC)
Step 6: If BEG<LOC-1, then:
                TOP := TOP + 1, LOWER[TOP] := BEG
                UPPER[TOP] = LOC – 1
Step 7: If LOC + 1< END, then:
                TOP:=TOP + 1, LOWER[TOP] := LOC + 1,
                UPPER[TOP] := END
Step 8: Exit
*/

// Source code:

#include <stdio.h>
void quicksort(int num[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (num[i] <= num[pivot] && i < last)
                i++;
            while (num[j] > num[pivot])
                j--;
            if (i < j)
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        temp = num[pivot];
        num[pivot] = num[j];
        num[j] = temp;
        quicksort(num, first, j - 1);
        quicksort(num, j + 1, last);
    }
}
int main()
{
    int i, count, num[25];
    printf("How many elements are u going to enter?: ");
    scanf("%d", &count);
    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++)
        scanf("%d", &num[i]);
    quicksort(num, 0, count - 1);
    printf("Order of Sorted elements: ");
    for (i = 0; i < count; i++)
        printf("%d ", num[i]);

    return 0;
}