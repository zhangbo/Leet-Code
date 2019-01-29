#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

uint32_t reverseBits(uint32_t n);

int main(int argc, char const *argv[])
{
	//2147483648 4294967295
	printf("%u\n", reverseBits(4294967295));
	return 0;
}

uint32_t reverseBits(uint32_t n)
{
	if (n > UINT_MAX)
	{
		return 0;
	}
	int arr[32] = {0};
	int i = 0;
	while (n != 0)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
	}

	uint32_t sum = 0;
	for (int j = 0; j < 32; ++j)
	{
		sum += (arr[j] == 1) ? pow(2, 31 - j) : 0;
	}
	return sum;
}