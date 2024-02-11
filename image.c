#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

char *imag(const int n, const int c)
{
    char *result = (char *)malloc(65);
    if (!result)
        return NULL;

    int i = 0;
    int x = n;
    int q = x / c;
    result[i++] = valueToChar(x - q * c);

    while (q > 0)
    {
        x = q;
        q = x / c;
        result[i++] = valueToChar(x - q * c);
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++)
    {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}
