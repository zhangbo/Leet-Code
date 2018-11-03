#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct item {
	int data;
	int key;
	struct item* next;
} Item;

typedef struct hashtable {
	int size;
	struct item **table;	
} Hashtable;

int* twoSum(int* nums, int numsSize, int target);
void freeHashTable(Hashtable* ht);
Hashtable* createHashTable(int size);
int genHash(Hashtable *hashtable, int key);
void addToHashTable(Hashtable* ht, Item* item);
Item* getItemFromHashTable(Hashtable* ht, int key);

int main(int argc, char const *argv[])
{
	int arr[24] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46};
	int length = sizeof(arr) / sizeof(int);
	clock_t begin = clock();
	int* tmpArr = twoSum(&arr[0], length, 66);
	if (tmpArr == NULL)
	{
		printf("Not Found!!!\n");
		return 0;
	}
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n", tmpArr[i]);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	free(tmpArr);
	return 0;
}

int* twoSum(int* nums, int numsSize, int target)
{
	Hashtable* ht = createHashTable(numsSize);
	if (ht == NULL)
	{
		return NULL;
	}
	int* resultArr = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; ++i)
	{
		int key = target - nums[i];
		Item* tmpItem = getItemFromHashTable(ht, key);
		if (tmpItem == NULL)
		{
			Item* item = (Item*)malloc(sizeof(Item));
			item->data = i;
			item->key = nums[item->data];
			addToHashTable(ht, item);
		} else {
			resultArr[0] = tmpItem->data;
			resultArr[1] = i;
			freeHashTable(ht);
			return resultArr;
		}
	}
	freeHashTable(ht);
	return NULL;
}

void freeHashTable(Hashtable* ht)
{
	Item* current = NULL;
	Item* next = NULL;
	for (int i = 0; i < ht->size; ++i)
	{
		if ((current = ht->table[i]) == NULL)
		{
			continue;
		}
		while (current->next != NULL) {
			next = current->next;
			free(current);
			current = next;
		}
	}
	free(ht);
}

Hashtable* createHashTable(int size)
{

	Hashtable *hashtable = NULL;

	if( size < 1 ) return NULL;

	if((hashtable = (Hashtable*)malloc(sizeof(Hashtable))) == NULL)
	{
		return NULL;
	}

	if((hashtable->table = (Item**)malloc(sizeof(Item*) * size)) == NULL)
	{
		return NULL;
	}
	for(int i = 0; i < size; ++i)
	{
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}


void addToHashTable(Hashtable* ht, Item* item)
{
	int hash = genHash(ht, item->key);
	Item* next;
	Item* last;
	next = ht->table[hash];
	while (next != NULL && item->key > next->key) {  //  23 3 --> 13  35  45
		last = next;
		next = next->next;
	}

	if(next != NULL && item->key == next->key)
	{
		next->data = item->data;

	} else {

		if( next == ht->table[hash]) {
			item->next = next;
			ht->table[hash] = item;
		} else if (next == NULL) {
			item->next = NULL;
			last->next = item;
		} else  {
			item->next = next;
			last->next = item;
		}
	}
}

Item* getItemFromHashTable(Hashtable* ht, int key)
{
	int hash = genHash(ht, key);
	Item* item = ht->table[hash];
	while(item != NULL && key > item->key) {
		item = item->next;
	}

	if(item == NULL || key != item->key) {
		return NULL;
	} else {
		return item;
	}
}

int genHash(Hashtable *hashtable, int key)
{

	unsigned long int hashval;
	int i = 0;

	while(hashval < ULONG_MAX && (int)(key / pow(10, i)) > 0) {
		hashval = hashval << 8;
		int num = pow(10, i + 1);
		hashval += (int)(key % num / pow(10, i));
		i++;
	}

	return hashval % hashtable->size;
}

// int* twoSum(int* nums, int numsSize, int target)
// {
// 	Item* head = NULL;
// 	Item* current = NULL;
// 	head = (Item*)malloc(sizeof(Item));
// 	head->data = 0;
// 	head->key = nums[head->data];
// 	head->next = NULL;
// 	int* resultArr = (int*)malloc(sizeof(int) * 2);
// 	for (int i = 1; i < numsSize; ++i)
// 	{
// 		int key = target - nums[i];
// 		current = head;
// 		if (current->key == key)
// 		{
// 			// found it!!!
// 			resultArr[0] = i;
// 			resultArr[1] = current->data;
// 			return resultArr;
// 		} else {
// 			while (current->next != NULL) {
// 				current = current->next;
// 				if (current->key == key)
// 				{
// 					//found it!!!
// 					resultArr[0] = i;
// 					resultArr[1] = current->data;
// 					return resultArr;
// 				}
// 			}
// 			Item* tmpItem = (Item*)malloc(sizeof(Item));
// 			tmpItem->data = i;
// 			tmpItem->key = nums[tmpItem->data];
// 			tmpItem->next = NULL;
// 			current->next = tmpItem;
// 		}
// 	}
// 	return NULL;
// }

// int* twoSum(int* nums, int numsSize, int target)
// {
// 	for (int i = 0; i < numsSize - 1; ++i)
// 	{
// 		for (int j = i + 1; j < numsSize; ++j)
// 		{
// 			if (nums[i] + nums[j] == target)
// 			{
// 				int* resultArr = (int*)malloc(sizeof(int) * 2);
// 				resultArr[0] = i;
// 				resultArr[1] = j;
// 				return resultArr;
// 			}
// 		}
// 	}
// 	return NULL;
// }

// int* twoSum(int* nums, int numsSize, int target)
// {
// 	int i = numsSize - 1;
// 	size_t idx = 0;
// 	size_t k = 0;
// 	for (; i > 0; --i)
// 	{
// 		k += i;
// 	}
//     int* tmpArr = (int*)malloc(sizeof(int) * k);
//     int* resultArr = (int*)malloc(sizeof(int) * 2);
//     for (int m = 0; m < numsSize - 1; ++m)
//     {
//     	for (int j = m + 1; j < numsSize; ++j)
//     	{
//     		tmpArr[idx] = nums[m] + nums[j];
//     		idx++;
//     	}
//     }

//     int index = 0, times = 0, sums = 0;

//     for (int i = 0; i < k; ++i)
//     {
//     	if (tmpArr[i] == target)
//     	{
//     		index = i;
//     		break;
//     	}
//     }

//     free(tmpArr);

//     for (int i = numsSize - 1; i >= 1; --i)
//     {
//     	sums += i;
//     	if (index < sums)
//     	{
//     		break;
//     	}
//     	times++;
//     	if (index == sums)
//     	{
//     		break;
//     	}
//     }

//     resultArr[0] = times;
    
//     for (int i = times + 1; i < numsSize; ++i)
//     {
//     	if (nums[times] + nums[i] == target)
//     	{
//     		resultArr[1] = i;
//     	}
//     }

//     return resultArr;

// }