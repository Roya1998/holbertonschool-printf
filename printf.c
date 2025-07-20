#include <stdarg.h>
#include <unistd.h>

/* Helper function to print a character */
int print_char(char c)
{
    return write(1, &c, 1);
}

/* Helper function to print a string */
int print_string(const char *str)
{
    int i = 0;

    if (!str)
        str = "(null)";

    while (str[i])
    {
        print_char(str[i]);
        i++;
    }
    return i;
}

/* Helper function to print an integer */
int print_integer(int n)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += print_char('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        count += print_integer(num / 10);

    count += print_char((num % 10) + '0');

    return count;
}

/* The main _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                count += print_char(va_arg(args, int));
            else if (format[i] == 's')
                count += print_string(va_arg(args, char *));
            else if (format[i] == '%')
                count += print_char('%');
            else if (format[i] == 'd' || format[i] == 'i')
                count += print_integer(va_arg(args, int));
            else
                count += print_char('%'), count += print_char(format[i]);
        }
        else
        {
            count += print_char(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}
