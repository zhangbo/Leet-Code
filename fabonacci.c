/*

Dynamic Programming

1. 计数 通过n种资源去完成
2. 优化 走多少步、最优解

与递归的相似和区别
DP其实是一种编程方法。非常灵活，但有模板参照

先决条件
1. 最优子结构
分解最优子问题，组合起来变成最优解
2. 同样的子问题会被求解多次
子问题重叠我们只需要对子问题求解一次并且存储，为后续计算提供子问题结果。
减少时间复杂度

3. 无后效性
子问题的最优解是确定的
原问题会用到子问题的最优解，子问题的最优解不会影响到原问题的决策。

*/

#include <stdio.h>
#include <time.h>

long long fabonacci(int x);
long long fabonacci_recursive(int* arr, int x);
long long fabonacci_dp1(int* arr, int x);
long long fabonacci_dp2(int x);

#ifndef SIZE
#define SIZE 45
#endif

int main(int argc, char const *argv[])
{
	int arr[SIZE] = {0};
	clock_t begin = clock();
	printf("%lld\n", fabonacci(SIZE));
	// printf("%lld\n", fabonacci_recursive((int*)arr, SIZE));
	// printf("%lld\n", fabonacci_dp1((int*)arr, SIZE));
	// printf("%lld\n", fabonacci_dp2(SIZE));
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	return 0;
}

//时间复杂度 O(2ⁿ) 空间复杂度 O(n)
long long fabonacci(int x)
{
	if (x == 0)
	{
		return 0;
	}
	else if (x == 1)
	{
		return 1;
	}
	return fabonacci(x - 1) + fabonacci(x - 2);
}

//时间复杂度 O(n) 空间复杂度 O(n)
long long fabonacci_recursive(int* arr, int x)
{
	if (x == 0)
	{
		arr[x] = 0;
		return arr[x];
	}
	else if (x == 1)
	{
		arr[x] = 1;
		return arr[x];
	}

	if (arr[x - 1] == 0)
	{
		arr[x - 1] = fabonacci_recursive(arr, x - 1) + fabonacci_recursive(arr, x - 2);
	}
	return arr[x - 1];
}

//时间复杂度 O(n) 空间复杂度 O(n)
long long fabonacci_dp1(int* arr, int x)
{
	arr[0] = 1, arr[1] = 1;

	for (int i = 2; i < x; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[x - 1];
}

//时间复杂度 O(n) 空间复杂度 O(1)
long long fabonacci_dp2(int x)
{
	int dp1 = 0, dp2 = 1, tmp = 0;
	for (int i = 2; i < x + 1; ++i)
	{
		tmp = dp2;
		dp2 += dp1;
		dp1 = tmp;
	}
	return dp2;
}