#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void my_main(void)
{
	char buf[32];
	char my_string[128];

	memset(buf, 0, 32 * sizeof *buf);
	read(0, buf, 32);
	strcpy(my_string, buf);

	puts(my_string);
}

int main(void)
{
	my_main();
	return 0;
}
