// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 6.	  312211
// 7.	  13112221
// 8.     1113213211
// 9.	  31131211131221


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
} Node;

char* countAndSay(int n);
void test();
void freeLinkList(Node* head);

int main(int argc, char const *argv[])
{
	clock_t begin = clock();
	printf("%s\n", countAndSay(49));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	// test();
	return 0;
}

char* countAndSay(int n) {

    if(n == 1) return "1";

    char * cur = malloc(2);
    char * temp;
    cur[0] = '1';
    cur[1] = 0;

    int len, idx, j, count;
    for(int i = 2; i <= n; i++) {

        len = strlen(cur);
        temp = malloc(3 * len);
        memset(temp, 0, 3 * len);
        count = 1;
        for(idx = 1, j = 0; idx < len; idx++) {
            if(cur[idx] == cur[idx - 1]) count++;
            else {
                temp[j++] = '0' + count;
                temp[j++] = cur[idx - 1];
                count = 1;
            }
        }
        temp[j++] = '0' + count;
        temp[j] = cur[len - 1];
        free(cur);
        cur = temp;
    }
    return cur;
}

// char* countAndSay(int n)
// {
// 	if (n == 1)
// 	{
// 		return (char *)"1";
// 	}
// 	if (n > 30)
// 	{
// 		return NULL;
// 	}

// 	char *chr = countAndSay(n - 1);
// 	int i = 1, count = 0;
// 	int countLength = 0;	//计算位数
// 	char tmpChr = *chr;
// 	//必须指定head初始化为NULL，不然的话，Node* head; head不是NULL
// 	Node *head = NULL, *nxt = NULL, *realHead = NULL;
// 	while (*(chr + i) != '\0')
// 	{
// 		count++;
// 		if (tmpChr != *(chr + i))
// 		{
// 			//添加链表
// 			if (!head)
// 			{
// 				head = (Node*)malloc(sizeof(Node));
// 				nxt = (Node*)malloc(sizeof(Node));
// 				head->val = count;
// 				nxt->val = tmpChr - '0';
// 				nxt->next = NULL;
// 				head->next = nxt;
// 				realHead = head;
// 			}
// 			else
// 			{
// 				head = (Node*)malloc(sizeof(Node));
// 				head->val = count;
// 				head->next = NULL;
// 				nxt->next = head;
// 				nxt = (Node*)malloc(sizeof(Node));
// 				nxt->val = tmpChr - '0';
// 				nxt->next = NULL;
// 				head->next = nxt;
// 			}
// 			countLength += 2;
// 			tmpChr = *(chr + i);
// 			count = 0;
// 		}
// 		i++;
// 	}

// 	count++;
// 	countLength += 2;
// 	//添加链表最后两位
// 	if (!head)
// 	{
// 		head = (Node*)malloc(sizeof(Node));
// 		nxt = (Node*)malloc(sizeof(Node));
// 		head->val = count;
// 		nxt->val = tmpChr - '0';
// 		nxt->next = NULL;
// 		head->next = nxt;
// 		realHead = head;
// 	}
// 	else
// 	{
// 		head = (Node*)malloc(sizeof(Node));
// 		head->val = count;
// 		head->next = NULL;
// 		nxt->next = head;
// 		nxt = (Node*)malloc(sizeof(Node));
// 		nxt->val = tmpChr - '0';
// 		nxt->next = NULL;
// 		head->next = nxt;
// 	}

// 	chr = NULL;

// 	count = 0;
// 	char* currentResult = (char*)malloc(countLength * sizeof(char));
// 	head = realHead;
// 	while (head)
// 	{
// 		currentResult[count] = '0' + head->val;
// 		head = head->next;
// 		count++;
// 	}
// 	freeLinkList(realHead);
// 	// printf("n = %d, result = %s\n", n, currentResult);
// 	return currentResult;

// }

void freeLinkList(Node* head)
{
	if (!head)
	{
		return;
	}
	if (head->next != NULL)
	{
		freeLinkList(head->next);
	}

	free(head);
}

void test()
{
	char* tmp = "11";
	int i = 1, count = 0;
	int countLength = 0;
	char tmpChr = *tmp;
	while (*(tmp + i) != '\0')
	{
		count++;
		if (tmpChr != *(tmp + i))
		{
			printf("%d%d ", count, tmpChr - '0');
			countLength += 2;
			tmpChr = *(tmp + i);
			count = 0;
		}
		i++;
	}
	count++;
	printf("%d%d\n", count, tmpChr - '0');
	countLength += 2;
	printf("Length is %d\n", countLength);
}
