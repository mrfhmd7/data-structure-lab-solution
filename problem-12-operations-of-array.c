#include <stdio.h>
#define MAX_SIZE 100
void displayArray(int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertElement(int arr[], int size, int element, int position)
{
    if (size >= MAX_SIZE)
    {
        printf("Array is full, can't insert.\n");
        return size;
    }
    if (position < 0 || position > size)
    {
        printf("Invalid position for insertion.\n");
        return size;
    }
    for (int i = size - 1; i >= position; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;

    return size + 1;
}
int deleteElement(int arr[], int size, int position)
{
    if (size <= 0)
    {
        printf("Array is empty, nothing to delete.\n");
        return size;
    }
    if (position < 0 || position >= size)
    {
        printf("Invalid position for deletion.\n");
        return size;
    }
    for (int i = position; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}
int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;
    do
    {
        printf("Array Operations Menu:\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayArray(arr, size);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            size = insertElement(arr, size, element, position);
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            size = deleteElement(arr, size, position);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}