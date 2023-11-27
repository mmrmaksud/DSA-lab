// 5. Write a program to implement all major Stack operations.

/*
Algorithm:PUSH (STACK, TOP, MAXSTK, ITEM)
Step 1: If TOP = MAXSTK, then: Print: OVERFLOW and Return.
Step 2: Set TOP: = TOP+1
Step 3: Set STACK[TOP]: = ITEM
Step 4: Return

POP (STACK, TOP, ITEM)
Step 1: If TOP = 0, then: Print: UNDERFLOW and Return
Step 2: Set ITEM: = STACK[TOP].
Step 3: Set TOP: =TOP-1
Step 4: Return.
*/

// Source code:

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int top = -1, inp_array[SIZE];
void push();
void pop();
void show();
int main()
{
    int choice;
    while (1)
    {
        printf("Perform operations on the stack:\n");
        printf("1. Push the element\n2. Pop the element\n3. Show\n4. End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!!");
        }
    }
}
void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        inp_array[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", inp_array[top]);
        top = top - 1;
    }
}
void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: ");
        for (int i = top; i >= 0; --i)
            printf("%d ", inp_array[i]);
    }
    printf("\n\n");
}
