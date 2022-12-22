#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define _GNU_SOURCE
 void *memmem(const void *haystack, size_t haystacklen,
                    const void *needle, size_t needlelen);

int main(int argc, char **argv) {
    char *filename = argv[1];
    int file = open(filename, O_RDONLY);
    char *str = argv[2];
    size_t str_len = strlen(str);
    struct stat f_stat;
    stat(filename, &f_stat);
    size_t size = f_stat.st_size;
    
    char *file_adr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, file, 0); 
    const char* start_adr = file_adr;
    const char* new_adr = memmem(start_adr, size, str, str_len);

    while (new_adr != NULL) {
        size -=(size_t)(new_adr - start_adr + 1);
        start_adr = new_adr + 1;
        printf("%ld\n", new_adr - file_adr);
        new_adr = memmem(start_adr, size, str, str_len);
    }
    munmap((void*)file_adr, size);
    close(file);

    return 0;
}