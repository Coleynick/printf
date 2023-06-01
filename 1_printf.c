#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
* handleInt - Handles the 'd' and 'i' conversion specifiers
* @args: The va_list variable contains the arguments
* @nc_count: Pointer to the count variable
* Return: None
*/
void handleInt(va_list args, int *nc_count)
{
int d_i = va_arg(args, int);
char *buff;
int buff_len;

buff_len = snprintf(NULL, 0, "%d", d_i);
buff = malloc((buff_len + 1) * sizeof(char));
if (buff == NULL)
{
va_end(args);
return (-1);
}
sprintf(buff, "%d", d_i);
nc_count += write(1, buff, buff_len);
free(buff);
break;
}

/**
* _printf - This function follows a format to produce output
* @format: The format string
* Return: count
*/
int _printf(const char *format, ...)
{
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
handleInt(args, &nc_count);
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
return (nc_count);
}

