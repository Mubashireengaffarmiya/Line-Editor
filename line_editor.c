#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Function to insert a line */
void insertLine()
{
    int lineNumber;
    char text[MAX_LENGTH];

    if (lineCount >= MAX_LINES)
    {
        printf("Error: Document is full.\n");
        return;
    }

    printf("Enter line number (1-%d): ", lineCount + 1);
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    /* Shift lines downward */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    /* Insert new line */
    strcpy(lines[lineNumber - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Function to delete a line */
void deleteLine()
{
    int lineNumber;

    if (lineCount == 0)
    {
        printf("Error: Document is empty.\n");
        return;
    }

    printf("Enter line number (1-%d): ", lineCount);
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Error: Invalid line number.\n");
        return;
    }

    /* Shift lines upward */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Function to display the document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n========== DOCUMENT ==========\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("==============================\n");
}

/* Function to save document to a file */
void saveFile()
{
    FILE *file;

    file = fopen("document.txt", "w");

    if (file == NULL)
    {
        printf("Error: Could not save the document.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully to document.txt\n");
}

/* Function to load document from a file */
void loadFile()
{
    FILE *file;

    file = fopen("document.txt", "r");

    if (file == NULL)
    {
        printf("Error: document.txt not found.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;
    }

    fclose(file);

    printf("Document loaded successfully.\n");
    printf("%d line(s) loaded.\n", lineCount);
}

/* Function to display help */
void showHelp()
{
    printf("\n========== HELP ==========\n");

    printf("I - Insert a new line\n");
    printf("D - Delete a line\n");
    printf("P - Display the document\n");
    printf("S - Save the document\n");
    printf("L - Load the document\n");
    printf("H - Show this help menu\n");
    printf("Q - Quit the program\n");

    printf("==========================\n");
}

/* Main function */
int main()
{
    char command;

    printf("=====================================\n");
    printf("       SIMPLE COMMAND-LINE EDITOR\n");
    printf("=====================================\n");

    printf("\nType H for help.\n");

    while (1)
    {
        printf("\nEnter command: ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'I':
            case 'i':
                insertLine();
                break;

            case 'D':
            case 'd':
                deleteLine();
                break;

            case 'P':
            case 'p':
                displayDocument();
                break;

            case 'S':
            case 's':
                saveFile();
                break;

            case 'L':
            case 'l':
                loadFile();
                break;

            case 'H':
            case 'h':
                showHelp();
                break;

            case 'Q':
            case 'q':
                printf("Exiting Line Editor...\n");
                return 0;

            default:
                printf("Error: Invalid command. Type H for help.\n");
        }
    }

    return 0;
}