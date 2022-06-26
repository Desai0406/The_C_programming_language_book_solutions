#include <stdio.h>
int main() // Fahr to cel
{
   int f;

   for (int f = 300; f >= 0; f = f - 20) // Using for loop syntax. For(initialization; conditional expression; Increment/decrement expression)
   {
       printf("%3d %7.1f\n", f, ((f - 32) * (5.0/9.0))); // Because here int f is being computed with floating point values, the answer will be available in floating point numbers.
   }                                                   // Floating point answer cannot be represented in an integer format. It will give garbage values. But an integer answer can be represented in floating point format if and only if computed.
    
    return 0;
}
/* Only 1 variable was used*/
/* Here, line 4; the data type coudl be changed to int without affecting the code. 
But once the variable data type is specified in the loop i.e initialized, it cannot be changed while printing or will cause garbage values to br printed. */ 
// COMPUTATIONAL RESULTS WILL ALLOW INTEGER CALCULATIONS TO BE REPRESENTED IN FLOATING POINT.