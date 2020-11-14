#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 0x4

void get_user_input(void)
{
	char buf[BUFFER_SIZE];

	read(STDIN_FILENO, buf, 2*BUFFER_SIZE);
	printf("%s\n", buf);

	read(STDIN_FILENO, buf, 12*BUFFER_SIZE);
}

int main(void)
{
	get_user_input();
	return 0;
}
