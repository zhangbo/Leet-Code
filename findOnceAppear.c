#include <stdio.h>
#include <stdlib.h>

int rmdup(int *array, int length);
int singleNumber(int* nums, int numsSize);

int main(int argc, char const *argv[])
{
	int array[9] = {1, 1, 2, 2, 2};
	int sum = 0, rmdupSum = 0;
	size_t length = sizeof(array) / sizeof(int);

	printf("%d\n", singleNumber(&array[0], length));

	return 0;
}

int singleNumber(int* nums, int numsSize) {
	int result = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		result ^= nums[i];
	}
	return result;
    
}

// int singleNumber(int* nums, int numsSize)
// {
	
// 	for (int i = 0; i < numsSize; ++i)
// 	{
// 		int index = 0;
// 		for (int j = 0; j < numsSize; ++j)
// 		{
// 			if (i == j)
// 			{
// 				continue;
// 			} else {
// 				if (nums[i] == nums[j])
// 				{
// 					index++;
// 					break;
// 				}
// 			}
// 		}
// 		if (index == 0)
// 		{
// 			return nums[i];
// 		}
// 	}
//     return 0;
// }

// int singleNumber(int* nums, int numsSize)
// {
//     int sum = 0, rmdupSum = 0;
//     for (int i = 0; i < numsSize; ++i)
// 	{
// 		sum += nums[i];
// 	}

// 	int index = rmdup(nums, numsSize);

// 	for (int i = 0; i < numsSize - index; ++i)
// 	{
// 		rmdupSum += nums[i];
// 	}

// 	for (int j = 0; j < numsSize - index; ++j)
// 	{
// 		int result = (rmdupSum - nums[j]) << 1;
// 		if (result == sum - nums[j])
// 		{
// 			return nums[j];
// 		}
// 	}

// 	return 0;
// }

// int rmdup(int *nums, int numsSize)
// {
//     int *current , *end = nums + numsSize - 1;
//     int index = 0;

//     for ( current = nums + 1; nums < end; nums++, current = nums + 1 )
//     {
//         while ( current <= end )
//         {
//             if ( *current == *nums )
//             {
//                 *current = *end--;
//                 index++;
//             }
//             else
//             {
//                 current++;
//             }
//         }
//     }
//     return index;
// }