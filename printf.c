#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	char *str;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1), count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				for (; *str; str++, count++)
					write(1, str, 1);
			}
			else
				write(1, format[i] == '%' ? "%" : (char[]){'%', format[i], 0}, format[i] == '%' ? 1 : 2), count += format[i] == '%' ? 1 : 2;
		}
		else
			write(1, &format[i], 1), count++;
		i++;
	}
	va_end(args);
	return (count);
}
