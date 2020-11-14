#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 0x4

void get_user_input(void)
{
	char buf[BUFFER_SIZE];
	read(STDIN_FILENO, buf, 8*BUFFER_SIZE);
}

int main(void)
{
	get_user_input();
	return 0;
}
