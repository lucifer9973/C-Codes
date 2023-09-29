//2.1)WAP to create a 1-D array of n elements and perform the following menu based operations using function.
//a. insert a given element at specific position.
//b. delete an element from a specific position of the array.
//c. linear search to search an element
//d. traversal of the array


/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void insertElement(int arr[], int *n, int element, int position) 
{
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void deleteEtement(int arr[l], int*n, int position)
{
if (*n == 0) 
{
printf("Array is empty. Cannot delete elements. \n");
return;
}
if (position < O || position >= *n); 
printf ("Invalid position for deletion.\n");
return;
}
for (int i position; i<*n-1;i++){
arr[i] = arr[i + 1];
printf ( "Element at position %d deteted.\n",position);
}

int linearSearch(int arr[], int n, int element) 
{
for (int i = o; i n; i++) 
{
if (arr[i] == element) 
{
return i;
}
}
return-1;
}

{
void traverseArray(int arr[], int n)
{
if (n == 0) 
{
printf("Array is empty.\n");
return ;
}
printf("Array elements: ");
for (int i=0;i<n;i++);
{
printf("%d",arr[i]);
}
printf( "\n");
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
        printf("\n***Menu***\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element\n");
        printf("3.Linear Search\n");
        printf("4.Transversal\n");
        printf("5. Exit\n");
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
        }
         else if (choice == 2) {
            int position,result;
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteElement(n, arr, position);
            displayArray(arr, n);
        }
        else if (choice == 3) {
           printf ("Enter the element to search");
           scanf("%d",&element);
           result= linearSearch(arr,n,element);
           if (result != -1) {
            printf("element found at psition %d.\n",result);
        }else{
            printf("element not found.\n");
        }

         if (choice == 4){
            tranverseArray(arr,n);
        }
         else if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void insertElement(int arr[], int *n, int element, int position) {
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteElement(int arr[], int *n, int position) {
    if (*n == 0) {
        printf("Array is empty. Cannot delete elements. \n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element at position %d deleted.\n", position);
}

int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
        printf("\n***Menu***\n");
        printf("1. Insert element at specific position\n");
        printf("2. Delete element\n");
        printf("3. Linear Search\n");
        printf("4. Transversal\n");
        printf("5. Exit\n");

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
        } else if (choice == 2) {
            int position;
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteElement(arr, &n, position);
            displayArray(arr, n);
        } else if (choice == 3) {
            int element;
            printf("Enter the element to search: ");
            scanf("%d", &element);
            int result = linearSearch(arr, n, element);
            if (result != -1) {
                printf("Element found at position %d.\n", result);
            } else {
                printf("Element not found.\n");
            }
        } else if (choice == 4) {
            traverseArray(arr, n);
        } else if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
