#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNodeTable {
	int currentIdx;
	struct TreeNode** tableArr;
};

struct TreeNode* generateBinaryTree(int* tmpArr, size_t length, struct TreeNode* root, size_t idx)
{
	if (idx < length)
	{
		struct TreeNode* currentNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		currentNode->val = tmpArr[idx];
		currentNode->left = NULL;
		currentNode->right = NULL;
		root = currentNode;
		root->left = generateBinaryTree(tmpArr, length, root->left, 2 * idx + 1);
		root->right = generateBinaryTree(tmpArr, length, root->right, 2 * idx + 2);
	}
	return root;
}

void printBinaryTree(struct TreeNode* root)
{
	if (root != NULL)
	{
		printBinaryTree(root->left);
		printf("%d ", root->val);
		printBinaryTree(root->right);
	}
}

int maxDepth(struct TreeNode* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}

void printBinaryTreeByLevel(struct TreeNode* root, size_t length)
{
	struct TreeNodeTable* table = (struct TreeNodeTable*)malloc(sizeof(struct TreeNodeTable));
	table->currentIdx = 0;
	table->tableArr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * length);
	for (int i = 0; i < length; ++i)
	{
		if (i == 0)
		{
			table->tableArr[i] = root;
		}
		else
		{
			table->tableArr[i] = NULL;
		}
	}

	int j = 0;
	int insertIdx = 1; //insert from 1 because root node has already exists
	while (table->currentIdx < length)
	{
		for (int i = 0; i < pow(2, j); ++i)
		{
			struct TreeNode* treeNode = table->tableArr[table->currentIdx + i];
			if (treeNode != NULL && treeNode->left != NULL && insertIdx < length)
			{
				// table->tableArr[table->currentIdx + 2 * i + (int)pow(2, j)] = treeNode->left;
				table->tableArr[insertIdx] = treeNode->left;
				insertIdx++;
			}
			if (treeNode != NULL && treeNode->right != NULL && insertIdx < length)
			{
				// table->tableArr[table->currentIdx + 2 * i + (int)pow(2, j) + 1] = treeNode->right;
				table->tableArr[insertIdx] = treeNode->right;
				insertIdx++;
			}
		}
		table->currentIdx += pow(2, j);
		j++;
	}

	j = 0;
	while (table->tableArr[j] != NULL)
	{
		struct TreeNode* tempNode = table->tableArr[j];
		printf("%d ", tempNode->val);
		j++;
	}
	printf("\n");
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct TreeNode* tempNode = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(tempNode);
	return root;
}

int main(int argc, char const *argv[])
{
	int arr[9] = {4, 2, 7, 1, 3, 6, 9, 5, 8};
	struct TreeNode* rootNode = generateBinaryTree((int*)arr, sizeof(arr) / sizeof(int), NULL, 0);
	printBinaryTreeByLevel(rootNode, sizeof(arr) / sizeof(int));
	// printBinaryTree(rootNode);
	// printf("\n");
	invertTree(rootNode);
	// printBinaryTree(rootNode);
	// printf("\n");
	// printf("Binary Tree's depth is %u\n", maxDepth(rootNode));
	printBinaryTreeByLevel(rootNode, sizeof(arr) / sizeof(int));
	return 0;
}