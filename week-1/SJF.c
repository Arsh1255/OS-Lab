// program to simulate SJF algorithm
#include <stdio.h>

void sort(int* at,int* bt,int* p,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j] > at[j+1]){
                int temp=at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = p[j]; p[j] = p[j+1] ; p[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    int at[n],bt[n],ct[n],tat[n],wt[n],p[n],finished[n];

    for(int i=0;i<n;i++){
        printf("Enter the AT and BT of P%d : ",i+1);
        p[i] = i+1;
        scanf("%d %d",&at[i],&bt[i]);
        finished[i] = 0;
    }

    sort(at,bt,p,n);

    int completed=0,current_time = 0;

    while(completed < n){
        int idx=-1;
        int min_bt=9999;

        for(int i=0;i<n;i++){
            if(at[i]<=current_time && finished[i] == 0){
                    if(bt[i] < min_bt){
                        min_bt = bt[i];
                        idx = i;
                    }
            }
        }

        if(idx != -1) {
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            current_time = ct[idx];
            finished[idx] = 1;
            completed++;
        }
        else
            current_time++;
    }


    int sum_tat = 0,sum_wt = 0;

    printf("\n\nProcess \tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        sum_tat += tat[i];
        sum_wt += wt[i];
        printf("p%d \t\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n\n");

    float avg_tat = (float)sum_tat/n,avg_wt = (float)sum_wt/n;
    printf("Average TAT: %.2f\nAverage WT: %.2f",avg_tat,avg_wt);
    printf("\n\nPROGRAM DEVELOPED BY ABDUL KHADAR JAMADAR");
}



