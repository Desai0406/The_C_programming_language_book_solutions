#include <stdio.h>
#include <limits.h>
int main()
{
    printf("*************************int lengths*********************************\n");
    printf("The length of a signed int is, Max: %d,    Min: %d\n", INT_MAX, INT_MIN);
    printf("The length of an unsigned int is: %u\n", UINT_MAX);
    
    printf("\n*************************char lengths*********************************\n");
    printf("The length of a signed char is, Max: %d,    Min: %d\n", SCHAR_MAX, SCHAR_MIN);
    printf("The length of an unsigned char is: %d\n", UCHAR_MAX);
    
    printf("\n*************************long lengths*********************************\n");
    printf("The length of a long is, Max: %li,   Min: %li\n", LONG_MAX, LONG_MIN);
    printf("The length of an unsigned long is, Max: %lu\n", ULONG_MAX);    

    printf("\n*************************short lengths*********************************\n");
    printf("The length of a signed short is, Max: %hi,  Min: %hi\n", SHRT_MAX, SHRT_MIN);    
    printf("The length of an unsigned short is: %hu\n\n", USHRT_MAX);    
    
    return 0;
}