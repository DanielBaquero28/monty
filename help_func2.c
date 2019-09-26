#include "monty.h"

/**
 * change_to_str - Converts an integer into a sting with it's
 * corresponding buffer size.
 * @number: Number to be converted to a string.
 * Return: Number converted to a string.
**/

char *change_to_str(int number)
{
	long num_v = 0;
	unsigned int help_number;
	int number_len = 0;
	char *string_int;

	help_number = abs(number);
	number_len = length_number(help_number, 10);

	if (number < 0 || num_v < 0)
		number_len++;
	string_int = malloc(number_len + 1); /* '\0' character */
	if (string_int == NULL)
		return (NULL);

	string_buff(help_number, 10, string_int, number_len);
	if (number < 0 || num_v < 0)
		string_int[0] = '-';

	return (string_int);
}

/**
 * length_number - Finds the length for the number.
 * @number: Number from which we will found the length of.
 * @help: Number used to divide the number and reduce it's length by one.
 * Return: Length of the number.
**/

int length_number(unsigned int number, unsigned int help)
{
	int len;

	len = 1;
	while (number > help - 1)
	{
		len++;
		number /= help;
	}

	return (len);
}

/**
 * string_buff - Stuffs in each digit into a string with '\0'
 * and if negative '-' included.
 * @num: Number to be converted into a string.
 * @help: Number used to divide the number and reduce it's length by one.
 * @str: Where the number converted into a string will be stored
 * one by one.
 * @len: Size of the buffer.
 * Return: Nothing.
**/

void string_buff(unsigned int num, unsigned int help, char *str, int len)
{
	int mod;
	int i = len - 1;

	str[len] = '\0';
	while (i >= 0)
	{
		mod = num % help;
		if (mod > 9)
			str[i] = mod + 87;
		else
			str[i] = mod + '0';
		num /= help;
		i--;
	}
}
