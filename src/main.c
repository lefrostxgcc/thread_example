#include <stdio.h>

static void print_message(void *message);

int main()
{
	print_message("First");
}

static void print_message(void *message)
{
	while (1)
		printf("%s\n", (const char *) message);
}
