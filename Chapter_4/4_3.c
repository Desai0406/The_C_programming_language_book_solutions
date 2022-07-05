// Extend the given problem calculator by adding the modulus operation.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100


int getop(char s[]);
int sp = 0;
int bufp = 0;
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
double atof(char string[]);
double val[MAXVAL];
char buf[BUFSIZE];


int main()
{
    int type;
    double sub_op2, mod_op2;
    char s[MAXOP]; // Initialize array here

    while ((type = getop(s)) != '\n')
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            sub_op2 = pop();
            if (sub_op2 != 0.0)
            {
               push(pop() - sub_op2);
            }
            else
            {
                printf("Division error with 0!");
            }
        case '%':
            mod_op2 = pop();
            if (mod_op2 != 0.0)
            {
                push(fmod(pop(), mod_op2));
            }
            else
            {
                printf("Division erros with 0!");
            }
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Unknown command!");
            break;
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("Error: Stack is full!");
    } 
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("Error: The stack is empty");
        return 0.0;
    }
}

int getch(void)
{
    return (bufp > 0 ? buf[--bufp]: getchar());
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("Error: Buffer is full");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getop(char s[])
{
    int c, i;
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
    {
        ;
    }

    s[1] = '\0';
    i = 0;

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != '\n')
            {
                ungetch(c);
            }
            return '-';
        }   
    }

    if (isdigit(c))
    {
        while (isdigit(s[i++] = c = getch()))
        {
            ;
        }
    }

    if (c == '.')
    {
        while (isdigit(s[i++] = c = getch()))
        {
            ;
        }
    }

    s[i] = '\0';
    if (c != '\n')
    {
        ungetch(c);
    }

    return NUMBER;    
}