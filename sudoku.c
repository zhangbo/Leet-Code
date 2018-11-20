#include <stdio.h>
#include <stdbool.h>

void printBoard(int board[][9]);
int puzzle(int board[][9], int row, int col);
int isValid(int board[][9], int row, int col, int target);

int main(int argc, char const *argv[])
{
	// int board[9][9] = {
	// 	{5,3,0,0,7,0,0,0,0},
	// 	{6,0,0,1,9,5,0,0,0},
	// 	{0,9,8,0,0,0,0,6,0},
	// 	{8,0,0,0,6,0,0,0,3},
	// 	{4,0,0,8,0,3,0,0,1},
	// 	{7,0,0,0,2,0,0,0,6},
	// 	{0,6,0,0,0,0,2,8,0},
	// 	{0,0,0,4,1,9,0,0,5},
	// 	{0,0,0,0,8,0,0,7,9}
	// };
	// int board[9][9] = {
	// 	{2,0,0,0,0,0,0,0,9},
	// 	{0,0,6,4,0,0,7,0,0},
	// 	{0,8,0,0,0,1,0,2,0},
	// 	{0,0,3,0,2,0,0,8,0},
	// 	{0,0,0,6,0,8,0,0,0},
	// 	{0,7,0,0,5,0,1,0,0},
	// 	{0,1,0,8,0,0,0,4,0},
	// 	{0,0,8,0,0,9,6,0,0},
	// 	{9,0,0,0,0,0,0,0,7}
	// };
	int board[9][9] = {
		{3,0,0,6,0,4,0,0,0},
		{0,8,4,1,0,0,0,0,0},
		{6,0,0,0,2,0,0,9,1},
		{0,0,6,0,0,0,0,0,9},
		{0,9,0,0,0,0,0,4,0},
		{8,2,0,3,0,9,5,0,6},
		{0,5,8,0,3,0,2,0,0},
		{0,0,0,0,0,2,0,5,7},
		{0,0,0,5,0,1,9,0,0}
	};
	printBoard(board);
	puzzle(board, 0, 0);
	printBoard(board);
	return 0;
}

int isValid(int board[][9], int row, int col, int target)
{
	if (target > 9 || target < 1)
	{
		return 0;
	}
	for (int i = 0; i < 9; ++i)
	{
		if (board[row][i] == target || board[i][col] == target || board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)] == target)
		{
			return 0;
		}
	}

	//origin
	// int r = row / 3, c = col / 3;
	// for (int i = r * 3; i < (r + 1) * 3; ++i)
	// {
	// 	for (int j = c * 3; j < (c + 1) * 3; ++j)
	// 	{
	// 		if (board[i][j] == target)
	// 		{
	// 			return 0;
	// 		}
	// 	}
	// }
	//origin
	return 1;
}

int puzzle(int board[][9], int row, int col)
{
	if (row < 9 && col < 9)
	{
		if (board[row][col] == 0)
		{
			for (int i = 1; i <= 9; ++i)
			{
				if (isValid(board, row, col, i) == 1)
				{
					board[row][col] = i;
					if (col + 1 < 9)
					{
						if (puzzle(board, row, col + 1) == 1)
						{
							return 1;
						}
						else
						{
							board[row][col] = 0;
						}
					}
					else if (row + 1 < 9)
					{
						if (puzzle(board, row + 1, 0) == 1)
						{
							return 1;
						}
						else
						{
							board[row][col] = 0;
						}
					}
					else
					{
						return 1;
					}
				}
			}
		}
		else
		{
			if (col + 1 < 9)
			{
				return puzzle(board, row, col + 1);
			}
			else if (row + 1 < 9)
			{
				return puzzle(board, row + 1, 0);
			}
			else
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

void printBoard(int board[][9])
{
	printf("\n┌─────┬─────┬─────┐\n");
	for(int i = 1; i < 10; ++i)
    {
        for(int j = 1; j < 10; ++j)
        {
        	if (j % 3 == 1)
        	{
        		printf("│%d", board[i-1][j-1]);
        	}
        	else
        	{
        		printf(" %d", board[i-1][j-1]);
        	}
        }
        printf("│\n");
        if (i % 3 == 0 && i != 9) printf("├─────┼─────┼─────┤\n");
    }
    printf("└─────┴─────┴─────┘\n");
}

//LeetCode puzzle
bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
	for (int i = 0; i < boardRowSize; ++i)
	{
		for (int j = 0; j < boardColSize; ++j)
		{
			if (board[i][j] != '.')
			{
				int num = board[i][j];
				for (int k = 0; k < boardRowSize; ++k)
				{
					if (board[i][k] == num || board[k][j] == num || board[(i / 3) * 3 + (k / 3)][(j / 3) * 3 + (k % 3)] == num)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
















