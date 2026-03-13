#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], p[n];
    int visited[n]; 

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter AT and BT of P%d: ", p[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        visited[i] = 0; 
    }

    int queue[100]; // Simple queue array
    int front = 0, rear = 0;
    int completed = 0, current_time = 0;

    
    while(completed < n) {
        for(int i = 0; i < n; i++) {
            if(at[i] <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (front == rear) { 
            current_time++;
            continue;
        }

        int i = queue[front++];

        if (rt[i] > tq) {
            current_time += tq;
            rt[i] -= tq;
        } else {
            current_time += rt[i];
            rt[i] = 0;
            ct[i] = current_time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            completed++;
        }

        
        for(int j = 0; j < n; j++) {
            if(at[j] <= current_time && visited[j] == 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        
        if (rt[i] > 0) {
            queue[rear++] = i;
        }
    }
    float sum_tat = 0, sum_wt = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        sum_tat += tat[i];
        sum_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT: %.2f", sum_tat / n);
    printf("\nAverage WT: %.2f\n", sum_wt / n);

    return 0;
}