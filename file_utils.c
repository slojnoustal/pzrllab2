#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(const char *filename, char **content) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = (char *)malloc(length + 1);
    fread(*content, 1, length, file);
    (*content)[length] = '\0';

    fclose(file);
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);
}
