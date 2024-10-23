#include <stdio.h>

void main()
{
    int row = 3, column = 3;
    int matA[row][column], matB[row][column], matC[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter MatA[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matA[i][j]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter MatB[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &matB[i][j]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matC[i][j] = matA[i][j]+matB[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d  ", matC[i][j]);
        }
        printf("\n");
    }


}