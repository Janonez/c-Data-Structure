#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//// 请计算一下Func1中++count语句总共执行了多少次？
//void Func1(int N) // N*N+2N+10
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//// 计算Func2的时间复杂度？
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//// 计算Func3的时间复杂度？
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//// 计算Func4的时间复杂度？
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//// 计算strchr的时间复杂度？
//const char* strchr(const char* str, int character);
//int main()
//{
//	// Func1(int N) - N*N+2N+10
//	// Func2(int N) - 2N+10
//	// Func3(int N, int M) - M+N
//	// Func4(int N) - 100
//	return 0;
//}


//int missingNumber(int* nums, int numsSize) 
//{
//    
//    // 
//    /*
//    int N = numsSize;
//    int sum = (N+1)*N/2;
//    for(size_t i = 0;i<N;i++)
//    {
//        sum -= nums[i];
//    }
//    return sum;
//    */
//
//
//    int N = numsSize;
//    int i = 0;
//    int x = 0;
//    for (i = 0; i < N; i++)
//    {
//        x ^= nums[i];
//    }
//    for (i = 0; i <= N; i++)
//    {
//        x ^= i;
//    }
//    return x;
//}



void reverse(int* nums, int left, int right)
{
    int tmp = 0;
    while (left < right)
    {
        tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k)
{

    k = k % numsSize;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

    for (int i = 0; i < numsSize - 1; i++)
    {
        printf("%d ", nums[i]);
    }
}
