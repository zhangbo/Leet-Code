#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int rob(int* nums, int numsSize);
int possibleRob(int numsSize);

int main(int argc, char const *argv[])
{
	int houses[4] = {2,1,1,7};
	size_t size = sizeof(houses) / sizeof(int);
	printf("%d\n", rob((int*)houses, size));
	return 0;
}

int possibleRob(int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}
	else if (numsSize == 1)
	{
		return 1;
	}
	else if (numsSize == 2)
	{
		return 2;
	}
	else
	{
		return possibleRob(numsSize - 1) + possibleRob(numsSize - 2) + 1;
	}
}

int rob(int* nums, int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}
	else if (numsSize == 1)
	{
		return nums[0];
	}
	else if(numsSize == 2)
	{
		return MAX(nums[numsSize - 1], nums[numsSize - 2]);
	}
	else
	{
		int* tmpArr = (int*)malloc((numsSize + 1) * sizeof(int));
		tmpArr[numsSize] = '\0';
		tmpArr[0] = nums[0];
		tmpArr[1] = MAX(nums[0], nums[1]);
		for (int i = 2; i < numsSize; ++i)
		{
			tmpArr[i] = MAX(tmpArr[i - 1], tmpArr[i - 2] + nums[i]);
		}
		int result = tmpArr[numsSize - 1];
		free(tmpArr);
		return result;
	}
}

// 1
// 1

// 1 2
// 2

// 1 2 3
// 13
// 3 + 1 = 4

// 1 2 3 4	

// 13 14 24
// 2 1						
// 4 + 3 = 7

// 1 2 3 4 5

// 13 14 15 135 24 25 35 
// 4 2 1
// 5 + 7 = 12

// 1 2 3 4 5 6
// 13 14 15 16 135 136 146 24 25 26 246 35 36 46
// 7 4 2 1
// 6 + 14 = 20

// 1 2 3 4 5 6 7
// 13 14 15 16 17 135 136 137 146 147 157 1357 24 25 26 27 246 247 257
// 12 7 4 2 1
// 7 + 26 = 33
// .
// .
// .
// 20 12 7 4 2 1
// 8 + 46 = 54

