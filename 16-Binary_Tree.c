// 10. Write a program to traverse a binary tree in any order.

/*
Algorithm: INORD(INFO, LEFT, RIGHT, ROOT)
Step 1: Set TOP := 1, STACK[1] := NULL and PTR := ROOT.
Step 2: Repeat while PTR != NULL:
	        (a) Set TOP := TOP + 1 and STACK[TOP] := PTR.
	        (b) Set PTR := LEFT[PTR].
Step 3: Set PTR := STACK[TOP] and TOP := TOP -1.
Step 4: Repeat Steps 5 to 7 while PTR != NULL:
Step 5: Apply PROCESS to INFO[PTR].
Step 6: If RIGHT[PTR] !=NULL, then:
	        (a) Set PTR := RIGHT[PTR].
	        (b) Go to Step 3.
Step 7: Set PTR := STACK[TOP] and TOP := TOP -1.
Step 8: Exit.
*/

// Source code:

#include <stdio.h>
#include <stdlib.h>
struct tnode
{
    int data;
    struct tnode *left, *right;
};
struct tnode *root = NULL;
struct tnode *createNode(int data)
{
    struct tnode *newNode;
    newNode = (struct tnode *)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}
void insertion(struct tnode **node, int data)
{
    if (!*node)
    {
        *node = createNode(data);
    }
    else if (data < (*node)->data)
    {
        insertion(&(*node)->left, data);
    }
    else if (data > (*node)->data)
    {
        insertion(&(*node)->right, data);
    }
}
void postOrder(struct tnode *node)
{
    if (node)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
    return;
}
void preOrder(struct tnode *node)
{
    if (node)
    {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
    return;
}
void inOrder(struct tnode *node)
{
    if (node)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
    return;
}
int main()
{
    int data, ch;
    while (1)
    {
        printf("\n1. Insertion\n2. Pre-order\n");
        printf("3. Post-order\n4. In-order\n");
        printf("5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &data);
            insertion(&root, data);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:
            inOrder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("You've entered wrong option.\n");
            break;
        }
    }

    return 0;
}