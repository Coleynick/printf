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
	putchar(prs_char);
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
	while (*prs_str != '\0')
	{
		putchar(*prs_str);
		(*nc_count)++;
		prs_str++;
	}
}

/**
 * handleperc -Handles the "%" conversion specifier
 * @nc_count: Pointer to the count variable
 * Return: None
 */

void handleperc(int *nc_count)
{
	putchar('%');
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
			putchar('%');
			putchar(*format);
			nc_count += 2;
			break;
	}
	}
	else
	{
		putchar(*format);
		nc_count++;
	}
	format++;
	}
	va_end(args);
	return (nc_count);
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	_printf("Hi, %s! Your nickname is %c%d%%.\n", "Nick", 'N', 23);
	return (0);
}
