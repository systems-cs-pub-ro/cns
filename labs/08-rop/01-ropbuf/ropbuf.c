#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vuln(char *input)
{
	char buf[128];
	strcpy(buf, input);
}

int main(int argc, char **argv)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	if (argc > 1)
		vuln(argv[1]);
	return 0;
}
