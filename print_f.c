#include "main.h"
/**
 * _printf - prints the format string
 * and handles the conversion specifiers
 * c, s, %
 * @format: the pointer to the format string
 * Return: the number of characters printed,
 * excluding the null byte
 */
int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	while (*format) /*a loop that iterates through the characters*/
	{
		if (*format != '%')/*if format is not % sign*/
		{
			write(1, format, 1);/*writes char to std output*/
			chara_print++;
		}
		else /*if the format is the % sign*/
		{
			format++; /*skip '%' to check next char*/
			if (*format == '\0')
				break;
			if (*format == '%') /*this solves %%*/
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list, int);

				write(1, &c, 1);
				chara_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				chara_print += str_len;
			}
		}
		format++;
	}
	va_end(list);
	return (chara_print);
}
