// 6. Write a program to implement all major Queue operations.

/*
Algorithm: QINSERT (QUEUE, N, FRONT, REAR, ITEM)
Step 1: If FRONT =1 and REAR = N, or If FRONT = REAR + 1, then:
                Write: OVERFLOW and Return.
Step 2: If FRONT: = NULL, then:
                Set FRONT: = 1 and REAR: =1
        Else if REAR = N, then:
                Set REAR: = 1
        Else:
                Set REAR: = REAR +1
Step 3: Set QUEUE[REAR]: = ITEM.
Step 4: Return.

QDELETE (QUEUE, N, FRONT, REAR, ITEM)
Step 1: If FRONT := NULL, then: Write: UNDERFLOW, and Return
Step 2: Set ITEM := QUEUE[FRONT]
Step 3: If FRONT = REAR, then:
                    Set FRONT := NULL and REAR := NULL
            Else if FRONT = N, then:
                    Set FRONT := 1
            Else:
                Set FRONT := FRONT + 1
Step 4: Return
*/

// Source code:

#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert element to queue \n");
        printf("2. Delete element from queue \n");
        printf("3. Display all elements of queue \n");
        printf("4. Quit \n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n\n");
        }
    }
}
void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("\nInsert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
        printf("\n");
    }
}
void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("\nElement deleted from queue is: %d\n", queue_array[front]);
        front = front + 1;
    }
}
void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("\nQueue is: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n\n");
    }
}
