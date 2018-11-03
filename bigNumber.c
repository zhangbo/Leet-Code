#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int charToInt(char c);
char intToChar(int i);
char* deepcopy(char* str);
char* reverse(char* number);
void bigNumberAdd(char* num1, char* num2);
void bigNumberMultiply(char* num1, char* num2);

int main()
{
	char *a, *firstNumber, *secondNumber;
	for (int i = 0; i < 2; ++i)
	{
		printf("Enter number%d: ", i+1);
		scanf("%s", a);
		if (i == 0)
		{
			firstNumber = deepcopy(a);
		} else {
			secondNumber = deepcopy(a);
		}
	}

	bigNumberAdd(firstNumber, secondNumber);
	printf("\n");
	bigNumberMultiply(firstNumber, secondNumber);

	free(firstNumber);
	free(secondNumber);

	return 0;
}

char* deepcopy(char* str)
{
    size_t length = strlen(str) + 1;
    void* new = malloc(length);
    if (new == NULL)
    {
        return NULL;
    }
    return (char*)memcpy(new, str, length);
}

char* reverse(char* number)
{
	if (number == NULL || strlen(number) == 0)
	{
		return NULL;
	}
	int length = strlen(number);
	char* tmpStr = (char*)malloc((length + 1) * sizeof(char));
	tmpStr[length] = '\0';
	for (int i = 0; i < length; ++i)
	{
		tmpStr[i] = number[length - 1 - i];
	}
	return tmpStr;
}

int charToInt(char c)
{
	return c - '0';
}

char intToChar(int i)
{
	return '0' + i;
}

void bigNumberAdd(char* num1, char* num2)
{
	if (num1 == NULL || num2 == NULL)
	{
		return;
	}

	bool carry = false;
	int n3 = 0;
	int minimum = MIN(strlen(num1), strlen(num2));
	int maximum = MAX(strlen(num1), strlen(num2));
	char *reversedNum1 = reverse(num1), *reversedNum2 = reverse(num2);
	char *longerOne = strlen(num1) > strlen(num2) ? reversedNum1 : reversedNum2;
	char* result = (char*)malloc((maximum + 2) * sizeof(char));
	result[maximum + 1] = '\0';

	for (int i = 0; i < maximum; ++i)
	{
		if (i < minimum)
		{
			n3 = carry ? 1 : 0;
			int num = charToInt(reversedNum1[i]) + charToInt(reversedNum2[i]) + n3;
			if (num >= 10)
			{
				result[i] = intToChar(num % 10);
				carry = true;
			} else {
				result[i] = intToChar(num);
				carry = false;
			}
		} else if (i == minimum) {
			result[minimum] = (longerOne[minimum] + n3);
		} else {
			result[i] = longerOne[i];
		}
	}

	if (carry)
	{
		result[maximum] = intToChar(1);
	}

	char *reversedResult = reverse(result);
	printf("%s\n", reversedResult);

	free(reversedNum1);
	free(reversedNum2);
	free(reversedResult);
	free(result);
}

void bigNumberMultiply(char* num1, char* num2)
{
	if (num1 == NULL || num2 == NULL)
	{
		return;
	}
	int minimum = MIN(strlen(num1), strlen(num2)), maximum = MAX(strlen(num1), strlen(num2)), carry = 0, index = minimum + maximum;
	char *shortOne = strlen(num1) > strlen(num2) ? num2 : num1;
	char *longerOne = strlen(num1) > strlen(num2) ? num1 : num2;
	int *tmpArr;
	char *result;
	tmpArr = (int *)malloc(sizeof(int) * (minimum + maximum + 1));
	tmpArr[minimum + maximum] = '\0';
	memset(tmpArr, 0, sizeof(int) * (minimum + maximum + 1));

	result = (char *)malloc(sizeof(char) * (minimum + maximum + 1));
	result[minimum + maximum] = '\0';

	for (int i = minimum - 1; i >= 0; --i)
	{
		int factor = charToInt(shortOne[i]);
		for (int j = maximum - 1; j >= 0; --j)
		{
			int num = charToInt(longerOne[j]);
			tmpArr[minimum + maximum - 2 - i - j] += (num * factor);
		}
	}

	for (int i = 0; i < (minimum + maximum); ++i)
	{
		int tmpNum = tmpArr[i];
		if ((tmpNum + carry) > 10)
		{
			tmpArr[i] = (tmpNum + carry) % 10;
			carry = (tmpNum + carry) / 10;
		} else {
			tmpArr[i] = (tmpNum + carry);
			carry = 0;
		}
	}

	while (tmpArr[index] == 0) --index;

	for (int i = index; i >= 0; --i)
	{
		result[index - i] = intToChar(tmpArr[i]);
	}

	printf("%s\n", result);
	free(tmpArr);
	free(result);
}