// Convert a string of characters to double type - atof
#include <ctype.h>
#include <stdio.h>
int main()
{
    float answer;
    float atofl(char string1[]);
    char stringmain[] = "324.58";
    answer = atofl(stringmain);
    printf("%f\n", answer);
    return 0;
}

float atofl(char string[])
{
    int i, sign;
    float val, power;

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
    return sign * (val / power);  
} 