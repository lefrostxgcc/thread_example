#include <stdio.h>

static int print_message(void *message);

int main()
{
	print_message("First");
}

static int print_message(void *message)
{
	while (1)
		printf("%s\n", (const char *) message);

	return 0;
}
