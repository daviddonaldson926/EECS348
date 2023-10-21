#include <iostream>
#include <fstream>
#include <iomanip> 

const int MAX_SIZE = 100;

void readMatrix(std::ifstream& inFile, int matrix[MAX_SIZE][MAX_SIZE], int size);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int resultMatrix[MAX_SIZE][MAX_SIZE], int size);


