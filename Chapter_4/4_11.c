// Extend the given problem calculator by adding ungets(s).

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
void ungets(char string[]);
void push(double);
double pop(void);
double atof(char string[]);
double val[MAXVAL];
char buf[BUFSIZE];

int main()
{
    int type, i, var = 0;
    double sub_op2, mod_op2, op1, op2, v, variable[26];
    char s[MAXOP]; // Initialize array here

    for (i = 0; i < 26; i++)
    {
        variable[i] = 0.0;
    }

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
        case 'i': // intergchange (swap)
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case 's': // Sin function
            op2 = pop();
            push(sin(op2));
            break;
        case 'e': // Operand to the power of 'e'
            op2 = pop();
            push(exp(op1));
            break;
        case 'p':
            op2 = pop();
            op1 = pop();
            push(pow(op1, op2));
            break;
        case '=':
            var = pop();
            if (var >= 'A' && var <= 'Z')
            {
                variable[var - 'A'] = pop();
            }
            else
            {
                printf("Error!");
            }
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
            {
                push(variable[type - 'A']);
            }
            else if (type == 'v')
            {
                push(v);
            }
            else
            {
                printf("Unknown command");
            }
            break;
        }
        var = type;
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
    static int lastc = 0;

    if (lastc == 0)
    {
        c = getch();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    
    while ((s[0] = c) == ' ' || c == '\t')
    {
        c = getch();
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    i = 0;
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
                lastc = c;
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
        lastc = c;
    }

    return NUMBER;
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

void ungets(char string[])
{
    int len = strlen(string);
    void ungetch(int);

    while (len > 0)
    {
        ungetch(string[--len]);
    }
}
