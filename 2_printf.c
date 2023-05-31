#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* _printf - This function follows a format to produce output
* @format: The format string
* Return: Always 0
*/
int _printf(const char *format, ...)
{
{
va_list num;
va_start(num, format);
for (; *format != '\0', format++)
{
if (*format == '%')
{
format++;
if (*format == 'b')
{
unsigned int numeral = va_arg(num, unsigned int);
int binary_arg[32];
int binary_count = 0;
if (numeral == 0)
{
binary_count += write(1, "0", 1);
}
else
{
while (numeral > 0)
{
binary_arg[binary_count] = numeral % 2;
numeral /= 2;
binary_count++;
}
for (int rev_arg = binary_count - 1; rev_arg >= 0; rev_arg--)
{
binary_arg[rev_arg] += '0';
binary_count += write(1, &binary_arg[rev_arg], 1);
}
}
}
}
}
va_end(num);
return (0);
}
