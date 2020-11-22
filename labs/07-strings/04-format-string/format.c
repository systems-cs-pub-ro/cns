#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

static int
my_evil_func(void)
{
	fprintf(stderr, "I'm evil, but nobody calls me :-(\n");
	exit(42);
}

int
main(int argc, char *argv[])
{
	printf(argv[1]);
	puts("\nThis is the most useless and insecure program!\n");
	return 0;
}
