#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

static void my_evil_func(void)
{
	puts("I'm evil, but nobody calls me :-(\n");
	exit(42);
}

static void my_memory_write(void)
{
	intptr_t *ptr, val;
	ssize_t b;

	b = read(0, &ptr, sizeof ptr);
	if (b != sizeof ptr)
		exit(-1);
	b = read(0, &val, sizeof val);
	if (b != sizeof val)
		exit(-1);

	*ptr = val;
}

#define NAME_SZ 32

static void read_name(char *name)
{
	memset(name, 0, NAME_SZ);
	read(0, name, NAME_SZ);
	//name[NAME_SZ-1] = 0;
}

static void my_main(void)
{
	char name[NAME_SZ];

	read_name(name);
	printf("hello %s, what address to modify and with what value?\n", name);
	fflush(stdout);
	my_memory_write();
	printf("Returning from main!\n");
}

int main(void)
{
	my_main();
	printf("Done!\n");
}
