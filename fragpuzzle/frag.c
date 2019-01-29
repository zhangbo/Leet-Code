#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct step {
	int* currentStep;
	struct step* next;
} Step;

void freeLink(Step* header);
void popLastStep(Step* header);
void swap(int* arr, int a, int b);
bool isValid(int idx, size_t size);
void printStep(Step* header, size_t size);
bool isEqual(int* start, int* end, size_t size);
void append(Step* header, int* arr, size_t size);
bool bruteforce(int* start, int* end, size_t size, Step* header);

int main(int argc, char const *argv[])
{
	int start[9] = {1, 1, 1, 1, 0, -1, -1, -1, -1};
	int end[9] = {-1, -1, -1, -1, 0, 1, 1, 1, 1};
	size_t size = sizeof(start) / sizeof(int);
	Step* header = (Step*)malloc(sizeof(Step));
	header->currentStep = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; ++i)
	{
		header->currentStep[i] = start[i];
	}
	header->next = NULL;
	bruteforce((int*)start, (int*)end, size, header);
	freeLink(header);
	return 0;
}

void append(Step* header, int* arr, size_t size)
{
	if (header == NULL)
	{
		return;
	}
	while (header->next != NULL)
	{
		header = header->next;
	}
	Step* tmpStep = (Step*)malloc(sizeof(Step));
	tmpStep->currentStep = (int*)malloc(sizeof(int) * size);
	tmpStep->next = NULL;
	for (int i = 0; i < size; ++i)
	{
		tmpStep->currentStep[i] = arr[i];
	}
	header->next = tmpStep;
}

void popLastStep(Step* header)
{
	if (header == NULL)
	{
		return;
	}
	Step* tmpStep = NULL;
	while (header->next != NULL)
	{
		tmpStep = header;
		header = header->next;
	}
	tmpStep->next = NULL;
	free(header);
}

void freeLink(Step* header)
{
	if (header == NULL)
	{
		return;
	}
	while (header->next != NULL)
	{
		Step* tmpStep = header;
		header = header->next;
		free(tmpStep);
	}
	free(header);
}

void printStep(Step* header, size_t size)
{
	if (header == NULL)
	{
		return;
	}
	while (header != NULL)
	{
		for (int i = 0; i < size; ++i)
		{
			printf("%s ", header->currentStep[i] == 1 ? "♖" : (header->currentStep[i] == 0 ? "▁" : "♜"));
		}
		printf("\n");
		header = header->next;
	}
}

void swap(int* arr, int a, int b)
{
	arr[a] = arr[a] ^ arr[b];
	arr[b] = arr[b] ^ arr[a];
	arr[a] = arr[a] ^ arr[b];
}

bool isValid(int idx, size_t size)
{
	return idx >= 0 && idx < size;
}

bool isEqual(int* start, int* end, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		if (start[i] != end[i])
		{
			return false;
		}
	}
	return true;
}

bool bruteforce(int* start, int* end, size_t size, Step* header)
{
	if (isEqual(start, end, size))
	{
		printStep(header, size);
		return true;
	}
	
	for (int i = 0; i < size; ++i)
	{
		int direction = start[i];
		if (direction == 1 || direction == -1)
		{
			if (isValid(i + direction, size) && start[i + direction] == 0)
			{
				swap(start, i, i + direction);
				append(header, start, size);
				if (bruteforce(start, end, size, header))
				{
					return true;
				}
				swap(start, i, i + direction);
				popLastStep(header);
			}
			else if (isValid(i + 2 * direction, size) && start[i + 2 * direction] == 0)
			{
				swap(start, i, i + 2 * direction);
				append(header, start, size);
				if (bruteforce(start, end, size, header))
				{
					return true;
				}
				swap(start, i, i + 2 * direction);
				popLastStep(header);
			}
		}
	}
	return false;
}
