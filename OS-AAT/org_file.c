#include <stdio.h>
#include <stdlib.h>

void singleLevel();
void twoLevel();
void hierarchical();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== FILE ORGANIZATION TECHNIQUES =====\n");

        printf("1. Single Level Directory\n");
        printf("2. Two Level Directory\n");
        printf("3. Hierarchical Directory\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            singleLevel();
            break;

        case 2:
            twoLevel();
            break;

        case 3:
            hierarchical();
            break;

        case 4:
            printf("Exiting Program...\n");
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

void singleLevel()
{
    int n, i;
    char files[20][30];

    printf("\n--- Single Level Directory ---\n");

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", files[i]);
    }

    printf("\nDirectory Listing:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, files[i]);
    }
}

void twoLevel()
{
    int users, files, i, j;
    char dirname[20];
    char filename[20][30];

    printf("\n--- Two Level Directory ---\n");

    printf("Enter number of users: ");
    scanf("%d", &users);

    for (i = 0; i < users; i++)
    {
        printf("\nEnter directory name for user %d: ", i + 1);
        scanf("%s", dirname);

        printf("Enter number of files: ");
        scanf("%d", &files);

        printf("Enter file names:\n");

        for (j = 0; j < files; j++)
        {
            scanf("%s", filename[j]);
        }

        printf("\nDirectory: %s\n", dirname);

        for (j = 0; j < files; j++)
        {
            printf(" - %s\n", filename[j]);
        }
    }
}

void hierarchical()
{
    char mainDir[30];
    char subDir[30];
    char file[30];

    printf("\n--- Hierarchical Directory ---\n");

    printf("Enter main directory name: ");
    scanf("%s", mainDir);

    printf("Enter subdirectory name: ");
    scanf("%s", subDir);

    printf("Enter file name: ");
    scanf("%s", file);

    printf("\nHierarchical Directory Structure:\n");

    printf("%s/\n", mainDir);
    printf("   %s/\n", subDir);
    printf("      %s\n", file);
}