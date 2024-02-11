#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "division.h"
#include "imag.h"
#include "subtraction.h"

void runCLI()
{
    char x[256] = { 0 }, y[256] = { 0 };
    int base, n;
    char operation;

    printf("[s]ubtraction, [d]division, or [i]mag: ");
    scanf(" %c", &operation);

    if (operation == 'i' || operation == 'I')
    {
        printf("Enter n: ");
        scanf("%d", &n);
        printf("Enter base: ");
        scanf("%d", &base);
        char *imagResult = imag(n, base);
        printf("IMAG Result: %s\n", imagResult);
        free(imagResult);
    }
    else
    {
        printf("Enter first number: ");
        scanf("%s", x);
        printf("Enter second number: ");
        scanf("%s", y);
        printf("Enter base: ");
        scanf("%d", &base);

        char *padded_x = padWithZeros(x, base);
        char *padded_y = padWithZeros(y, base);

        switch (operation)
        {
        case 's':
        case 'S':
        {
            char *result = subtraction(padded_x, padded_y, base);
            printf("Subtraction Result: %s\n", result);
            free(result);
            break;
        }
        case 'd':
        case 'D':
        {
            int rest = -1;
            int result = division(padded_x, padded_y, base, &rest);
            printf("Division Result = %d and Remainder = %d\n", result, rest);
            break;
        }
        default:
            printf("Invalid operation selected.\n");
        }

        free(padded_x);
        free(padded_y);
    }

    while ((getchar()) != '\n')
    {
    }

    printf("Press Enter key to exit...\n");
    getchar();
}
