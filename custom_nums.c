#include "main.h"

/**
 * print_integer - function that counts and print integers.
 * @arg: an input argument.
 * @print: input struct of printF_t.
 * Return: number of digits.
 */
int print_integer(va_list arg, printF_t *print)
{
	int32_t num = va_arg(arg, int);
	int32_t digit = count_nums(num);

	if (print->space == 1 && print->plus == 0 && num >= 0)
		digit += _putchar(' ');
	if (print->plus == 1 && num >= 0)
		digit += _putchar('+');
	if (num <= 0)
		digit++;

	print_num(num);
	return (digit);
}

/**
 * count_nums - count numbers digits.
 * @num: an input integer
 * Return: number of digits.
 */
int count_nums(int num)
{
	uint32_t digit = 0;
	uint32_t un;

	if (num < 0)
	{
		un = num * -1;
	}
	else
	{
		un = num;
	}
	while (un != 0)
	{
		un /= 10;
		digit++;
	}
	return (digit);
}
