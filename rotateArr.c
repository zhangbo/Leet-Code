#include <stdio.h>

void swap(int* a, int* b);
void rotate(int* nums, int numsSize, int k);

int main(int argc, char const *argv[])
{
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(arr) / sizeof(int);
	rotate(&arr[0], length, 4);
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

void rotate(int* nums, int numsSize, int k)
{
    if (nums == NULL || numsSize == 0 || k < 0)
    {
    	return;
    }

    k = (k >= numsSize) ? (k % numsSize) : k;
    int count = 0;
    for (int i = numsSize; i > 0; i = i - k)
    {
    	if (i / k > 1)
    	{
    		printf("Loop: %d -- %d\n", k * count, (count + 1) * k);
    		for (int j = k * count; j < (count + 1) * k; ++j)
    		{
    			swap(&nums[j], &nums[numsSize - (k - (j - k * count))]);
    		}
    	} else if (i / k == 1) {
    		for (int j = k * count; j < (k * count) + (i % k); ++j)
    		{
    			swap(&nums[j], &nums[numsSize - (k - (j - k * count))]);
    		}
    	} else {
    		for (int j = count + 1; j < (count + 1) + (i % k); ++j)
    		{
    			
    		}
    	}
    	count ++;
    }
}

void swap(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}