#include "main.h"
#include <unistd.h>

/**
 * handle_char - handles %c conversion
 * @args: argument list
 * Return: characters printed
 */
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * handle_string - handles %s conversion
 * @args: argument list
 * Return: characters printed
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * handle_percent - handles %% conversion
 * Return: characters printed
 */
int handle_percent(void)
{
	write(1, "%", 1);
	return (1);
}
