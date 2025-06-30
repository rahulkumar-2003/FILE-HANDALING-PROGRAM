#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w"); // overwrite mode
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    char data[100];
    printf("Enter data to write (max 100 chars): ");
    getchar(); // consume newline
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    printf("Data written successfully.\n");

    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); // append mode
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    char data[100];
    printf("Enter data to append (max 100 chars): ");
    getchar(); // consume newline
    fgets(data, sizeof(data), stdin);

    fprintf(fp, "%s", data);
    printf("Data appended successfully.\n");

    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading or file doesn't exist!\n");
        return;
    }

    char ch;
    printf("File content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

int main() {
    char filename[50] = "example.txt";
    int choice;

    while (1) {
        printf("\nFile Operations Menu:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(filename); break;
            case 2: writeFile(filename); break;
            case 3: appendFile(filename); break;
            case 4: readFile(filename); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}