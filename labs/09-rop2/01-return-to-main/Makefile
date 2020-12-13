all: ret_to_main

ret_to_main: ret_to_main.c
	gcc -no-pie -mpreferred-stack-boundary=3 -fno-stack-protector  -o $@ $<

clean:
	rm -f ret_to_main
