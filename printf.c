#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            switch (*(ptr + 1))
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += print_str(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(*(ptr + 1));
                    break;
            }
            ptr++;
        }
        else
        {
            count += _putchar(*ptr);
        }
    }

    va_end(args);

    return count;
}

/**
 * _putchar - Custom putchar function
 * @c: Character to be printed
 *
 * Return: 1 (success), EOF (failure)
 */
int _putchar(int c)
{
    return write(1, &c, 1);
}

/**
 * print_str - Custom function to print a string
 * @str: String to be printed
 *
 * Return: Number of characters printed
 */
int print_str(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count += _putchar(*str);
        str++;
    }
    return count;
}

int main(void)
{
    _printf("Hello, %cWorld%c!\n", '(', ')');
    _printf("Name: %s\n", "Alice");
    _printf("Percentage: %%\n");
    _printf("Invalid specifier: %x\n", 42);

    return 0;
}
