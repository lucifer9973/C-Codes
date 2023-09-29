//3.3>WAP to represent the polynomial of single variable using 1-D array and perform the addition of two polynomial equations.
#include <stdio.h>
#include <stdlib.h>
void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}
void displayPolynomial(int poly[], int degree) {
    int firstTerm = 1;
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (!firstTerm) {
                if (poly[i] > 0) {
                    printf("+");
                }
            } else {
                firstTerm = 0;
            }
            if (i == 0) {
                printf("%d", poly[i]);
            } else if (i == 1) {
                printf("%dx", poly[i]);
            } else {
                printf("%dx^%d", poly[i], i);
            }
        }
    }
    printf("\n");
}
int main() {
    int degree;
    printf("Enter the maximum degree of x: ");
    scanf("%d", &degree);
    int poly1[degree + 1], poly2[degree + 1], result[degree + 1];
    printf("Enter Polynomial-1 from the lowest degree to the highest degree: \n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }
    printf("Enter Polynomial-2: \n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }
    addPolynomials(poly1, poly2, result, degree);
    printf("Resultant Polynomial: ");
    displayPolynomial(result, degree);
    return 0;
}