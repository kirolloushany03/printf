#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/* Buffer size */
#define BUFF_SIZE 1024
#define HASH_BUFF_SIZE 21
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long int uint64_t;

/**
 * struct printFlags - Struct that contains flag
 *s when a specifier is passed to _printf()
 * @plus: Flag for '+' specifier
 * @space: Flag for ' ' specifier
 * @hash: Flag for '#' specifier
 */
typedef struct printFlags
{
	int plus;
	int space;
	int hash;
} printF_t;

/**
 * struct printHandler - Struct to choose the
 * right function depending on the format specifier
 * passed to _printf()
 * @ch: Format specifier
 * @ptr: Pointer to the correct printing function
 */
typedef struct printHandler
{
	char ch;
	int (*ptr)(va_list pr, printF_t *printF);
} printH_t;

int _printf(const char *format, ...);

int print_integer(va_list arg, printF_t *print);
int print_string(va_list arg, printF_t *print);
int print_character(va_list arg, printF_t *print);
int print_unsigned(va_list arg, printF_t *print);
int print_binary(va_list arg, printF_t *print);
int print_percent(va_list arg, printF_t *print);
int print_hex(va_list arg, printF_t *print);
int print_hex_upper(va_list arg, printF_t *print);
int print_octal(va_list arg, printF_t *print);

int (*get_prints(char str))(va_list, printF_t*);
int get_flags(char ch, printF_t *printF);
void print_num(int num);

int _putchar(char c);
int _puts(char *str);
int _strlen(char *str);
int count_nums(int num);

#endif /* __MAIN_H__ */
