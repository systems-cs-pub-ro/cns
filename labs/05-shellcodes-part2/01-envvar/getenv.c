#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
        {
            printf("Usage: %s env_var_name\n", argv[0]);
            exit(-1);
        }

    printf("Env var addr %p\n", getenv(argv[1]));

    return 0;
}
