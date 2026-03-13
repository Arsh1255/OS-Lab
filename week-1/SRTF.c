#include <stdio.h>
#include <limits.h>


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



    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int min_rt = INT_MAX;


        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0) {
                if (rt[i] < min_rt) {
                    min_rt = rt[i];
                    idx = i;
                }

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


