#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// recv and execute from gbuf
char gbuf[256];

void vuln()
{
    char buf[64];
    read(0, buf, 512);
}

int main(void)
{
    vuln();
    return 0;
}
