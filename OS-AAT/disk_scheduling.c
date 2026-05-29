#include <stdio.h>
#include <stdlib.h>

void fcfs();
void sstf();
void scan();
void clook();

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== DISK SCHEDULING ALGORITHMS =====\n");

        printf("1. FCFS\n");
        printf("2. SSTF\n");
        printf("3. SCAN\n");
        printf("4. C-LOOK\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                fcfs();
                break;

            case 2:
                sstf();
                break;

            case 3:
                scan();
                break;

            case 4:
                clook();
                break;

            case 5:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

void fcfs()
{
    int n, i, head, total = 0;
    int req[20];

    printf("\n--- FCFS Disk Scheduling ---\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        total += abs(req[i] - head);
        head = req[i];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total);
}

void sstf()
{
    int n, i, head, total = 0;
    int req[20], visited[20] = {0};

    printf("\n--- SSTF Disk Scheduling ---\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        int min = 9999;
        int index = -1;
        int j;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(req[j] - head) < min)
            {
                min = abs(req[j] - head);
                index = j;
            }
        }

        visited[index] = 1;
        total += abs(req[index] - head);
        head = req[index];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total);
}

void scan()
{
    int n, i, head, total = 0;
    int req[20];

    printf("\n--- SCAN Disk Scheduling ---\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        total += abs(req[i] - head);
        head = req[i];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total);

    printf("\n(Note: Simplified SCAN simulation)\n");
}

void clook()
{
    int n, i, head, total = 0;
    int req[20];

    printf("\n--- C-LOOK Disk Scheduling ---\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        total += abs(req[i] - head);
        head = req[i];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", total);

    printf("\n(Note: Simplified C-LOOK simulation)\n");




}