#include <stdio.h>

int unused_data __attribute__ ((section (".data")));

int
main(void)
{
	extern int _binary___mycode_bin_start;
	void (*func)(void) = (void (*)(void))&_binary___mycode_bin_start;

	++unused_data;
	printf("%d\n", unused_data);

	func();
}
