#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

unsigned int max_n_line = 0;

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

struct Node* buildLinkedList(struct Node* header)
{
	if (header == NULL)
	{
		return NULL;
	}
	struct Node* newHeader = (struct Node*)malloc(sizeof(struct Node));
	newHeader->value = 1;
	newHeader->next = NULL;
	max_n_line = MAX(newHeader->value, max_n_line);
	struct Node* tempNewHeader = newHeader;
	while (header != NULL)
	{
		struct Node* freeNode = header;
		struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
		if (header->next != NULL)
		{
			tempNode->value = header->value + header->next->value;
		}
		else
		{
			tempNode->value = header->value;
		}
		max_n_line = MAX(newHeader->value, max_n_line);
		tempNode->next = NULL;
		newHeader->next = tempNode;
		newHeader = tempNode;
		header = header->next;
		free(freeNode);
	}
	return tempNewHeader;
}

void printLinkedList(struct Node* header)
{
	if (header == NULL)
	{
		return;
	}
	while (header != NULL)
	{
		printf("%d ", header->value);
		header = header->next;
	}
	printf("\n");
}

void freeLinkedList(struct Node* header)
{
	if (header == NULL)
	{
		return;
	}
	while (header != NULL)
	{
		struct Node* tmpNode = header;
		header = header->next;
		free(tmpNode);
	}
}

void printYangHuiTriangle(unsigned int num)
{
	if (num <= 0)
	{
		return;
	}
	if (num == 1)
	{
		printf("%d\n", num);
	}
	else
	{
		struct Node* header = (struct Node*)malloc(sizeof(struct Node));
		header->value = 1;
		header->next = NULL;
		printLinkedList(header);
		header = buildLinkedList(header);
		printLinkedList(header);
		int i = 0;
		while (true)
		{
			header = buildLinkedList(header);
			printLinkedList(header);
			if (num <= max_n_line)
			{
				freeLinkedList(header);
				break;
			}
			i++;
		}
	}
}

int main(int argc, char const *argv[])
{
	unsigned int number = 555;
	printYangHuiTriangle(number);
	return 0;
}