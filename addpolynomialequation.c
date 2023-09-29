#include <stdio.h>
#include <stdlib.h>

// Define a structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

typedef struct Term Term;

// Function to create a new term
Term* createTerm(int coeff, int exp) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    if (newTerm == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term at the end of the linked list
void insertTerm(Term** poly, int coeff, int exp) {
    Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display a polynomial equation
void displayPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomial equations
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                insertTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Append any remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    printf("Enter the first polynomial equation:\n");
    // Input the first polynomial
    // Example input: 2x^3 + 3x^2 + 5x^1
    insertTerm(&poly1, 2, 3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);

    printf("Enter the second polynomial equation:\n");
    // Input the second polynomial
    // Example input: 4x^3 - 2x^2 + 1x^0
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, -2, 2);
    insertTerm(&poly2, 1, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of the two polynomials: ");
    displayPolynomial(sum);

    // Free memory for the linked lists
    while (poly1 != NULL) {
        Term* temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        Term* temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (sum != NULL) {
        Term* temp = sum;
        sum = sum->next;
        free(temp);
    }

    return 0;
}
