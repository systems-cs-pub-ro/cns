CFLAGS= -m32  -fno-stack-protector -mpreferred-stack-boundary=3 -g -no-pie -fno-pic

all: format

# This adds a dependency to Makefile as well
format: format.c Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(@) $(<)

.PHONY: clean
clean:
	-rm -rf format format.o
