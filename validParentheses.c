#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s);
bool isPairExists(char* s, int endAscii, int count);

int main(int argc, char const *argv[])
{
	char* s = "(([]){})";
	printf("%s\n", isValid(s) ? "true" : "false");
	return 0;
}

bool isPairExists(char* s, int endAscii, int count)
{
	int length = strlen(s);
	bool isExist = false;
	for (int i = count + 1; i < length; i += 2)
	{
		if ((int)*(s + i) == endAscii)
		{
			isExist = true;
			break;
		}
	}

	return isExist;
}

bool isValid(char* s)
{
	if (strlen(s) % 2 != 0)
	{
		return false;
	}
	int count = 0, length = strlen(s);
	while (*(s + count) != '\0')
	{
		if ((int)*(s + count) == 40 && !isPairExists(s, 41, count))
		{
			return false;
		}
		else if ((int)*(s + count) == 123 && !isPairExists(s, 125, count))
		{
			return false;
		}
		else if ((int)*(s + count) == 91  && !isPairExists(s, 93, count))
		{
			return false;
		}
		count++;
	}
    return true;
}