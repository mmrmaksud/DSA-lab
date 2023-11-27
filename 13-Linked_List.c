#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d inserted at the beginning.\n\n", new_data);
}
// Function to insert a new node before a given node in the linked list
void insertBeforeNode(struct Node **head_ref, int new_data, int before_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    while (current != NULL && current->data != before_data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("%d not found in the list. Inserting at the end.\n", before_data);
        prev->next = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = current;
        if (prev == NULL)
        {
            *head_ref = new_node;
        }
        else
        {
            prev->next = new_node;
        }
        printf("%d inserted before %d.\n\n", new_data, before_data);
    }
}
// Function to delete a node by data value
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the list.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("%d not found in the list.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the list.\n\n", key);
}
// Function to display the linked list
void displayList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int choice, data, beforeData, afterData;
    do
    {
        printf("Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert before a data value\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to be inserted at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the data value before which to insert: ");
            scanf("%d", &beforeData);
            insertBeforeNode(&head, data, beforeData);
            break;
        case 3:
            printf("Enter data value to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 4:
            printf("Current linked list: ");
            displayList(head);
            printf("\n");
            break;
        case 5:
            printf("Exit.\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
