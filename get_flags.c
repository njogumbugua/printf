#include "main.h"

/**
 * _getFlags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int _getFlags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char CHAR_FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FLAGS[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; CHAR_FLAGS[j] != '\0'; j++)
			if (format[curr_i] == CHAR_FLAGS[j])
			{
				flags |= ARR_FLAGS[j];
				break;
			}

		if (CHAR_FLAGS[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
