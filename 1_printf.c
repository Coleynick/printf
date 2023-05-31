#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
/**
* _printf - This function follows a format to produce output
* @format: The format string
* Return: Always 0.
*/
int _printf(const char *format, ...)
{
int d;
int i;

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
d = va_arg(args, int);
write(1, &d, sizeof(int));
break;
case 'i':
i = va_arg(args, int);
write(1, &i, sizeof(int));
break;
default:
write(1, "%", 1);
write(1, format, 1);
break;
}
}
else
{
write(1, format, 1);
}
}
va_end(args);
return (0);
}

