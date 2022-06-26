// #include <stdio.h>
// int main()
// {
//     int celsius, fahrenheit, step, upper, lower;
//     lower = 0;
//     upper = 300;
//     step = 20;
//     fahrenheit = 0;


//     while (fahrenheit <= upper)
//     {
//         celsius = ((fahrenheit - 32) * (9/5)); // Here (9/5) will equate to 1, because in C integer division truncates the decimal figure so 1.8 will truncated to 1.
//         printf("%d\t%d\n", fahrenheit, celsius);
//         fahrenheit = fahrenheit + step;
//     }
    
//     return 0;
// }

/******************************************************************************************************************************************************************************************/

#include <stdio.h>
int main() // Function - consists of variables and statements
{
    float celsius;
    float fahrenheit; // Declaration statements
    int step, upper, lower;

    lower = 0; // Assignment statements
    upper = 300;
    step = 20;
    fahrenheit = lower;

    printf("%3s %5s\n", "cel", "Fahr");
    while (fahrenheit <= upper)
    {
        celsius = ((fahrenheit - 32.0) * (5.0/9.0)); 
        printf("%3.0f %4.1f\n", fahrenheit, celsius); // %4.1 represents total width of 4 digits and 1 digit after decimal point.
        fahrenheit = fahrenheit + step;
    }
    
    return 0;
}