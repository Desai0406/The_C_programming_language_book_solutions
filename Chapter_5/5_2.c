// getfloat using pointers
#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getchar()))
    {
        ;
    }

    if (!isdigit(c) && c != '\n' && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c =getch();
    }
    
    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + ( c - '0');
        power *= 10.0;
    }

    *pn *= sign/power;
    if (c != '\n')
    {
        ungetch(c);
    }
    return c;
    
    
    
}