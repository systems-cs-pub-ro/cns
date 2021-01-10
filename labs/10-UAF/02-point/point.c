#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point2D {
    unsigned x;
    unsigned y;
    float (*vector_len)(struct point2D*);
};

struct point3D {
    unsigned x;
    unsigned y;
    unsigned z;
    float (*vector_len)(struct point3D*);
};

void bad_func(void) {
    printf("You shouldn't be here!\n");
}

float vector2d_len_func(struct point2D* p) {
    return sqrt(p->x * p->x + p->y * p->y);
}

float vector3d_len_func(struct point3D* p) {
    return sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
}

int point2D_init(struct point2D** p, unsigned x, unsigned y)
{
    if (!p) return -1;
    *p = malloc(sizeof(struct point2D));
    printf("malloc address = %p\n", *p);
    if (!*p) return -1;
    memset(*p, 0, sizeof(struct point2D));

    (*p)->x = x;
    (*p)->y = y;

    (*p)->vector_len = vector2d_len_func;

    return 0;
}

int point3D_init(struct point3D** p, unsigned x, unsigned y, unsigned z)
{
    if (!p) return -1;
    *p = malloc(sizeof(struct point3D));
    printf("malloc address = %p\n", *p);
    if (!*p) return -1;
    memset(*p, 0, sizeof(struct point3D));

    (*p)->x = x;
    (*p)->y = y;
    (*p)->z = z;

    (*p)->vector_len = vector3d_len_func;

    return 0;
}

int read_id(void)
{
    printf("Insert point ID:");
    int id = fgetc(stdin) - '0';
    // skip newline
    fgetc(stdin);

    return id;
}

void print_commands(void)
{
    printf("Select command:\n");
    printf("1. Create 2d point\n");
    printf("2. Delete 2d point\n");
    printf("3. Compute 2d vector length\n");
    printf("\n");
    printf("4. Create 3d point\n");
    printf("5. Delete 3d point\n");
    printf("6. Compute 3d vector length\n");
    printf("\n");
    printf("7. Exit\n");
}

int main(void)
{
    int err = 0;

    printf("sizeof(struct point2D) = %ld\n", sizeof(struct point2D));
    printf("sizeof(struct point3D) = %ld\n", sizeof(struct point3D));

    struct point2D* point_list_2d[256];
    struct point3D* point_list_3d[256];

    int id = 0;
    unsigned x, y, z;

    while (1) {
        print_commands();
        int cmd = fgetc(stdin);
        // skip newline
        fgetc(stdin);
        switch (cmd) {
        case '1':
            printf("Insert x, y coordinates:");
            scanf("%d %d", &x, &y);
            // skip newline
            fgetc(stdin);

            id = read_id();
            err = point2D_init(&point_list_2d[id], x, y);
            break;
        case '2':
            id = read_id();
            free(point_list_2d[id]);
            break;
        case '3':
            id = read_id();
            printf("len = %f\n",
                point_list_2d[id]->vector_len(point_list_2d[id]));
            break;

        case '4':
            printf("Insert x, y, z coordinates:");
            scanf("%d %d %d", &x, &y, &z);
            // skip newline
            fgetc(stdin);

            id = read_id();
            err = point3D_init(&point_list_3d[id], x, y, z);
            break;
        case '5':
            id = read_id();
            free(point_list_3d[id]);
            break;
        case '6':
            id = read_id();
            printf("len = %f\n",
                point_list_3d[id]->vector_len(point_list_3d[id]));
            break;

        case '7':
            goto _exit;
        }
    }

_exit:
    // print timestamp
    system("date");
    return err;
}
