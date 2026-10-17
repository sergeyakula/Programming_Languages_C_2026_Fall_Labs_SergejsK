// week5_task1_file_io.c
// Name: Sergejs  Surname: Kruglovs  Student ID: 251RDC089
//
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
//
// Build: make lab5   Run: ./bin/week5_task1_file_io

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    const char *filename = DEFAULT_FILENAME;
    char line[LINE_LEN];
    int line_count = 0;

    // Bonus: if a file name was given on the command line, use it instead
    if (argc > 1) {
        filename = argv[1];
    }

    // 1. Open the file for writing
    printf("Writing lines to %s...\n", filename);
    fp = fopen(filename, "w");

    // 2. fopen returns NULL if the file cannot be opened
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 3. Write a few lines of text
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");

    // 4. Close the file
    fclose(fp);

    // 5. Open the same file again for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror(filename);
        return EXIT_FAILURE;
    }

    // 6. Read line by line until fgets returns NULL (end of file)
    printf("Reading contents:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    // 7. Close the file
    fclose(fp);

    // Bonus: number of lines read
    printf("Lines read: %d\n", line_count);

    return EXIT_SUCCESS;
}