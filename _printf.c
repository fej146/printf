#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: placeholders and identifiers passed
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	change p[] = {
		{"%s", print_s}, {"%c", print_c},
		{"%%", print_37},
		{"%i", print_i}, {"%d", print_d}, {"%r", print_revs},
		{"%R", print_rot13}, {"%b", print_bin},
		{"%u", print_unsigned},
		{"%o", print_oct}, {"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_exc_string}, {"%p", print_pointer}
	};

	va_list args;
	int i = 0;
	int j;
	int length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	for (i = 0; format[i] != '\0'; i++)
	{
		for (j = 13; j >= 0; j--)
		{
			if (p[j].ph[0] == format[i] && p[j].ph[1] == format[i + 1])
			{
				length += p[j].function(args);
				i = i + 2;
				goto Here;
			}
		}
		_putchar(format[i]);
		length++;
	}
	va_end(args);
	return (length);
}
