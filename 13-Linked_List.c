#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
void append(void);
void display(void);
void insert(void);
void deletee(void);
int main()
{
    int ch;
    while (1)
    {
        printf("\nSingle linked list operation:\n");
        printf("1. Append\n");
        printf("2. Display\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            deletee();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input\n\n");
        }
    }
    return 0;
}
void append()
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
}
void insert()
{
    int position, i;
    printf("Enter the position at which you want to insert the node: ");
    scanf("%d", &position);
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (position == 0)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        p = root;
        for (i = 0; i < position - 1 && p != NULL; i++)
        {
            p = p->link;
        }
        if (p == NULL)
        {
            printf("Invalid position\n");
            free(temp);
            return;
        }
        temp->link = p->link;
        p->link = temp;
    }
    printf("Node inserted successfully\n");
}
void deletee()
{
    int loc;
    printf("Enter location to delete: ");
    scanf("%d", &loc);
    if (root == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (loc == 0)
    {
        struct node *temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node *p = root, *q = NULL;
        int i = 0;
        while (i < loc && p != NULL)
        {
            q = p;
            p = p->link;
            i++;
        }
        if (p == NULL)
        {
            printf("Invalid location\n");
            return;
        }
        q->link = p->link;
        p->link = NULL;
        free(p);
    }
}
