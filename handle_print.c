#include "main.h"
/**
 * _handlePrint - Prints an argument based on its type
 * @format: Formatted string to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int _handlePrint(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', _printChar}, {'s', _printString}, {'%', _printPercent},
		{'i', _printInt}, {'d', _printInt}, {'b', _printBinary},
		{'u', _printUnsigned}, {'o', _printOctal}, {'x', _printHexadecimal},
		{'X', _printHexUpper}, {'p', _printPointer}, {'S', _printNonPrintable},
		{'r', _printReverse}, {'R', _printRot13String}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (format[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].func(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
