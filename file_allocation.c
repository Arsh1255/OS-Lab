#include <stdio.h>
#include <stdlib.h>

void sequential();
void linked();
void indexed();

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== FILE ALLOCATION STRATEGIES =====\n");
        printf("1. Sequential Allocation\n");
        printf("2. Linked Allocation\n");
        printf("3. Indexed Allocation\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sequential();
            break;

        case 2:
            linked();
            break;

        case 3:
            indexed();
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

void sequential(){
    int start, length, i;
    char filename[20];

    printf("\n--- Sequential Allocation ---\n");

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file: ");
    scanf("%d", &length);

    printf("\nFile Name: %s\n", filename);
    printf("Allocated Blocks: ");

    for(i = 0; i < length; i++)
    {
        printf("%d ", start + i);
    }

    printf("\n");
}

void linked(){
    int n, i;
    int blocks[20];
    char filename[20];

    printf("\n--- Linked Allocation ---\n");

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nFile Name: %s\n", filename);

    printf("Linked Allocation:\n");

    for(i = 0; i < n - 1; i++)
    {
        printf("%d -> ", blocks[i]);
    }

    printf("%d -> NULL\n", blocks[n - 1]);
}

void indexed()
{
    int indexBlock, n, i;
    int blocks[20];
    char filename[20];

    printf("\n--- Indexed Allocation ---\n");

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &blocks[i]);
    }

    printf("\nFile Name: %s\n", filename);

    printf("Index Block: %d\n", indexBlock);

    printf("\nAllocated Blocks:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d\n", indexBlock, blocks[i]);
    }
}