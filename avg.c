#include <stdio.h>

float calculateAverage(int numbers[], int size) {
    if (size <= 0) {
        printf("Error: Array size must be greater than 0.\n");
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    float average = (float)sum / size;
    return average;
}

int main(){
{
    int numArray[100];
    printf("Enter %d elements in an array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numArray[i]);
    }
    printf ("The Average is:%f \n ",calculateAverage(int numbers[], int size));
    return 1;}

    int arraySize = sizeof(numArray) / sizeof(numArray[100]);

    float avg = calculateAverage(numArray, arraySize);
    printf("Average: %.2f\n", avg);
    return 0;
}