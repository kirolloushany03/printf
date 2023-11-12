#include "main.h"

/**
 * get_flags - function to check string flags.
 * @ch: an input char to check.
 * @printF: an input struct to check.
 * Return: 1 if flag found, otherwise 0.
 */
int get_flags(char ch, printF_t *printF)
{
	int i = 0;

	switch (ch)
	{
		case ' ':
			printF->space = 1;
			i++;
			break;

		case '#':
			printF->hash = 1;
			i++;
			break;

		case '+':
			printF->plus = 1;
			i++;
			break;
	}
	return (i);
}
