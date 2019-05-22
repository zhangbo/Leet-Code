#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node* next;
} Node;

struct Node* generateLinkedList(int* arr, size_t length)
{
	if (arr == NULL || length == 0)
	{
		return NULL;
	}

	struct Node* header = (struct Node*)malloc(sizeof(struct Node));
	header->val = arr[0];
	header->next = NULL;
	struct Node* root = header;
	for (int i = 1; i < length; ++i)
	{
		struct Node* tmpNode = (struct Node*)malloc(sizeof(struct Node));
		tmpNode->val = arr[i];
		tmpNode->next = NULL;
		header->next = tmpNode;
		header = tmpNode;
	}
	return root;
}

void printLinkedList(struct Node* header)
{
	if (header == NULL)
	{
		return;
	}
	while (header != NULL)
	{
		printf("%d ", header->val);
		header = header->next;
	}
	printf("\n");
}

struct Node* InvertLinkedList(struct Node* header)
{
	if (header == NULL || header->next == NULL)
	{
		return header;
	}
	else
	{
		struct Node* tmpNode = InvertLinkedList(header->next);
		header->next->next = header;
		header->next = NULL;
		return tmpNode;
	}
}

void reversePrintLinkedList(struct Node* header)
{
	if (header == NULL)
	{
		return;
	}
	reversePrintLinkedList(header->next);
	printf("%d ", header->val);
}

int main(int argc, char const *argv[])
{
	int array[5] = {1, 2, 3, 4, 5};
	size_t size = sizeof(array) / sizeof(int);
	struct Node* header = generateLinkedList((int*)array, size);
	printLinkedList(header);
	reversePrintLinkedList(header);
	// header = InvertLinkedList(header);
	// printLinkedList(header);
	return 0;
}