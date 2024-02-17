#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int words = 0, lines = 0, characters = 0, inWord = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening file. Please check the filename and try again.\n");
        return 1; // Exit with an error code
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        characters++;
           printf("%c",ch);
        // Check for newlines to count lines
        if (ch == '\n') {
            lines++;
        }

        // Check for word boundaries
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    // Close the file
    fclose(file);

    // Display the results
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);
    printf("Total characters: %d\n", characters);

    return 0; // Exit successfully
}
