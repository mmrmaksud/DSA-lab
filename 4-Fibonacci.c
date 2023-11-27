#include <stdio.h>
int fibo(int m)
{
    if (m < 2)
        return m;
    return fibo(m - 1) + fibo(m - 2);
}
int main()
{
    int n, i;
    printf("Enter the value: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        printf("%d ", fibo(i));

    return 0;
}