#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
/**
* _print_integer - This function follows a format to produce output
* @format: The format string
* Return: Always 0.
*/
int _print_integer(int num)
{
int d_i;
int buff_len;
char buff[12];
int nc_count = 0;
va_list args;
va_start(args, format);

for (; *format != '\0'; format++)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'd':
case ‘I’:
d_i = va_arg(args, int);
buff_len = sprintf(buff, "%d", d_i);
nc_count += write(1, buff, buff_len);
break;
default:
write(1, "%", 1);
write(1, format, 1);
nc_count += 2;
break;
}
}
else
{
nc_count += write(1, format, 1);
}
}
va_end(args);
return (0);
}
