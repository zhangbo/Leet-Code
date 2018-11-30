#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main(int argc, char const *argv[])
{
	int arr[6] = {0, 1, 1, 2, 2, 3};
	size_t size = sizeof(arr) / sizeof(int);
	int result = removeDuplicates((int*)arr, size);
	for (int i = 0; i < result; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
    int *current , *end = nums + numsSize - 1;
    int index = 0;

    for ( current = nums + 1; nums < end; nums++, current = nums + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *nums )
            {
                *current = *end--;
                index++;
            }
            else
            {
                current++;
            }
        }
    }
    return numsSize - index;
}