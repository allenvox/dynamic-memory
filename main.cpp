#include <iostream>
#include <ctime>
using namespace std;

int *genRandArray(int size, int maxValue)
{
    int *arr = new int[size + 1];
    arr[0] = size;
    for (int i = 1; i < size + 1; i++)
    {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void printArray(int *arr)
{
    int size = arr[0];
    cout << size << ":";
    for (int i = 1; i < size + 1; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

void Array(int size, int maxValue)
{
    int *arr = genRandArray(size, maxValue);
    printArray(arr);
    free(arr);
}

int **genRandMatrix(int rows, int maxValue)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        int size = rand() % 10;
        matrix[i] = genRandArray(size, maxValue);
    }
    return matrix;
}

void printMatrix(int rows, int **matrix)
{
    cout << rows << endl;
    for (int i = 0; i < rows; i++)
    {
        printArray(matrix[i]);
    }
}

void Matrix(int rows, int maxValue)
{
    int **matrix = genRandMatrix(rows, maxValue);
    printMatrix(rows, matrix);
    free(matrix);
}

int main()
{
    srand(time(0));
    int size = rand() % 10;
    int rows = rand() % 10;
    int maxValue = 100;
    cout << "Array:\n";
    Array(size, maxValue);
    cout << "Matrix:\n";
    Matrix(rows, maxValue);
    return 0;
}