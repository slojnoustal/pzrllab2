#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_processing.h"
#include "file_utils.h"

void print_usage() {
    printf("Usage:\n");
    printf("./sed_simplified input.txt -r \"old_text\" \"new_text\"\n");
    printf("./sed_simplified input.txt -d \"text_to_delete\"\n");
    printf("./sed_simplified input.txt -i -f \"insert_text_front\"\n");
    printf("./sed_simplified input.txt -i -b \"insert_text_back\"\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    const char *filename = argv[1];
    const char *operation = argv[2];

    if (strcmp(operation, "-r") == 0 && argc == 5) {
        replace_text_in_file(filename, argv[3], argv[4]);
    } else if (strcmp(operation, "-d") == 0 && argc == 4) {
        delete_lines_matching_regex(filename, argv[3]);
    } else if (strcmp(operation, "-i") == 0 && argc == 5) {
        if (strcmp(argv[3], "-f") == 0) {
            insert_text_at_start(filename, argv[4]);
        } else if (strcmp(argv[3], "-b") == 0) {
            insert_text_at_end(filename, argv[4]);
        } else {
            print_usage();
        }
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
