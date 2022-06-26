#include <stdio.h>
#include <string.h>
#include <math.h>
#define c getchar()

int main()
{
    int decimal, len, val, i, j; // Declaring variables
    char hex[100];

    printf("Enter your hexadecimal string: "); 
    scanf("%s", hex); // Taking input to the character array    

    len = strlen(hex); // Length of the string array
    j = len - 1;
    i = 0;
    val = 0;
    decimal = 0;

    while (i != len)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            val = hex[i] - 48;
            decimal = decimal + val * pow(16, (j));
        }

        else if (hex[i] >= 'a' && hex[i] <= 'f')
        { 
            val = (hex[i] - 97) + 10;
            decimal = decimal + val * pow(16, (j));
        }

        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            val = (hex[i] - 65) + 10;
            decimal = decimal + val * pow(16, (j));
        } 

        i++;
        j--;
    }

    printf("The decimal value is: %d", decimal);

    return 0;
}