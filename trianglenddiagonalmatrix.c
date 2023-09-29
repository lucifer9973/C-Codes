#include <stdio.h>
#include <stdlib.h>
int NonZero(int matrix[][10], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                count++;
            }
        }
    }
    return count;
}
void displayUpperTriangular(int matrix[][10], int size) 
{
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (j >= i) 
            {
                printf("%d", matrix[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void displayDiagonalElements(int matrix[][10], int size) 
{
    printf("Elements above and below the main diagonal:\n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (j == i - 1 || j == i + 1) 
            {
                printf("%4d", matrix[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() 
{
    int size, matrix[10][10];

    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n");

    printf("Nonzero elements: %d\n", NonZero(matrix, size));
    displayUpperTriangular(matrix, size);
    displayDiagonalElements(matrix, size);

    return 0;
}