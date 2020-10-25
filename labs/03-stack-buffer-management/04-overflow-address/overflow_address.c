#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE	100

static void bad_func(void)
{
	puts("Bad.");
}

static void really_bad_func(void)
{
	int x[42];
	puts("We are doomed.\n");
}

static int get_user_data(void)
{
	static int id = 0;
	unsigned int age = -1;
	char name[NAME_SIZE];

	printf("Name: ");
	fgets(name, 2*NAME_SIZE, stdin);

	printf("Age: ");
	scanf("%u", &age);
	getchar();

	return id++;
}

int main(void)
{
	int id;

	while (1) {
		id = get_user_data();
		if (id < 0)
			break;
		printf("User ID is: %d\n", id);
	}

	exit(EXIT_SUCCESS);
	return 0;
}
