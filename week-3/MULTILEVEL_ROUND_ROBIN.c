#include <stdio.h>

int main() {
    int n, tq, time = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int p[n][7]; 
    for (int i = 0; i < n; i++) {
        p[i][0] = i + 1;
        printf("P%d [AT BT Type]: ", p[i][0]);
        scanf("%d %d %d", &p[i][1], &p[i][2], &p[i][6]);
        p[i][3] = p[i][2]; 
        p[i][4] = 0;        
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tType\n");

    while (done < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (p[i][1] <= time && !p[i][4]) {
                executed = 1;
                int slice = (p[i][3] > tq) ? tq : p[i][3];
                time += slice;
                p[i][3] -= slice;

                if (p[i][3] == 0) {
                    p[i][5] = time; 
                    p[i][4] = 1;
                    done++;
                    int tat = p[i][5] - p[i][1];
                    int wt = tat - p[i][2];
                    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%s\n", 
                        p[i][0], p[i][1], p[i][2], p[i][5], tat, wt, 
                        (p[i][6] == 1) ? "System" : "User");
                }
            }
        }
        if (!executed) time++;
    }

    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += (p[i][5] - p[i][1]);
        total_wt += (p[i][5] - p[i][1] - p[i][2]);
    }

    printf("\nAverage TAT: %.2f", total_tat / n);
    printf("\nAverage WT : %.2f\n", total_wt / n);

    return 0;
}
