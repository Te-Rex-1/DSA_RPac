#include <stdio.h>

int main() {
    FILE *filePointer;
    char sentence[100];

    // Writing to a file
    filePointer = fopen("example.txt", "w");
    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }
    fprintf(filePointer, "Hello, World!\n");
    fclose(filePointer);

    // Reading from a file
    filePointer = fopen("example.txt", "r");
    if (filePointer == NULL) {
        printf("Error opening the file.\n");
        return -1;
    }
    fscanf(filePointer, "%[^\n]", sentence);
    printf("Sentence read from file: %s\n", sentence);
    fclose(filePointer);

    return 0;
}
