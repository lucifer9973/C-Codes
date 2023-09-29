//3.2>WAP to perform addition of two given sparse matrix in 3–tuple format.
#include <stdio.h>
#include <stdlib.h>
struct SparseElement {
    int row;
    int col;
    int value;
};
void addSparseMatrices(struct SparseElement matrix1[], int numElements1,
    struct SparseElement matrix2[], int numElements2) 
    {
    int numRows1 = matrix1[0].row;
    int numCols1 = matrix1[0].col;
    int numRows2 = matrix2[0].row;
    int numCols2 = matrix2[0].col;
    if (numRows1 != numRows2 || numCols1 != numCols2) 
    {
        printf("Matrix dimensions do not match. Addition not possible.\n");
        return;
    }
    int numElementsResult = numElements1 + numElements2 - 1;
    struct SparseElement resultMatrix[numElementsResult + 1];
    int i = 1, j = 1, k = 1;
    while (i <= numElements1 && j <= numElements2) 
    {
        if (matrix1[i].row < matrix2[j].row ||
            (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) 
            {
            resultMatrix[k] = matrix1[i];
            i++;
        } else if (matrix2[j].row < matrix1[i].row ||
                   (matrix2[j].row == matrix1[i].row && matrix2[j].col < matrix1[i].col)) 
                   {
            resultMatrix[k] = matrix2[j];
            j++;
        } 
        else 
        {
            resultMatrix[k].row = matrix1[i].row;
            resultMatrix[k].col = matrix1[i].col;
            resultMatrix[k].value = matrix1[i].value + matrix2[j].value;
            i++;
            j++;
        }
        k++;
    }
    while (i <= numElements1) 
    {
        resultMatrix[k] = matrix1[i];
        i++;
        k++;
    }
    while (j <= numElements2) 
    {
        resultMatrix[k] = matrix2[j];
        j++;
        k++;
    }
    printf("Resultant Matrix in 3-tuple format:\n");
    printf("%d   %d   %d\n", numRows1, numCols1, k - 1);
    for (int idx = 1; idx < k; idx++) 
    {
        printf("%d   %d   %d\n", resultMatrix[idx].row, resultMatrix[idx].col, resultMatrix[idx].value);
    }
}
int main() 
{
    int numElements1, numElements2;
    printf("Enter the number of elements in sparse matrix-1: ");
    scanf("%d", &numElements1);
    struct SparseElement matrix1[numElements1 + 1];
    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    for (int i = 1; i <= numElements1; i++) 
    {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }
    printf("Enter the number of elements in sparse matrix-2: ");
    scanf("%d", &numElements2);
    struct SparseElement matrix2[numElements2 + 1];
    printf("Enter sparse matrix-2 in 3-tuple format:\n");
    for (int i = 1; i <= numElements2; i++) 
    {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }
    addSparseMatrices(matrix1, numElements1, matrix2, numElements2);
    return 0;
}