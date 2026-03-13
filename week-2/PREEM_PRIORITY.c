// Program to simulate the preemptive scheduling algorithms
// assuming LOWER THE NUMBER -> HIGHER THE PRIORITY
#include <stdio.h>



int main(){
    int n;
    printf("Enter the number of process : ");
    scanf("%d",&n);

    int arr[n],at[n],bt[n],ct[n],wt[n],rt[n],pr[n],p[n],tat[n];

    for(int i=0;i<n;i++){
        printf("Enter the AT,BT and priority of P%d : ",i+1);
        p[i] = i+1;
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        rt[i] = bt[i];
    }

    int completed = 0,current_time = 0;

    while(completed < n){
        int idx = -1;
        int highest = 9999;

        for(int i=0;i<n;i++){
            if(at[i] <= current_time && rt[i] > 0  && pr[i] < highest){
                highest = pr[i];
                idx = i;
            }
        }

        if(idx != -1){
            rt[idx]--;
            current_time++;

            if(rt[idx] == 0){
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                completed++;
            }       
        }
        else
            current_time++;
    }

    float total_tat = 0, total_wt = 0;

    printf("\n\nProcess \tAT\tBT\tPRIORITY\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
        printf("P%d \t\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT: %.2f", total_tat / n);
    printf("\nAverage WT:    %.2f", total_wt / n);

    printf("\n\nPROGRAM DEVELOPED BY ABDUL KHADAR JAMADAR\n");
    return 0;
}  


