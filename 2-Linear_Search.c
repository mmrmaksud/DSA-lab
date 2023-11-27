#include <stdio.h>
int linearSearch(int arr[], int size, int target)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int size, target;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int index = linearSearch(arr, size, target);
    if (index != -1)
        printf("Element found at index %d\n", index + 1);
    else
        printf("Element not found.\n");

    return 0;
}
