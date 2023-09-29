//3.1>WAP to perform transpose of a given sparse matrix in 3-tuple format.
#include <stdio.h>
#include <stdlib.h>
struct SparseElement 
{
    int row;
    int col;
    int value;
};
void transposeSparseMatrix(struct SparseElement inputMatrix[],
int numElements) {
    int numRows = inputMatrix[0].row;
    int numCols = inputMatrix[0].col; 
    int count[numCols];
    for (int i = 0; i < numCols; i++) {
        count[i] = 0;
    }
    for (int i = 1; i <= numElements; i++) {
        count[inputMatrix[i].col]++;
    }
    int startIndex[numCols];
    startIndex[0] = 1;
    for (int i = 1; i < numCols; i++) {
        startIndex[i] = startIndex[i - 1] + count[i - 1];
    }
    struct SparseElement transposeMatrix[numElements + 1];
    for (int i = 1; i <= numElements; i++) {
        int j = startIndex[inputMatrix[i].col]++;
        transposeMatrix[j].row = inputMatrix[i].col;
        transposeMatrix[j].col = inputMatrix[i].row;
        transposeMatrix[j].value = inputMatrix[i].value;
    }
    printf("Transpose of sparse matrix:\n");
    printf("R   C  Element\n");
    for (int i = 0; i <= numElements; i++) {
    printf("%d   %d   %d\n", transposeMatrix[i].row, transposeMatrix[i].col, transposeMatrix[i].value);
    }
}
int main() {
    int numElements;   
    printf("Enter the number of elements in the sparse matrix: ");
    scanf("%d", &numElements);
    struct SparseElement inputMatrix[numElements + 1];
    printf("Enter sparse matrix in 3-tuple format:\n");
    for (int i = 1; i <= numElements; i++) {
    scanf("%d %d %d", &inputMatrix[i].row, &inputMatrix[i].col, &inputMatrix[i].value);
    }
    transposeSparseMatrix(inputMatrix, numElements);
    return 0;
}