#include <stdio.h>

static void print_message(void *message);

int main()
{
}

static void print_message(void *message)
{
	while (1)
		printf("%s\n", (const char *) message);
}
