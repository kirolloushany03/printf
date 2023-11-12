#include "main.h"
/**
 * _printf - Custom implementation of the printf function
 * @format: Format string containing format specifiers
 *
 *	This function emulates the behavior of the standard printf function,
 *	supporting various format specifiers. It processes the format string
 *	and corresponding arguments, utilizing a modular design with helper
 *	functions for specific format specifiers.
 *
 *	@format: The format string to be processed.
 *			 - If NULL or an empty string, returns -1.
 *			 - If the format string contains only "%", returns -1.
 *			 - If the format string starts with "% " and has no other characters,
 *			   returns -1.
 *
 *	Return: The number of characters written (excluding the null byte),
 *			or -1 in case of error.
 */
int _printf(const char *format, ...)
{
	int chars = 0;	/* Number of characters written */
	const char *str;	/* Pointer to iterate through the format string */
	int (*p_Func)(va_list, printF_t *);	/* Function pointer for format sh*/
	va_list args;	/* Variable argument list */
	printF_t flags = { 0, 0, 0 };	/* Struct to store format flags */

	va_start(args, format);

	/* Check for format string validity */
	if (!format || (format[0] == '%' && !format[1]) ||
	    (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);

	for (str = format; *str; str++)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				chars += _putchar('%');	/* Print literal '%' character */
				continue;
			}
			while (get_flags(*str, &flags))	/* Retrieve and process format flags */
				str++;

			p_Func = get_prints(*str);	/* Get function pointer for format specifier */
			chars += p_Func ? p_Func(args, &flags) : _printf("%%%c", *str);
		}
		else
			chars += _putchar(*str);	/* Print non-format specifier characters */
	}

	va_end(args);
	_putchar(-1);	/* Signal the end of printing */
	return (chars);
}
