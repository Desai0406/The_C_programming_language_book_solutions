// Convert a string of characters to double type - atof
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

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

float atofl(char string[])
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