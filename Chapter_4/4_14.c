// Swap function defined in a block structure as a macro substitution 
#include <stdio.h>
#define swap(t, x, y) {t var1; \
                       var1 = x; \
                       x = y; \
                       y = var1; \
                      }
int main()
{
    int a = 5;
    int b = 3;
    swap(int, a, b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}