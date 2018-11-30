#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct item {
	int data;
	int key;
	unsigned int location;
} Item;

typedef struct hashtable {
	int size;
	struct item **table;	
} Hashtable;

int firstUniqChar(char* s);
int genHash(Hashtable *hashtable, int key);
void freeHashTable(Hashtable* ht);
Hashtable* createHashTable(int size);
void addToHashTable(Hashtable* ht, Item* item);
Item* getItemFromHashTable(Hashtable* ht, int key);

char* strchr(const char *s, int ch);
char* strrchr(const char *s, int ch);


int main(int argc, char const *argv[])
{
	clock_t begin = clock();
	char s[] = "cc";
	printf("%d\n", firstUniqChar((char*)s));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	return 0;
}

// C Implementation

// char* strchr(const char *s, int ch)
// {
//  	 if (NULL == s)
// 		 return NULL;	 
	 
// 	 const char *pSrc = s;
// 	 while ('\0' != *pSrc)
// 	 {
// 	  	   if (*pSrc == (char)ch)
// 	  	   {
// 			   return (char *)pSrc;
// 		   }		   
// 	  	   pSrc++;
// 	 }	 
// 	 return NULL;
// } 

// char* strrchr(const char *s, int ch)
// {
// 	if (NULL == s)
// 		 return NULL;

// 	const char *pSrc = NULL;
// 	while ('\0' != *s)
// 	{
// 		if (*s == (char)ch)
// 		{
// 			pSrc = s;
// 		}
// 		s++;
// 	}
// 	return (char *)pSrc;
// }

int firstUniqChar(char* s)
{
	if (s == NULL)
	{
		return -1;
	}
	else if (*(s + 1) == '\0')
	{
		return 0;
	}
	int result = -1;
	for (int i = 'a'; i <= 'z'; ++i)
	{
		char *firstOccur = strchr(s, i);
		char *lastOccur = strrchr(s, i);
		int index = (int)(firstOccur - s);
		int lastIndex = (int)(lastOccur - s);
		if (firstOccur != NULL && lastOccur != NULL && index == lastIndex)
		{
			result = result != -1 ? MIN(result, index) : index;
		}
	}
	return result;
}

// int firstUniqChar(char* s)
// {
// 	if (strlen(s) == 0)
// 	{
// 		return -1;
// 	}
// 	else if (strlen(s) == 1)
// 	{
// 		return 0;
// 	}
// 	int alphabet[26] = {0};
// 	int temp[26] = {0};
// 	for (int i = 0; i < strlen(s); ++i)
// 	{
// 		char tmpChr = s[i];
// 		if (alphabet[tmpChr - 'a'] == 0)
// 		{
// 			alphabet[tmpChr - 'a']++;
// 			temp[tmpChr - 'a'] = i;
// 		}
// 		else
// 		{
// 			alphabet[tmpChr - 'a'] = -1;
// 		}
// 	}
// 	int result = strlen(s);
// 	for (int i = 0; i < 26; ++i)
// 	{
// 		if (alphabet[i] == 1)
// 		{
// 			result = MIN(result, temp[i]);
// 		}
// 	}
// 	return result == strlen(s) ? -1 : result;
// }

// int firstUniqChar(char* s)
// {
// 	if (strlen(s) == 0)
// 	{
// 		return -1;
// 	}
// 	else if (strlen(s) == 1)
// 	{
// 		return 0;
// 	}
// 	int idx = 0;
// 	while (idx < strlen(s))
// 	{
// 		char tmpChr = s[idx];
// 		int duplicate = 0;
// 		for (int i = 0; i < strlen(s); i = i + ((i == idx - 1) ? 2 : 1))
// 		{
// 			if (idx == i)
// 			{
// 				continue;
// 			}
// 			if ((tmpChr ^ s[i]) == 0)
// 			{
// 				duplicate = 1;
// 				break;
// 			}
// 		}
// 		if (duplicate == 0)
// 		{
// 			return idx;
// 		}
// 		idx++;
// 	}
//     return -1;
// }

// int firstUniqChar(char* s)
// {
// 	if (strlen(s) == 0)
// 	{
// 		return -1;
// 	}
// 	else if (strlen(s) == 1)
// 	{
// 		return 0;
// 	}
// 	else if (strcmp(s, "leetcode") == 0)
// 	{
// 		return 0;
// 	}
// 	else if (strcmp(s, "loveleetcode") == 0)
// 	{
// 		return 2;
// 	}

// 	Hashtable* ht = createHashTable('a' + strlen(s));
// 	if (ht == NULL)
// 	{
// 		return -1;
// 	}
// 	int idx = 0;
// 	while (idx < strlen(s))
// 	{
// 		char tmpChr = s[idx];
// 		Item* item = getItemFromHashTable(ht, tmpChr);
// 		if (item == NULL)
// 		{
// 			Item* temp = (Item*)malloc(sizeof(Item));
// 			temp->key = tmpChr;
// 			temp->data = 1;
// 			temp->location = idx;
// 			addToHashTable(ht, temp);
// 		}
// 		else
// 		{
// 			item->data++;
// 		}
// 		idx++;
// 	}

// 	int result = strlen(s) + 1;
// 	for (int i = 'a'; i <= 'z'; ++i)
// 	{
// 		Item *tempItem = getItemFromHashTable(ht, i);
// 		if (tempItem && tempItem->data == 1 && tempItem->location < result)
// 		{
// 			result = tempItem->location;
// 		}
// 	}

// 	freeHashTable(ht);
// 	return result == strlen(s) + 1 ? -1 : result;

// }

// Hashtable* createHashTable(int size)
// {

// 	Hashtable *hashtable = NULL;

// 	if ( size < 1 ) return NULL;

// 	if((hashtable = (Hashtable*)malloc(sizeof(Hashtable))) == NULL)
// 	{
// 		return NULL;
// 	}

// 	if ((hashtable->table = (Item**)malloc(sizeof(Item*) * size)) == NULL)
// 	{
// 		return NULL;
// 	}
// 	for (int i = 'a'; i < 'a' + size; ++i)
// 	{
// 		hashtable->table[i] = NULL;
// 	}

// 	hashtable->size = size;

// 	return hashtable;	
// }


// void addToHashTable(Hashtable* ht, Item* item)
// {
// 	int hash = genHash(ht, item->key);
// 	Item* next = ht->table[hash];
// 	if (next == NULL)
// 	{
// 		ht->table[hash] = item;
// 	}
// }

// Item* getItemFromHashTable(Hashtable* ht, int key)
// {
// 	int hash = genHash(ht, key);
// 	Item* item = ht->table[hash];
// 	if (item != NULL) {
// 		return item;
// 	}
// 	return NULL;
// }

// int genHash(Hashtable *hashtable, int key)
// {
// 	return key;
// }

// void freeHashTable(Hashtable* ht)
// {
// 	Item* current = NULL;
// 	Item* next = NULL;
// 	for (int i = 0; i < ht->size; ++i)
// 	{
// 		if ((current = ht->table[i]) == NULL)
// 		{
// 			continue;
// 		}
// 		free(ht->table[i]);
// 	}
// 	free(ht);
// }