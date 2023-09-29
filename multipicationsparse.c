#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int rows1, cols1, rows2, cols2;
    printf("Enter size of the first sparse matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    int sparseMatrix1[rows1][cols1];
    printf("Enter elements of the first sparse matrix:\n");
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols1; j++) 
        {
            scanf("%d", &sparseMatrix1[i][j]);
        }
    }
    int nonZeroCount1 = 0;
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols1; j++) 
        {
            if (sparseMatrix1[i][j] != 0) 
            {
                nonZeroCount1++;
            }
        }
    }
    printf("\nEnter size of the second sparse matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);
    int sparseMatrix2[rows2][cols2];
    printf("Enter elements of the second sparse matrix:\n");
    for (int i = 0; i < rows2; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            scanf("%d", &sparseMatrix2[i][j]);
        }
    }

    int nonZeroCount2 = 0;
    for (int i = 0; i < rows2; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            if (sparseMatrix2[i][j] != 0) 
            {
                nonZeroCount2++;
            }
        }
    }

    // Check if multiplication is possible
    if (cols1 != rows2) 
    {
        printf("\nMatrix multiplication is not possible. The number of columns in the first matrix must be
         equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int triplet1[nonZeroCount1 + 1][3];
    triplet1[0][0] = rows1;
    triplet1[0][1] = cols1;
    triplet1[0][2] = nonZeroCount1;
    int k1 = 1;
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols1; j++) 
        {
            if (sparseMatrix1[i][j] != 0) 
            {
                triplet1[k1][0] = i;
                triplet1[k1][1] = j;
                triplet1[k1][2] = sparseMatrix1[i][j];
                k1++;
            }
        }
    }
    int triplet2[nonZeroCount2 + 1][3]; 
    triplet2[0][0] = rows2;
    triplet2[0][1] = cols2;
    triplet2[0][2] = nonZeroCount2;
    int k2 = 1; 
    for (int i = 0; i < rows2; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            if (sparseMatrix2[i][j] != 0) 
            {
                triplet2[k2][0] = i;
                triplet2[k2][1] = j;
                triplet2[k2][2] = sparseMatrix2[i][j];
                k2++;
            }
        }
    }
    int result[rows1][cols2];
    for (int i = 0; i < rows1; i++) 
    {
    for (int j = 0; j < cols2; j++) 
    {
    result[i][j] = 0;
    for (int k = 0; k < cols1; k++) 
    {
    for (int x = 1; x <= nonZeroCount1; x++) 
    {
    if (triplet1[x][0] == i && triplet1[x][1] == k) 
    {
    for (int y = 1; y <= nonZeroCount2; y++) 
    {
    if (triplet2[y][0] == k && triplet2[y][1] == j) 
    {
    result[i][j] += (triplet1[x][2] * triplet2[y][2]);
                             }
                        }
                    }
                }
            }
        }
    }
    printf("\nResult of matrix multiplication:\n");
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}