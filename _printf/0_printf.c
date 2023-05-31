#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* handleChar -Handles the "%c" conversion specifier
* @nc_count: Pointer to the count variable
* @args: The va_list variable contains the arguments
* Return: None
*/

void handleChar(va_list args, int *nc_count)
{
char prs_char = va_arg(args, int);
write(1, &prs_char, 1);
(*nc_count)++;
}

/**
* handlestr -Handles the "s" conversion specifier
* @nc_count: Pointer to the count variable
* @args: The va_list variable contains the arguments
* Return: None
*/

void handlestr(va_list args, int *nc_count)
{
const char *prs_str = va_arg(args, const char *);
int len = 0;
while (prs_str[len] != '\0')
{
len++;
(*nc_count)++;
}
write(1, prs_str, len);
}

/**
* handleperc -Handles the "%" conversion specifier
* @nc_count: Pointer to the count variable
* Return: None
*/

void handleperc(int *nc_count)
{
write(1, "%", 1);
(*nc_count)++;
}

/**
* _printf - This function follows a format to produce output
* @format: The format string
* Return: Number of characters printed
*/

int _printf(const char *format, ...)
{
int nc_count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
handleChar(args, &nc_count);
break;
case 's':
handlestr(args, &nc_count);
break;
case '%':
handleperc(&nc_count);
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
write(1, format, 1);
nc_count++;
}
format++;
}
va_end(args);
return (nc_count);
}
