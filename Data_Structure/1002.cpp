#include <iostream>

void createMatrix(int iGrid, char cMat[100][100])
{
    for (int i = 0; i < iGrid; ++i)
    {
        for (int j = 0; j < iGrid; ++j)
        {
            std::cin >> cMat[i][j];
        }
    }
}

int verifyMatrix(int iGrid, char cMat[100][100], int x, int y, int &iCount)
{

    for (int i = 0; i < iGrid; ++i)
    {
        for (int j = 0; j < iGrid; ++j)
        {
            if (cMat[i][j] == '.')
                verifyMatrix(iGrid, cMat, i, j, iCount);
        }
    }
}

int checkMatrix(int iGrid, char cMat[100][100])
{
    int iResult = 0;

    for (int i = 0; i < iGrid; ++i)
    {
        for (int j = 0; j < iGrid; ++j)
        {
            if (cMat[i][j] == '.')
                verifyMatrix(iGrid, cMat, i, j, iResult);
        }
    }

    return iResult;
}

int main()
{
    int iTest, iGrid, iResult;
    char cMat[100][100];
    std::cin >> iTest;

    for (int i = 0; i < iTest; ++i)
    {
        std::cin >> iGrid;
        createMatrix(iGrid, cMat);
        std::cout << checkMatrix(iGrid, cMat) << std::endl;
    }
    return 0;
}