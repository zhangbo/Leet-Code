#include <stdio.h>

int** splitArray(int* arr, size_t n);
int array_sum(int* arr, int size);
void findItemBySum(int* arr, size_t n,  int k, int sum_left, int startIdx, int* tmpArr, int arrIdx);

int main(int argc, char const *argv[])
{
    int temp[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t size = sizeof(temp) / sizeof(int);
    int tmpArr[2];
    findItemBySum((int*)temp, size, 4, 18, 0, (int*)tmpArr, 0);
    // int** splitedArr = splitArray((int*)temp, size);
    return 0;
}

int** splitArray(int* arr, size_t n)
{
    int k = 1, sum_array = array_sum(arr, n);
    int sum_left, sum_right;
    printf("Average number is %.1f\n", (float)(sum_array * 1.0 / n));
    for (; k <= n / 2; ++k)
    {
        if ((sum_array * k) % n == 0 && (sum_array * (n - k)) % n == 0)
        {
            printf("k = %d\n", k);
            printf("left sum is %lu, right sum is %lu\n", (sum_array * k) / n, (sum_array * (n - k)) / n);
        }

    }
    return NULL;
}

int array_sum(int* arr, int size)
{
    int i = 0, sum = 0;
    while (i < size)
    {
        sum += *arr;
        arr++;
        i++;
    }
    return sum; 
}

/*
 *  arr         : 原数组
 *  n           : 原数组长度
 *  k           : 取出的元素数
 *  sum_left    : 目标元素的和
 *  startIdx    : 原数组开始下标
 *  tmpArr      : 中间数组
 *  arrIdx      : 中间数组下标
 */
void findItemBySum(int* arr, size_t n,  int k, int sum_left, int startIdx, int* tmpArr, int arrIdx)
{
    if (n < k)
    {
        return;
    }
    if (startIdx > n - k)
    {
        return;
    }
    if (k == 0)
    {
        if (array_sum(tmpArr, arrIdx) == sum_left)
        {
            for (int i = 0; i < arrIdx; ++i)
            {
                printf("%d ", tmpArr[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = startIdx; i <= (n - k); ++i)
    {
        tmpArr[arrIdx] = arr[i];
        findItemBySum(arr, n, k - 1, sum_left, i + 1, tmpArr, arrIdx + 1);
    }
} 

// [1, 2, 3, 4, 5, 6, 7, 8]

// [2, 3, 5, 8] [1, 4, 6, 7]

// [2, 3, 6, 7] [1, 4, 5, 8]

// [2, 7] [1, 3, 4, 5, 6, 8]

// array_size = n;
// array_left_size = k;
// array_right_size = n - k;

// sum(array) / n = sum(array_left) / k = sum(array_right) / (n - k); 

// sum(array) * k / n = sum(array_left);

// sum(array) * (n - k) / n = sum(array_right);

// 1 <= k <= n/2
// n/2 <= (n - k) <= (n - 1)

// sum(array) - sum(array_left) = sum(array_right)



