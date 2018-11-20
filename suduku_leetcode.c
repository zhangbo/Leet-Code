#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char board[][9], int boardRowSize, int boardColSize);

int main(int argc, char const *argv[])
{
	char board[9][9] = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	bool result = isValidSudoku(board, 9, 9);
	printf("%s\n", result ? "true" : "false");
	return 0;
}

bool isValidSudoku(char board[][9], int boardRowSize, int boardColSize)
{
	for (int i = 0; i < boardRowSize; ++i)
	{
		for (int j = 0; j < boardColSize; ++j)
		{
			if (board[i][j] != '.')
			{
				char num = board[i][j];
				for (int k = 0; k < boardRowSize; ++k)
				{
					if ((k != j && board[i][k] == num) || (k != i && board[k][j] == num) || ((i / 3) * 3 + (k / 3) != i && (j / 3) * 3 + (k % 3) != j && board[(i / 3) * 3 + (k / 3)][(j / 3) * 3 + (k % 3)] == num))
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}