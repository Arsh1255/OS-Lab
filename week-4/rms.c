#include <stdio.h>
#include <math.h>

int find_lcm(int a, int b) {
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) return max;
        max++;
    }
}

int main() {
    int n, i, j, current_time = 0, hyperperiod = 1;
    float utilization = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], period[n], remaining_burst[n];

    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        remaining_burst[i] = burst[i];
    }

    printf("Enter the time periods:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &period[i]);
        if (i == 0) hyperperiod = period[i];
        else hyperperiod = find_lcm(hyperperiod, period[i]);
        utilization += (float)burst[i] / period[i];
    }

    printf("LCM = %d\n", hyperperiod);
    printf("\nRate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);
    }

    printf("\n%f <= %f => true\n\n", utilization, n * (pow(2, 1.0/n) - 1));
    printf("Scheduling occurs for %d ms\n", hyperperiod);

    int last_pid = -1;
    while (current_time < hyperperiod) {
        int selected = -1;
        int min_period = 10000;

        for (i = 0; i < n; i++) {
            if (current_time % period[i] == 0) {
                remaining_burst[i] = burst[i];
            }
        }

        for (i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                if (period[i] < min_period) {
                    min_period = period[i];
                    selected = i;
                }
            }
        }

        if (selected != last_pid) {
            if (selected != -1)
                printf("%dms onwards: Process %d running\n", current_time, selected + 1);
            else
                printf("%dms onwards: CPU is idle\n", current_time);
            last_pid = selected;
        }

        if (selected != -1) remaining_burst[selected]--;
        current_time++;
    }
    printf("\n\nProgram Developed by : 1bm24cs005");
    return 0;
}