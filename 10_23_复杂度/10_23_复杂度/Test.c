#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// �����һ��Func1��++count����ܹ�ִ���˶��ٴΣ�
void Func1(int N) // N*N+2N+10
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}

// ����Func2��ʱ�临�Ӷȣ�
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}

// ����Func3��ʱ�临�Ӷȣ�
void Func3(int N, int M)
{
	int count = 0;
	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
// ����Func4��ʱ�临�Ӷȣ�
void Func4(int N)
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
// ����strchr��ʱ�临�Ӷȣ�
const char* strchr(const char* str, int character);
int main()
{
	// Func1(int N) - N*N+2N+10
	// Func2(int N) - 2N+10
	// Func3(int N, int M) - M+N
	// Func4(int N) - 100
	return 0;
}