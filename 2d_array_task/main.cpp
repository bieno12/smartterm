#include <iostream>

using namespace std;


int **newArray(int rows, int cols)
{
    int **array = (int **) malloc( rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        array[i] = (int *) calloc(cols, sizeof(int));
    return array;
}
void destroyArray(int **array, int rows)
{
    for(int i = 0; i < rows; i++)
        free(array[i]);
    free(array);
}

int **fillArray(int **array, int rows, int cols,int fill)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            array[i][j] = fill;
        }
    }
    return array;
}
int main()
{
    const int rows = 10, cols = 10;

    int **array = newArray(rows, cols);

    int **arrayReference = fillArray(array, rows, cols, '*');

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << (char)array[i][j];
        }
        cout << endl;
    }
    destroyArray(array, rows);
}