#include <stdio.h>
#include <string.h>

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

void itob(int n, char s[], int base)
{
    int sign, i , d;


    if ((sign = n) < 0)
    {
        n = -n;
    }
    
    i = 0;
    do
    {
        d = n % base;
        s[i++] = (d <= 9) ? d + '0': d + 'a' - 10;
    } while ((n /= base) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);    
}

int main()
{
    int n;
    int base = 16;
    char arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }

    printf("Enter your number: ");
    scanf("%d", &n);

    printf("Base chosen 16\n");

    itob(n, arr, base);
    printf("%s", arr);
    
    return 0;
}