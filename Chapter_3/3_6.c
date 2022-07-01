#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x): (x))

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int w)
{
    int sign, i;

    sign = n;
    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    while (i < w)
    {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);    
}

int main()
{
    int n, w;
    char arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter w: ");
    scanf("%d", &w);
    
    itoa(n, arr, w);
    printf("%s", arr);
    return 0;
}