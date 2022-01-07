#include "palindrome.h"

/**
 * is_palindrome - Checks integer for androgyny
 * @n: unsigned long integer parameter
 * Return: 1 if true 0 if false
 */
int is_palindrome(unsigned long n)
{
    unsigned long int n, u, rem, rev = 0;

    while(u != 0) {
        rem = n % 10;
        rev *= 10 + rem;
        u /= 10;
    }
    if (rev == n) {
        return (1);
    }
    return (0);
}