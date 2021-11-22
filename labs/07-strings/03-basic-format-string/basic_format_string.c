#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned int v = 10;

int main(void)
{
	char buffer[16];
	char fmt_buffer[256];

	setvbuf(stdout, NULL, _IONBF, 0);
	
	fgets(buffer, 16, stdin);
	fgets(fmt_buffer, 256, stdin);
	printf(fmt_buffer, buffer);

	if (v == 0x300)
		system("/bin/bash");

	return 0;
}
