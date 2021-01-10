#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    void (*action_func)(struct person*);
    char name[32];
};

void bad_func(void) {
    printf("You shouldn't be here!\n");
}

void print_hello(struct person* p) {
    printf("Hello, %s!\n", p->name);
}

int main(void) {

    struct person* p = malloc(sizeof(struct person));
    if (!p) return -1;

    printf("Enter your name:\n");
    fgets(p->name, 32, stdin);
    p->name[strlen(p->name)-1] = '\x00';

    printf("Select an action:\n");
    printf("1. Print hello message.\n");
    printf("2. Exit\n");
    char c = fgetc(stdin);
    // read endline
    fgetc(stdin);
    switch(c) {
    case '1':
        p->action_func = print_hello;
        break;
    case '2':
        printf("Goodbye!\n");
        return 0;
    default:
        printf("Invalid command\n");
        free(p);
    }

    char* post_action_msg = malloc(40);
    printf("Post action message:\n");
    fgets(post_action_msg, 40, stdin);

    p->action_func(p);
    printf("%s\n", post_action_msg);

    return 0;
}
