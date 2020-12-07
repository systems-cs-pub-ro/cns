#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void call_exit() {
	exit(0);
}

void call_1(unsigned param1) {
	if (param1 == 0xdeadc0de) {
		printf("Stage A!\n");
	}
}

void call_2(unsigned param1, unsigned param2) {
	if (param1 == 0xbeefc475 && param2 == 0x10101010) {
		printf("Stage B!\n");
	}
}

void vuln() {
	char buf[128];
	read(STDIN_FILENO, buf, 512);
}

int main(void) {
	vuln();
	return 0;
}
