#include "main.h"

/**
 * _getPrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int _getPrecision(const char *format, int *i, va_list list)
{
	int curr_int = *i + 1;
	int precision = -1;

	if (format[curr_int] != '.')
		return (precision);

	precision = 0;

	for (curr_int += 1; format[curr_int] != '\0'; curr_int++)
	{
		if (_isDigit(format[curr_int]))
		{
			precision *= 10;
			precision += format[curr_int] - '0';
		}
		else if (format[curr_int] == '*')
		{
			curr_int++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_int - 1;

	return (precision);
}
