#include <stdio.h>

int main() {
    int n, i, j, time = 0, completed = 0, total_time;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], period[n], deadline[n], remaining[n], next_deadline[n];

    for (i = 0; i < n; i++) {
        printf("Enter Burst, Period, and Deadline for P%d: ", i + 1);
        scanf("%d %d %d", &burst[i], &period[i], &deadline[i]);
        remaining[i] = burst[i];
        next_deadline[i] = deadline[i];
    }

    printf("Enter total simulation time: ");
    scanf("%d", &total_time);

    printf("\nScheduling occurs for %d ms\n", total_time);

    int last_pid = -1;
    while (time < total_time) {
        int selected = -1;
        int min_deadline = 10000;

        for (i = 0; i < n; i++) {
            if (time > 0 && time % period[i] == 0) {
                remaining[i] = burst[i];
                next_deadline[i] = time + deadline[i];
            }
        }

        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (next_deadline[i] < min_deadline) {
                    min_deadline = next_deadline[i];
                    selected = i;
                }
            }
        }

        if (selected != last_pid) {
            if (selected != -1)
                printf("%dms: Task %d is running.\n", time, selected + 1);
            else
                printf("%dms: CPU is idle.\n", time);
            last_pid = selected;
        }

        if (selected != -1) remaining[selected]--;
        time++;
    }
    return 0;
}