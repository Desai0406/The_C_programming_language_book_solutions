#include <stdio.h>
int main()
{
    int c, ccount, arr[10], words, maxlen, maxwords;
    int overflow = 0;
    ccount = 0;
    maxwords = 15;
    maxlen = 10;
    words = 0;
    for (int i = 0; i < maxlen; i++)
    {
        arr[i] = 0;
    }
    
    printf("Enter your string of words: \n");

    while (words < maxwords)
    {
        while ((c = getchar()) != ' ' && c != '\n' && c != '\t')
        {
            ++ccount;
        }

        if (ccount > maxlen)
        if ('0' < ccount < maxlen)
        {
            ++arr[(ccount)]; 
            ++words; 
            ccount = 0;
        }
        
    }

    for (int i = 0; i < maxlen; i++)
    {
        printf("%d -- > ", i);
        for (int j = 0; j < (arr[i]); j++)
        {
            printf(" *");
        }
        printf("\n");
    }

    return 0;
}