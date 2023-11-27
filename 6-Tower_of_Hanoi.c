// 4. Write a program that implements Tower of Hanoi problem by using a recursive function.

/*
Algorithm: TOWER (N, BEG, AUX, END)
Step 1: If N=1, then:
            (a) Write: BEG->END
            (b) Return
Step 2: [Move N-1 disks from peg BEG to Peg AUX]
        Call TOWER (N-1, BEG, END, AUX)
Step 3: Write: BEG->END
Step 4: [Move N-1 disks from peg AUX to peg END]
        Call TOWER (N-1, AUX, BEG, END)
Step 5: Return.
*/

// Source code:

#include <stdio.h>
void towerOfHanoi(int n, char source, char aux, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, aux);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, aux, source, destination);
}
int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}