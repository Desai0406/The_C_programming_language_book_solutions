#include <stdio.h>

int to_lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c;
}

int main()
{
    char chr;
    int x;

    printf("Enter your letter: ");
    scanf("%c", &chr);

    x = to_lower(chr); // Implicit typecasting from char to int

    printf("%c", x); // Implicit typecast from int to char
    return 0;
}