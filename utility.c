#include <ctype.h>

int charToValue(const char ch)
{
    if (isdigit(ch))
        return ch - '0';
    if (isalpha(ch))
        return tolower(ch) - 'a' + 10;
    return 0;
}

char valueToChar(const int value)
{
    if (value < 10)
        return '0' + value;
    return 'a' + (value - 10);
}
