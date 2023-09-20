#include "main.h"

void _printBuffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_printed = 0;
	int flags, width, precision, size, buffId = 0;
	va_list list;
	char my_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_buffer[buffId++] = format[i];
			if (buffId == BUFF_SIZE)
				_printBuffer(my_buffer, &buffId);
			/* write(1, &format[i], 1);*/
			chars_printed++;
		}
		else
		{
			_printBuffer(my_buffer, &buffId);
			flags = _getFlags(format, &i);
			width = _getWidth(format, &i, list);
			precision = _getPrecision(format, &i, list);
			size = _getSize(format, &i);
			++i;
			printed = _handlePrint(format, &i, list, my_buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}

	_printBuffer(my_buffer, &buffId);

	va_end(list);

	return (chars_printed);
}

/**
 * _printBuffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void _printBuffer(char buffer[], int *buffId)
{
	if (*buffId > 0)
		write(1, &buffer[0], *buffId);

	*buffId = 0;
}
