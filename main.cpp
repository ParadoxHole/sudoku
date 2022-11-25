//SUDOKU
#include <iostream>
using namespace std;

int main()
{
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    int row, col, num;
    bool check = true;
    cout << "SUDOKU" << endl;
    cout << "Enter the row, column and number you want to insert: ";
    cin >> row >> col >> num;
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == num)
        {
            check = false;
            break;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num)
        {
            check = false;
            break;
        }
    }
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++)
    {
        for (int j = colStart; j < colStart + 3; j++)
        {
            if (sudoku[i][j] == num)
            {
                check = false;
                break;
            }
        }
    }
    if (check)
    {
        sudoku[row][col] = num;
        cout << "The number is inserted" << endl;
    }
    else
    {
        cout << "The number is not inserted" << endl;
    }  
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}