#include <stdlib.h>
#include "holberton.h"

/**
 * print_error - prints the word error and new line
 * Return: nothing
 */
void print_error(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		_putchar("Error"[i]);
	}
	_putchar('\n');
}

/**
 * return_nb_or_error - checks if correct number and takes out 0 at the start
 * @origin: the supposed number
 * Return: the corrected number (without zeros at the start) or Null if no nb
 */
char *return_nb_or_error(char *origin)
{
	int i;

	if (origin[0] == '\0')
		return (NULL);

	for (i = 0; origin[i] != '\0'; i++)
	{
		if (origin[i] < '0' || origin[i] > '9')
		{
			return (NULL);
		}
	}
	while (origin[0] == '0' && origin[1] != '\0')
	{
		origin++;
	}
	return (origin);
}

/**
 * get_length - gets the length of a string
 * @number: string (containg nb)
 * Return: total nb of 'letters' in the nb
 */
int get_length(char *number)
{
	int i, total = 0;

	for (i = 0; number[i] != '\0'; i++)
	{
		total++;
	}
	return (total);
}

/**
 * calculate - multiplies two positive numbers
 * @num1: number 1
 * @num2: number 2
 * @lenNum1: lenght of number 1
 * @lenNum2: lenght of number 2
 * Return: nothing
 */
void calculate(char *num1, char *num2, int lenNum1, int lenNum2)
{
	int *result;
	int i, j, local, firstNoneZero = 0;

	result = malloc(sizeof(int) * (lenNum1 + lenNum2));

	if (result == NULL)
		exit(98);

	for (i = 0; i < lenNum1 + lenNum2; i++)
		result[i] = 0;

	for (i = lenNum1 - 1; i >= 0; i--)
	{
		for (j = lenNum2 - 1; j >= 0; j--)
		{
			local = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
			result[i + j + 1] = local % 10;
			result[i + j] += local / 10;
		}
	}
	for (i = 0; i < (lenNum1 + lenNum2); i++)
	{
		if (result[i] != 0)
		{
			firstNoneZero = 1;
		}
		if (result[i] != 0 || (result[i] == 0 && firstNoneZero == 1))
		{
			_putchar(result[i] + '0');
		}
	}
	if (firstNoneZero == 0)
		_putchar('0');
	_putchar('\n');
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int lenNum1, lenNum2;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	num1 = return_nb_or_error(num1);
	num2 = return_nb_or_error(num2);

	if (num1 == NULL || num2 == NULL)
	{
		print_error();
		exit(98);
	}

	lenNum1 = get_length(num1);
	lenNum2 = get_length(num2);

	calculate(num1, num2, lenNum1, lenNum2);

	return (0);
}
