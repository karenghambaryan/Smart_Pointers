#include <iostream>
#include <string>
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

int main(int argc,char* argv[])
{
    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    int** matrix = new int*[x];
    for (int i = 0; i < x; i++)
    {
        matrix[i] = new int[y];
    }
    InitMatrix(matrix,x,y);
    PrintMatrix(matrix,x,y);
    for (int i = 0; i < x; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;

}