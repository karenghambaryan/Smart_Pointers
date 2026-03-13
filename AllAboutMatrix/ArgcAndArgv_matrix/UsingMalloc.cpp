#include <iostream>
#include <string>
#include <cstdlib>
void InitMatrix(int** matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (i + j) % 10;
        }
        
    }
}
void PrintMatrix(int** matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
    std::cout << std::endl;
    }
    
}
int main(int argc, char* argv[])
{
    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    if(x > 0 && y > 0)
    {
        
        int** matrix = (int**)malloc(x * sizeof(int*));
        for (int i = 0; i < x; i++)
        {
            matrix[i] = (int*)malloc(y * sizeof(int));
        }
        InitMatrix(matrix, x , y);
        PrintMatrix(matrix, x , y);

        for(int i = 0; i < x; i++)
        {
            free(matrix[i]);
        }

        free(matrix);
    }
    else
    {
        std::cout << "GREAT Mistake" << std::endl;
    }

    return 0;
}