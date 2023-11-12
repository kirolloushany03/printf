#include "main.h"

/**
 * _putchar - writes the character
 * @c: an input char to print
 * Descroption: custom putchar that creates temporary buffer
 * when i equals to buffer, ch equals to -1 it's time to flush buffer
 * else, store character in the buffer.
 * Return: Always 1 (Character count)
 */
int _putchar(char ch)
{
	static char buf[BUFF_SIZE];
	static int32_t i;

	if (ch == -1 || i >= BUFF_SIZE)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (ch != -1)
	{
		buf[i] = ch;
		i++;
	}
	return (1);
}

/**
 * _puts - writes string.
 * @str: an input string to print
 * Return: number of characters printed.
*/
int _puts(char* str)
{
	register int32_t i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _strlen - returns the length of a string.
 * @str: an input string.
 * Return: length of a string.
 */
int _strlen(char* str)
{
	int32_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
