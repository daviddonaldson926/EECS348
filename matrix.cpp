#include <iostream>
#include <fstream>
#include <iomanip> 

const int MAX_SIZE = 100;

void readMatrix(std::ifstream& inFile, int matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);

int main() {
    std::ifstream inFile("matrix_input.txt");
    if (!inFile) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }

    int size;
    inFile >> size; 

    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];

    readMatrix(inFile, matrixA, size);
    readMatrix(inFile, matrixB, size);

    std::cout << "Matrix A:\n";
    printMatrix(matrixA, size);

    std::cout << "\nMatrix B:\n";
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "\nMatrix Sum (A + B):\n";
    printMatrix(resultMatrix, size);

    multiplyMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "\nMatrix Product (A * B):\n";
    printMatrix(resultMatrix, size);

    subtractMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "\nMatrix Difference (A - B):\n";
    printMatrix(resultMatrix, size);

    inFile.close();
    return 0;
}void readMatrix(std::ifstream& inFile, int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            inFile >> matrix[i][j];
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(5) << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
}

void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < size; ++k)
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
}
