#include <stdio.h>
#include <stdlib.h>

static void hidden_function(void)
{
	puts("I laugh in the face of danger. Ha ha ha ha!");
}

static void visible_function(void)
{
	puts("Knock, knock! Who's there? Recursion. Recursion who? Knock, knock!");
}

static void helper_function(void)
{
	void (*f_ptr)(void) = visible_function;
	unsigned int dumb_number = 0x12345678;
	char buffer[32];

	printf("Provide buffer input: ");
	fgets(buffer, 64, stdin);

	printf("Dumb number value is 0x%08x.\n", dumb_number);
	printf("Buffer is %s\n", buffer);

	f_ptr();
}

int main(void)
{
	helper_function();

	return 0;
}
