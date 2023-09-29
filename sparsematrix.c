#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int rows, cols;

    printf("Enter size of the sparse matrix (rows cols): ");
    scanf("%d %d", &rows, &cols);
    int sparseMatrix[rows][cols];
    printf("Enter elements of the sparse matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (sparseMatrix[i][j] != 0) 
            {
                nonZeroCount++;
            }
        }
    }
    int triplet[nonZeroCount + 1][3]; // 3-tuple format array
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = nonZeroCount;
    int k = 1; // Index for triplet array
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (sparseMatrix[i][j] != 0) 
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    printf("Sparse matrix in 3-tuple format:\n");
    for (int i = 0; i <= nonZeroCount; i++) 
    {
        printf("%d   %d   %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }

    return 0;
}