#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

void replace_text_in_file(const char *filename, const char *old_text, const char *new_text) {
    char *content;
    read_file(filename, &content);

    char *result = NULL;
    size_t result_size = strlen(content) + 1;
    result = (char *)malloc(result_size);
    result[0] = '\0';

    char *current = content;
    while ((current = strstr(current, old_text)) != NULL) {
        strncat(result, content, current - content);
        strcat(result, new_text);
        current += strlen(old_text);
        content = current;
    }
    strcat(result, content);

    write_file(filename, result);
    free(result);
    free(content);
}

void delete_lines_matching_regex(const char *filename, const char *pattern) {
    char *content;
    read_file(filename, &content);

    regex_t regex;
    regcomp(&regex, pattern, REG_EXTENDED);

    char *result = NULL;
    size_t result_size = strlen(content) + 1;
    result = (char *)malloc(result_size);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line != NULL) {
        if (regexec(&regex, line, 0, NULL, 0) != 0) {
            strcat(result, line);
            strcat(result, "\n");
        }
        line = strtok(NULL, "\n");
    }

    write_file(filename, result);
    regfree(&regex);
    free(result);
    free(content);
}

void insert_text_at_start(const char *filename, const char *text) {
    char *content;
    read_file(filename, &content);

    char *result = (char *)malloc(strlen(content) + strlen(text) * 10 + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line != NULL) {
        strcat(result, text);
        strcat(result, line);
        strcat(result, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(filename, result);
    free(result);
    free(content);
}

void insert_text_at_end(const char *filename, const char *text) {
    char *content;
    read_file(filename, &content);

    char *result = (char *)malloc(strlen(content) + strlen(text) * 10 + 1);
    result[0] = '\0';

    char *line = strtok(content, "\n");
    while (line != NULL) {
        strcat(result, line);
        strcat(result, text);
        strcat(result, "\n");
        line = strtok(NULL, "\n");
    }

    write_file(filename, result);
    free(result);
    free(content);
}
