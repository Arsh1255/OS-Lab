#include <stdio.h>
#include <limits.h>

// Function to sort processes by Arrival Time
void sort(int* at, int* bt, int* p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        p[i] = i + 1;
    }

    // 1. Sort by Arrival Time so the simulation starts correctly
    sort(at, bt, p, n);

    // 2. Initialize Remaining Time AFTER sorting
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_rt = INT_MAX;

        // Find process with shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) {
                if (rt[i] < min_rt) {
                    min_rt = rt[i];
                    idx = i;
                }
                // Tie-breaker: If RT is equal, pick the one that arrived first
                else if (rt[i] == min_rt) {
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1) {
            current_time++;
        } else {
            rt[idx]--;
            current_time++;

            if (rt[idx] == 0) {
                completed++;
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        }
    }

    // 3. Calculate Totals and Averages
    float total_tat = 0, total_wt = 0;

    printf("\n\nProcess \tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
        printf("P%d \t\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n-------------------------------------------");
    printf("\nTotal Turnaround Time: %.2f", total_tat);
    printf("\nTotal Waiting Time:    %.2f", total_wt);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time:    %.2f", total_wt / n);
    printf("\n-------------------------------------------");
    printf("\n\nPROGRAM DEVELOPED BY ABDUL KHADAR JAMADAR\n");

    return 0;
}
