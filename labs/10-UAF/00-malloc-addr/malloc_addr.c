#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define KB (1024)
#define MB (KB * KB)
#define PAGE_SIZE (4 * KB)
#define BIG_SIZE (32 * MB)

void malloc_check(int start, int end, int jump)
{
    int sizes[128] = {0};
    int int_sizes[128] = {0};
    void* addrs[128] = {0};
    int count[128] = {0};

    int idx = -1;
    void* prevAddr = NULL;
    for (int i = start; i < end; i += jump) {
        void* ptr = malloc(i);

        if (ptr != prevAddr) {
            idx++;
            prevAddr = ptr;
        }

        // 8 bytes for the chunck header
        sizes[idx] = i;
        int_sizes[idx] = ((unsigned long*)ptr)[-1];
        addrs[idx] = ptr;
        count[idx]++;
        free(ptr);
    }

    const char* suffix = NULL;
    printf("Range [%d, %d] with jump of %d:\n", start, end-1, jump);
    for (int i = 0; i <= idx; i++) {
        int prev_inuse = int_sizes[i] & 1;
        int is_mmaped = (int_sizes[i] >> 1) & 1;
        int non_main_arena = (int_sizes[i] >> 2) & 1;

        int_sizes[i] &= ~7;

        if (sizes[i] > MB) {
            sizes[i] = sizes[i] / MB;
            int_sizes[i] = int_sizes[i] / MB;
            suffix = "MB";
        } else if (sizes[i] > KB) {
            sizes[i] = sizes[i] / KB;
            int_sizes[i] = int_sizes[i] / KB;
            suffix = "KB";
        } else {
            suffix = "B";
        }
        printf("Addr: %p; Size: %d %s; Internal size: %d %s; Count = %d\n",
                addrs[i], sizes[i], suffix, int_sizes[i], suffix, count[i]);
        printf("prev_inuse = %d; is_mmaped = %d; non_main_arena = %d\n",
                prev_inuse, is_mmaped, non_main_arena);
    }
    printf("\n");
}

int main(void)
{
    malloc_check(1, 512 - 7, 1);
    malloc_check(BIG_SIZE, BIG_SIZE + 64 * KB, KB);
    malloc_check(BIG_SIZE, BIG_SIZE + 64 * KB, PAGE_SIZE);

    return 0;
}
