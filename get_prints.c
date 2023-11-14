#include "main.h"
/**
 * get_prints - Returns the corresponding function for a format specifier
 * @str: Format specifier character
 *
 * This function takes a format specifier character and returns the
 * corresponding function for printing based on the specifier.
 *
 * @str: The format specifier character to be matched.
 *
 * Return: Function pointer to the corresponding print function,
 *         or NULL if no match is found.
 */
int (*get_prints(char str))(va_list, printF_t *)
{
	printH_t funcs[] = {
		{'s', print_string},
		{'c', print_character},
		{'d', print_integer},
		{'i', print_integer},
		{'b', print_binary},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_upper},
		{'o', print_octal},
		{'%', print_percent}
	};

	int flags = sizeof(funcs) / sizeof(funcs[0]);
	int i;

	for (i = 0; i < flags; i++)
	{
		if (funcs[i].ch == str)
		{
			return (funcs[i].ptr);
		}
	}

	return (NULL);
}
