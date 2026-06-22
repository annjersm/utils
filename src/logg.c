#include <anders/logg.h>
#include <anders/types.h>
#include <stdio.h>
#include <stdarg.h>

static u8 color;

static void print_success();
static void print_error();
static void print_info();

int logg_error(const char *message, ...)
{
	va_list ap;
	const char *str = message;
	va_start(ap, message);
	while (str != NULL) {
		printf("%s", str);
		str = va_arg(ap, const char *);
	}
	va_end(ap);
}

void logg(int type, const char *message)
{
	if (type == LOGG_ERROR)
		print_error();
	else if (type == LOGG_SUCCESS)
		print_success();
	else
		print_info();
	printf("%s\n", message);
}

void init_logg(int i)
{
	color = (i == LOGG_COLOR) ? true : false;
}

static void print_error()
{
	(color) ? printf("[\033[31m ERROR \033[m]: ") : printf("[ ERROR ]: ");
}

static void print_success()
{
	(color) ? printf("[\033[32mSUCCESS\033[m]: ") : printf("[SUCCESS]: ");
}

static void print_info()
{
	printf("[       ]: ");
}

/*
 * 0x0000 |
 * 0x0001 | u8 color[]
 * 0x0002 | _logg_init: arg1
 * 0x0003 |     cmp arg1 1
 * 0x0004 |     je _set_color
 * 0x0005 |     mov arg1 0x0001
 * 0x0006 | _set_color:
 * 0x0007 |     mov arg1 0x0002
 * 0x0008 | _print_error:
 * 0x0009 | _print_error_color:
 * 0x000a | _print_success:
 * 0x000b | _print_success_color:
 * 0x000c |
 * 0x000d |
 * 0x000e |
 * 0x000f |
 * 0x0010 |
 * 0x0011 |
 * 0x0012 |
 * 0x0013 |
 * 0x0014 |
 * 0x0015 |
 * 0x0016 |
 * 0x0017 |
 * 0x0018 |
 * 0x0019 |
 * 0x001a |
 * 0x001b |
 * 0x001c |
 * 0x001d |
 * 0x001e |
 * 0x001f |
 */
