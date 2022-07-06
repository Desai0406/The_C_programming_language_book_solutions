// Itoa function that uses recursion implementation
#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x): (x))

void itoa(int n, char s[])
{
    static int i = 0;
    if ((n / 10) > 0) 
    {
        itoa(n / 10, s);
    }

    s[i++] = (n % 10 + '0');
}

int main()
{
    int n;
    char arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }

    printf("Enter n: ");
    scanf("%d", &n);

    itoa(n, arr);
    printf("%s", arr);
    return 0;
}