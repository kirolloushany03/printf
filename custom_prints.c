#include "main.h"

/**
 * print_num - print numbers.
 * @num: an input number to print.
 * Return: Nothing.
 */
void print_num(int num)
{
	uint32_t n;

	if (num < 0)
	{
		_putchar('-');
		n = -num;
	}
	else
	{
		n = num;
	}
	if (n / 10)
		print_num(n / 10);
	_putchar('0' + (n % 10));
}

/**
 * print_string - print string.
 * @arg: an input argument to print.
 * @print: an input struct.
 * Return: number of characters printed.
 */
int print_string(va_list arg, printF_t *print)
{
	char *str = va_arg(arg, char *);

	(void)print;

	if (!str)
		str = "(null)";

	return (_puts(str));
}

/**
 * print_character - print character.
 * @arg: an input argument to print.
 * @print: an input struct.
 * Return: Always 1 (character printed)
 */
int print_character(va_list arg, printF_t *print)
{
	int ch = va_arg(arg, int);

	(void)print;
	_putchar(ch);
	return (1);
}

/**
 * print_percent - print character.
 * @arg: an input argument to print.
 * @print: an input struct.
 * Return: Always 1 (character printed)
 */
int print_percent(va_list arg, printF_t *print)
{
	(void)arg;
	(void)print;
	return (_putchar('%'));
}

/**
 * print_binary - print in binary code.
 * @arg: an input argument to print.
 * @print: an input struct for flags.
 * Return: number of printed characters.
 */
int print_binary(va_list arg, printF_t *print)
{
	uint32_t value = va_arg(arg, uint32_t);
	int32_t leadingZeroes = 1;
	int32_t i = 31, bit, count = 0;

	if (!value)
	{
		_putchar('0');
		return (1);
	}
	(void)print;
	while (i >= 0)
	{
		bit = (value >> i) & 1;
		if (bit || !leadingZeroes)
		{
			_putchar(bit + '0');
			leadingZeroes = 0;
			count++;
		}
		i--;
	}

	return (count);
}
