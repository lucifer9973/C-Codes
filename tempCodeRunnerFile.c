/*2.1> WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array.?*/
#include <stdio.h>

void insertElement(int arr[], int *n, int element, int position) {
    if (position < 0 || position > *n) {
        printf("Invalid position. Position should be between 0 and %d\n", *n);
        return;
    }

    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*n)++;
    printf("Element inserted successfully!\n");
}

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete(int n,int *a,int l);
int main()
{
int *a,n,i,l;
scanf(“%d”,&n);
a=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
scanf(“%d”,(a+i));
}
scanf(“%d”,&l);
delete(n,a,l);
return 0;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    displayArray(arr, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at specific position\n");
        printf("2.Delete")
        printf("3. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int element, position;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);

            insertElement(arr, &n, element, position);
            displayArray(arr, n);
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else if (choice == 2) {
            deleteElement(&n, arr);
            displayArray(arr, n);
            }else {
                printf("Invalid Choice!\n");
                }
                }
                return 0;
                }
                