#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>

enum { THREAD_COUNT = 2, STACK_SIZE = 1 << 16 };
static char stack[THREAD_COUNT][STACK_SIZE];

static int print_message(void *message);

int main()
{
	int		flags;

	flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD;

	if (clone(print_message, stack[0] + STACK_SIZE, flags, "First") < 0)
	{
		perror("clone");
		return 1;
	}

	if (clone(print_message, stack[1] + STACK_SIZE, flags, "\tSECOND") < 0)
	{
		perror("clone");
		return 1;
	}

	print_message("\t\tThird");
}

static int print_message(void *message)
{
	while (1)
	{
		printf("%s\n", (const char *) message);
		sleep(1);
	}

	return 0;
}
