// Extend the given problem calculator by adding the clear, duplicate & swap, and print the top element without popping operation.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
int bufp = 0;
int getop(char s[]);
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
    double sub_op2, mod_op2, op1, op2;
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
        case 't':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clearStack();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
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

int main()
{
    int len;
    float atofl(char string[]);
    char stringmain[100];
    for (int i = 0; i < 100; i++)
    {
        stringmain[i] = 0;
    }
    
    printf("Enter your string: ");
    scanf("%s", stringmain);

    len = strlen(stringmain);
    len++;
    stringmain[len] = '\0';
    
    printf("The value in float is: %f", atofl(stringmain));
    return 0;
}

double atof(char string[])
{
    int i, sign, exponent;
    float val, power, finalVal;

    for (i = 0; isspace(string[i]); i++) // Check for whitespaces
    {
        ;
    }

    sign = (string[i] == '-') ? -1 : 1; // Check if sign is negative and record it

    if (string[i] == '+' || string[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(string[i]); i++) // Add value before decimal point
    {
        val = 10.0 * val + (string[i] - '0');
    }

    if (string[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(string[i]); i++) // Add value after decimal point
    {
        val = 10.0 * val + (string[i] - '0');
        power *= 10.0;
    }
    
    if (string[i] == 'e' || string[i] == 'E')
    {
        i++;
        exponent = 0;
        while (string[i] != '\0')
        {
            exponent = 10 * exponent + (string[i] - '0');
            i++;
        }
    }
    printf("value: %f\n", val);
    printf("power: %f\n", power);
    printf("exponent: %f\n", exponent);
    finalVal = (val / power) * (float)(pow(10, exponent));
    return sign * finalVal;  
} 

void clearStack(void)
{
    sp = 0;
}