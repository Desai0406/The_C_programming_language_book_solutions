#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main()
{
    // invert (x, p, n);
    return 0;
}