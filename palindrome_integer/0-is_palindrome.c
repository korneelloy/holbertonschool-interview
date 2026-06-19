#include <stdlib.h>

/**
 * ipow10 - calculetes power of 10
 *
 * @e: number
 *
 * Return: power of 10
 */

static unsigned long ipow10(int e)
{
	unsigned long r = 1;

	while (e-- > 0)
		r *= 10;
	return (r);
}

/**
 * is_palindrome - checks if unsigned integer is a palindrome
 * No allocation of memory dynamically (malloc, calloc, …)
 *
 * @n: number
 *
 * Return: 1 if palindrome,  0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int lenght = 0;
	unsigned long remainder = n / 10;

	for (lenght = 1; remainder != 0; lenght++)
	{
		remainder = n / ipow10(lenght + 1);
	}
	for (int i = 0; i < lenght / 2; i++)
	{
		if ((n / ipow10(i)) % 10 != (n / ipow10(lenght - 1 - i)) % 10)
		{
			return (0);
		}
	}
	return (1);
}
