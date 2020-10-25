#include <stdio.h>

#define MAX_SIZE	63

typedef unsigned long(*op_t)(unsigned long*, int);

static unsigned long xor(unsigned long *input, int n)
{
	int i;

	unsigned long result = (unsigned long)-1;
	for (i = 0; i < n; i++) {
		result ^= input[i];
	}

	return result;
}

static unsigned long and(unsigned long *input, int n)
{
	int i;

	unsigned long result = (unsigned long)-1;
	for (i = 0; i < n; i++) {
		result &= input[i];
	}

	return result;
}

static void bad_func(unsigned long *input, int n)
{
	if (xor(input, n) == 1337) {
		printf("Very bad.\n");
	} else {
		printf("Bad.\n");
	}
}

static void choose_op(char op, op_t *f)
{
	switch (op) {
	case '1':
		*f = xor;
		break;
	case '2':
		*f = and;
		break;
	default:
		*f = NULL;
	}
}

int main(void)
{
	int i, r;
	char op;
	op_t opfunc;
	unsigned long input[MAX_SIZE];

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Choose operation (1/2): ");
	op = fgetc(stdin);
	if (op != '1' && op != '2') {
		printf("Invalid choice (%c)!\n", op);
		return 1;
	}
	choose_op(op, &opfunc);

	printf("Enter %d integers: ", MAX_SIZE);
	i = 0, r = 1;
	while (r != 0 && r != EOF && i <= MAX_SIZE) {
		r = scanf("%lu\n", &(input[i++]));
	}

	printf("Result: 0x%lx\n", opfunc(input, MAX_SIZE));

	return 0;
}
