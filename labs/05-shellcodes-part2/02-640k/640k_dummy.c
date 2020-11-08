#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char buf[16];
	char digits[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};
	int index;
	int option;

	printf("640k is enough for anyone!\n");
	while (1) {
		printf("Give option: \n");
		printf("1. Read digit.\n");
		printf("2. Write a message.\n");
		printf("3. Exit.\n");
		scanf("%d", &option);
		switch (option) {
			case 1:
				printf("Give index: ");
				scanf("%d", &index);
				printf("index: %d addr: %p value: %c\n", index, &digits[index], digits[index]);
				break;
			case 2:
				read(0, buf, 32);
				break;
			case 3:
				goto leave;
				break;
			default:
				printf("Unknown option!\n");
				break;
		}
	}
leave:
	return 0;
}
