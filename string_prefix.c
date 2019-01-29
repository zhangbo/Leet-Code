#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

char* longestCommonPrefix(char** strs, int strsSize);

int main(int argc, char const *argv[])
{
	char* strArr[3] = {"aggresive", "aggregation", "aggress"};
	char *result = longestCommonPrefix(strArr, sizeof(strArr) / sizeof(*strArr));
	printf("%s\n", result);
	free(result);
	return 0;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
	// printf("%c, %c, %c\n", *(*strs + 2), *(*(strs + 1) + 2), *(*(strs + 2) + 2));
	int minLength = strlen(*strs);
	int count = 0;	//计数器
	for (int i = 1; i < strsSize; ++i)
	{
		minLength = MIN(strlen(strs[i]), minLength);
	}

	for (int i = 0; i < minLength; ++i)
	{
		int row = 1;
		char tmpChar = *(*strs + i);
		while (row < strsSize)
		{
			if (*(*(strs + row) + i) != tmpChar)
			{
				break;
			}
			row++;
		}

		if (row == strsSize)
		{
			count++;
		}
		else
		{
			break;
		}

	}

	char* p = (char*)malloc((count + 1) * sizeof(char));
	memcpy(p, *strs, count);
	*(p + count) = '\0';
    return p;
}