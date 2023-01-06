#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//    int n;
//    int count = 0;
//    int m = 10;
//    while (scanf("%d", &n) != EOF)
//    { // 注意 while 处理多个 case
//        // 64 位输出请用 printf("%lld") to 
//        
//        for (int i = 0; i <= n; i++)
//        {
//            if (i >= m)
//                m *= 10;
//
//            if ((i * i - i) % m == 0)
//            {
//                printf("%d ", i);
//                count++;
//            }
//        }
//        printf("%d", count);
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int is_prime(int i)
//{
//    for (int j = 2; j <= sqrt(i); j++)
//    {
//        if (i % j == 0)
//            return 0;
//    }
//    return 1;
//}
//int main()
//{
//    int N = 0;
//    int count = 0;
//    while (scanf("%d", &N) != EOF)
//    {
//        for (int i = 2; i <= N; i++)
//        {
//            if (is_prime(i))
//            {
//                count++;
//            }
//        }
//        printf("%d\n", count);
//    }
//    return 0;
//}


int FirstNotRepeatingChar(char* str)
{
    // write code here
    int arr[150];
    // 初始化数组为0
    for (int i = 0; i < 150; i++)
    {
        arr[i] = 0;
    }
    for (int j = 0; j < strlen(str); j++)
    {
        //int num = *(str+j)
        arr[str[j]]++;
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (arr[str[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}