#include <stdio.h>
#include <stdlib.h>
struct SparseElement {
    int row;
    int col;
    int value;
};
void addSparseMatrices(struct SparseElement matrix1[], int numElements1,
                       struct SparseElement matrix2[], int numElements2) {
    int i = 0, j = 0, k = 0;
    int numElementsResult = numElements1 + numElements2;
    struct SparseElement resultMatrix[numElementsResult];
    while (i < numElements1 || j < numElements2) {
        if (i < numElements1 && (j >= numElements2 || 
            (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)))) {
            resultMatrix[k] = matrix1[i++];
        } else if (j < numElements2) {
            resultMatrix[k] = matrix2[j++];
        }
        k++;
    }
    printf("Resultant Matrix in 3-tuple format:\n");
    printf("%d   %d   %d\n", matrix1[0].row, matrix1[0].col, k - 1);
    for (int idx = 0; idx < k; idx++) {
        printf("%d   %d   %d\n", resultMatrix[idx].row, resultMatrix[idx].col, resultMatrix[idx].value);
    }
}
int main() {
    int numElements1, numElements2;
    printf("Enter the number of elements in sparse matrix-1: ");
    scanf("%d", &numElements1);
    struct SparseElement matrix1[numElements1];
    printf("Enter sparse matrix-1 in 3-tuple format:\n");
    for (int i = 0; i < numElements1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }
    printf("Enter the number of elements in sparse matrix-2: ");
    scanf("%d", &numElements2);
    struct SparseElement matrix2[numElements2];
    printf("Enter sparse matrix-2 in 3-tuple format:\n");
    for (int i = 0; i < numElements2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }
    addSparseMatrices(matrix1, numElements1, matrix2, numElements2);
    return 0;
}
