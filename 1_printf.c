#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
* _printf - This function follows a format to produce output
* @format: The format string
* Return: Always 0.
*/
int _printf(const char *format, ...)
{
int d_i;
int buff_len;
char *buff;
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
case 'i':
{
d_i = va_arg(args, int);
buff_len = snprintf(NULL, 0, "%d", d_i);
nc_count += write(1, buff, buff_len);
buff = malloc((buff_len + 1) * sizeof(char));
if (buff == NULL)
{
va_end(args);
return (-1); 
}
sprintf(buff, "%d", d_i);
nc_count+=write(1, buff, buff_len);
free(buff);
break;
}
default:
write(1, "%", 1);
write(1, format, 1);
nc_count+=2;
break;
}
}
else
{
nc_count+=write(1, format, 1);
}
}
va_end(args);
return (nc_count);
}
