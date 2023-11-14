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

	if (print->space == 1 && !print->plus && !print->hash && num >= 0)
		digit += _putchar(' ');
	if (print->plus == 1 && num >= 0)
		digit += _putchar('+');
	if (num <= 0)
		digit++;

	print_num(num);
	return (digit);
}

/**
 * print_unsigned - function that prints unsigned integers.
 * @arg: an input argument.
 * @print: input struct of printF_t.
 * Return: number of printed numbers.
 */
int print_unsigned(va_list arg, printF_t *print)
{
	uint64_t num = va_arg(arg, uint64_t);
	uint32_t num_chars = 0;
	char buffer[20];
	int32_t index = 19;

	if (num == 0)
	{
		_putchar('0');
		num_chars++;
		return (num_chars);
	}

	buffer[19] = '\0';

	while (num > 0)
	{
		buffer[--index] = (num % 10) + '0';
		num /= 10;
		num_chars++;
	}

	while (buffer[index] != '\0')
	{
		_putchar(buffer[index]);
		num_chars++;
		index++;
	}
	return (num_chars);
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

/**
 * print_hex - function that prints hex value of numbers in lower case.
 * @args: an input argument.
 * @printF: input struct of printF_t.
 * Return: number of printed chars.
 */
int print_hex(va_list args, printF_t *printF)
{
	int32_t i = HASH_BUFF_SIZE - 2;
	uint64_t num = va_arg(args, uint64_t);
	char buffer[HASH_BUFF_SIZE];
	int32_t printed_chars = 0;

	if (num == 0)
		buffer[i--] = '0';

	(void)printF;
	buffer[HASH_BUFF_SIZE - 1] = '\0';
	if (printF->hash == 1)
	{
		printed_chars += _putchar('0');
		_putchar('x');
	}
	while (num > 0)
	{
		buffer[i--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}

	i++;

	while (buffer[i] != '\0')
	{
		_putchar(buffer[i]);
		i++;
		printed_chars++;
	}

	return (printed_chars);
}

/**
 * print_hex_upper - function that prints hex value of numbers in upper case.
 * @args: an input argument.
 * @printF: input struct of printF_t.
 * Return: number of printed chars.
 */
int print_hex_upper(va_list args, printF_t *printF)
{
	int32_t i = HASH_BUFF_SIZE - 2;
	uint64_t num = va_arg(args, uint64_t);
	char buffer[HASH_BUFF_SIZE];
	int32_t printed_chars = 0;

	if (!num)
		buffer[i--] = '0';

	(void)printF;
	buffer[HASH_BUFF_SIZE - 1] = '\0';
	if (printF->hash == 1)
	{
		printed_chars += _putchar('0');
		_putchar('X');
	}
	while (num > 0)
	{
		buffer[i--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}

	i++;

	while (buffer[i] != '\0')
	{
		_putchar(buffer[i]);
		i++;
		printed_chars++;
	}

	return (printed_chars);
}
