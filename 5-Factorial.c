#include <stdio.h>
int fact(int f)
{
    if (f == 0 && 1)
        return 1;
    else
        return f * fact(f - 1);
}
int main()
{
    int n;
    printf("What number factorial do you want? ");
    scanf("%d", &n);
    printf("Factorial: %d! = %d", n, fact(n));

    return 0;
}