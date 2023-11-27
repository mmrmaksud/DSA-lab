// 3. Write a program to implement first pattern matching algorithm.

/*
Algorithm: 
Step 1: Set K: =1 and MAX: = S-R+1
Step 2: Repeat steps 3 to 5 while K≤MAX:
Step 3: Repeat for L=1 to R:
            If P[L] ≠ T[K+L-1], then: Go to step 5
Step 4: Set INDEX = K, and Exit
Step 5: Set K: =K+1
Step 6: Set INDEX = 0
Step 7: Exit.
*/

// Source code:

#include <stdio.h>
#include <string.h>
int main()
{
    char text[20], pat[20];
    int a, b;
    printf("Enter the string: ");
    gets(text);
    printf("Enter the pattern to find: ");
    gets(pat);
    a = strlen(pat);
    b = strlen(text);
    for (int i = 0; i <= b - a; i++)
    {
        int j;
        for (j = 0; j < a; j++)
            if (text[i + j] != pat[j])
                break;
        if (j == a)
            printf("Pattern found at position %d\n", i + 1);
    }

    return 0;
}