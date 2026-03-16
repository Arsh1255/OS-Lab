#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid, at, bt, ct, tat, wt, type;
    bool completed;
} Process;

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter AT, BT & Type (1:System, 2:User) for P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].type);
        p[i].completed = false;
    }

    int completed_count = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tType\n");

    while (completed_count < n) {
        int idx = -1;
        int min_priority = 3; // Higher than System(1) and User(2)

        // Find the highest priority process (System > User) that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && !p[i].completed) {
                if (p[i].type < min_priority) {
                    min_priority = p[i].type;
                    idx = i;
                } 
                // If types are same, FCFS (earliest AT)
                else if (p[i].type == min_priority) {
                    if (idx == -1 || p[i].at < p[idx].at) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            // Process found, execute it
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;
            
            current_time = p[idx].ct;
            completed_count++;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;

            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
                   p[idx].pid, p[idx].at, p[idx].bt, p[idx].ct, 
                   p[idx].tat, p[idx].wt, (p[idx].type == 1) ? "System" : "User");
        } else {
            // No process has arrived yet, jump time forward
            current_time++;
        }
    }

    printf("\nAverage TAT: %.2f", total_tat / n);
    printf("\nAverage WT : %.2f\n", total_wt / n);

    return 0;
}