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
    //print sudoku using . for empty spaces and with column and row numbers separated with the grid by | and | for the grid
    cout << "    1 2 3   4 5 6   7 8 9" << endl;
    cout << "  -------------------------" << endl; 
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                cout << i + 1 << " | ";
            }
            if (sudoku[i][j] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << sudoku[i][j] << " ";
            }
            if (j == 2 || j == 5 || j == 8)
            {
                cout << "| ";
            }
            if (j == 8)
            {
                cout << i + 1;
            }
        }
        cout << endl;
        if (i == 2 || i == 5)
        {
            cout << "  -------------------------" << endl;
        }
    }   
    cout << "  -------------------------" << endl; 
    cout << "    1 2 3   4 5 6   7 8 9" << endl;
    return 0;
}