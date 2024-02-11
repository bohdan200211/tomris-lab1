#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subtraction.h"
#include "utility.h"

char *subtraction(const char *x, const char *y, const int base)
{
    const int len = strlen(x);
    char *result = (char *)malloc((len + 2) * sizeof(char));
    if (!result)
        return NULL;

    result[len + 1] = '\0';
    int carry = 0;

    for (int i = len; i > 0; i--)
    {
        int sub = charToValue(x[i - 1]) - charToValue(y[i - 1]) + carry;
        carry = (sub < 0) ? -1 : 0;
        if (sub == -1)
        {
            sub = base - 1;
        }

        result[i] = (sub % base < 10) ? (sub % base + '0') : (sub % base - 10 + 'a');
    }
    result[0] = (carry < 10) ? (carry + '0') : (carry - 10 + 'a');

    int firstNonZero = 0;
    while (result[firstNonZero] == '0' && firstNonZero < len)
    {
        firstNonZero++;
    }
    if (firstNonZero == len + 1)
    {
        char *zero = (char *)malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        free(result);
        return zero;
    }

    char *finalResult = strdup(result + firstNonZero);
    free(result);
    return finalResult;
}

char *padWithZeros(const char *number, const int maxLength)
{
    const int length = strlen(number);
    const int numZeros = maxLength - length;
    char *paddedNumber = (char *)malloc((maxLength + 1) * sizeof(char));
    if (!paddedNumber)
        return NULL;

    memset(paddedNumber, '0', numZeros);
    strcpy(paddedNumber + numZeros, number);
    return paddedNumber;
}
