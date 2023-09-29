/*write to program using c  to swap 2 value using function and call by address.
#include <stdio.h>
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue function:\n");
    printf("a = %d, b = %d\n", a, b);
}
void swapByReference(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference function:\n");
    printf("a = %d, b = %d\n", *a, *b);
}

int main() {
    int num1,num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping:\n");
    printf("num1 = %d, num2 = %d\n\n", num1, num2);
    swapByValue(num1, num2);
    printf("After swapping by value:\n");
    printf("num1 = %d, num2 = %d\n\n", num1, num2);
    swapByReference(&num1, &num2);
    printf("After swapping by reference:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}
//wap to input and display the value along with sum of all values using dynamic memory allocation to a pointer variable  in c language
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, n, sum = 0;

    printf("Enter the number of values: ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 0;
    }
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
        sum += ptr[i]; 
    }
    printf("Entered values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\nSum of all values: %d", sum);
    free(ptr);
    return 0;
}

//wap to insert a new element in a 1D array at 0th position,at the end at a specified position of an array 

#include <stdio.h>
void insertAtStart(int arr[], int size, int element) {
    for(int i = size-1; i >= 0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = element;
    size++;
    printf("Array after inserting element at 0th position: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void insertAtEnd(int arr[], int size, int element) {
    arr[size] = element;
    size++;
    printf("Array after inserting element at end: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void insertAtPosition(int arr[], int size, int element, int position) {
    for(int i = size-1; i >= position; i--) {
        arr[i+1] = arr[i];
    }
    arr[position] = element;
    size++;
    printf("Array after inserting element at position %d: ", position);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100];
    int size, element, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    insertAtStart(arr, size, element);
    
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);

    insertAtEnd(arr, size, element);
    
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);
    
    printf("Enter the position to insert the element: ");
    scanf("%d", &position);

    insertAtPosition(arr, size, element, position);

    return 0;
}

