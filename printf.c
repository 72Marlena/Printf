#include "main.h"
#include <unistd.h>
#include <string.h>


/**
 * _printf - produces the output according to a format
 * @format: the string
 * Return: the num of chars
 */

int _printf(const char *format, ...)
{
	int chars_printed = 0;

	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chars_printed++;
		}
		else
		{
			if (*format == '%')
			{
				write(1, format, 1);
				chars_printed++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(arg_list, int);
				write(1, &c, 1);
				chars_printed++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(arg_list, char*);
				int i;

				for (str[i] = 0 ; str[i] != '\0' ; i++)
					write(1, str,i);
				chars_printed += i;
			}
			if (*format == '\0')
				break;
		}
		format++;
	}
	va_end(arg_list);

	return (chars_printed);
}
