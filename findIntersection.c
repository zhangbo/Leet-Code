#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

Node* delNode(Node* head, int data);
Node* array2LinkedList(int array[], size_t length);

int main(int argc, char const *argv[])
{
	int arr1[5] = {9, 4, 9, 8, 4};
	int arr2[3] = {4, 9, 5};
	size_t length1 = sizeof(arr1) / sizeof(int);
	size_t length2 = sizeof(arr2) / sizeof(int);
	Node* head1 = array2LinkedList(arr1, length1);
	Node* head2 = array2LinkedList(arr2, length2);
	Node* current = head1;
	while (current->next != NULL && head2 != NULL) {
		head2 = delNode(head2, current->data);
		current = current->next;
		if (current->next == NULL)
		{
			head2 = delNode(head2, current->data);
		}
	}
	return 0;
}

Node* delNode(Node* head, int data)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->data == data)
	{
		free(head);
		printf("find %d\n", data);
		return head->next;
	}
	Node* current = head;
	while (current->next != NULL) {
		Node* prev = current;
		current = current->next;
		if (current->data == data)
		{
			prev->next = current->next;
			printf("find %d\n", data);
			free(current);
			break;
		}
	}
	return head;
}

Node* array2LinkedList(int array[], size_t length)
{
	if (array == NULL || length == 0)
	{
		return NULL;
	}
	Node* head = (Node*)malloc(sizeof(Node));
	Node* current = head;
	for (int i = 0; i < length; ++i)
	{
		current->data = array[i];
		if (i == length - 1)
		{
			current->next = NULL;
			break;
		}
		Node* temp = (Node*)malloc(sizeof(Node));
		current->next = temp;
		current = temp;
	}
	return head;
}