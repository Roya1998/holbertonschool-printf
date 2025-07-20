#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: number of characters written
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - prints formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, count = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                    count += _putchar(*s++);
            }
            else if (format[i] == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}
