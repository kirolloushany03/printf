#include "main.h"

/**
 * print_octal - function that prints octal numbers.
 * @args: an input argument.
 * @printF: input struct of printF_t.
 * Return: number of printed numbers.
*/
int print_octal(va_list args, printF_t *printF)
{
	uint32_t num = va_arg(args, uint32_t);
	int32_t printed_nums = 0, i, j;
	char buffer[HASH_BUFF_SIZE];

	if (!num)
	{
		return (_putchar('0'));
	}

	if (printF->hash == 1)
	{
		printed_nums += _putchar('0');
	}

	i = sizeof(buffer) - 1;

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	for (j = i + 1; j < sizeof(buffer); j++)
	{
		_putchar(buffer[j]);
		printed_nums++;
	}

	return (printed_nums);
}
