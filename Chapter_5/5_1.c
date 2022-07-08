// Getint problem using pointers
#include <stdio.h>
#include <ctype.h>
int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, d, sign;
    while (isspace(c = getch()))
    {
        ;
    }
    
    if (!isdigit(c) && c != '\n' && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        d = c;
        if (!isdigit(c = getchar()))
        {
            if (c != '\n')
            {
                ungetch(c);
            }
            ungetch(d);
            return d;
        }

        for (*pn = 0; isdigit(c); c = getch())
        {
            *pn = 10 * *pn + (c - '0');
        }

        *pn *= sign;
        if (c != '\n')
        {
            ungetch(c);
        }

        return c;        
    }
    
}
int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("%d", getint(&a));
    return 0;
}