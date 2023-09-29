#include <stdio.h>

float calculateAverage(int submissions[], int numSubmissions) {
    int sum = 0;
    
    for (int i = 0; i < numSubmissions; i++) {
        sum += submissions[i];
    }
    
    float average = (float)sum / numSubmissions;
    
    return average;
}

int main() {
    int submissions[] = {70, 80, 90, 75, 85};
    int numSubmissions = sizeof(submissions) / sizeof(submissions[0]);
    
    float average = calculateAverage(submissions, numSubmissions);
    
    printf("The average of the submissions is %.2f\n", average);
    
    return 0;
}
