#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buf[16];
	size_t i;
	int ptr_hex_digits;
	int n_chars_hex, n_chars_ptr;

	/* Simple printing. */
	printf("1. Hello\n");

	/* Do proper initialization on buf. Use NUL as string terminator. */
	for (i = 0; i < sizeof(buf)-1; i++)
		buf[i] = 'a';
	buf[sizeof(buf)-1] = '\0';

	/* Print buf using string conversion specifier (%s).
	 * Use # to guard start and end of buffer. */
	printf("2. Buffer is: #%s#\n", buf);

	/* Do not NUL-terminate buf. Will result in leaks. */
	for (i = 0; i < sizeof(buf); i++)
		buf[i] = 'a';

	/* Print buf using string conversion specifier (%s).
	 * Use # to guard start and end of buffer.
	 * Will result in a leak. */
	printf("3. Buffer is: #%s#\n", buf);

	/* Print data using hexadecimal conversion specifier (%x). */
	printf("4. 0x%08x 0x%08x 0x%08x 0x%08x\n", (1<<16) - 1, 1<<16, (1<<24) - 1, 1<<24);

	/* Print address using pointer conversion specifier. */
	printf("5. buf address is %p\n", buf);

	/* Print address in hexadecimal size depending on pointer size. */
	ptr_hex_digits = 2 * sizeof(char *);
	printf("6. buf address is 0x%0*lx\n", ptr_hex_digits, (unsigned long) buf);

	/* Be precise saying which argument holds the print format size and
	 * which argument is the actual buffer */
	printf("7. buf address is 0x%2$0*1$lx\n", ptr_hex_digits, (unsigned long) buf);
	printf("7'. buf address: 0x%1$lx, %1$p, 0x%1$016lx\n", (unsigned long) buf);

	/* Write in a given variable the number of characters written so far. */
	printf("8. 0x%08x 0x%08x 0x%08x 0x%08x\n%n", (1<<16) - 1, 1<<16, (1<<24) - 1, 1<<24, &n_chars_hex);
	printf("9. number of printed chars is: %d\n", n_chars_hex);

	printf("10. buf address is 0x%0*lx\n%n", ptr_hex_digits,
			(unsigned long) buf, &n_chars_ptr);
	printf("11. number of printed chars is: %d\n", n_chars_ptr);

	return 0;
}
