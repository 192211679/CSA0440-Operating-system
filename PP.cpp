#include <stdio.h>
#define max 30

int main() {
    int i, j, n, bt[max], wt[max], tat[max],at[max];
    float awt = 0, atat = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Enter the arrival time ");
    for(i=0;i<n;i++){
    	scanf("%d",&at[i]);
	}
    
    printf("Process\tBurst Time\tArrival time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];    
        atat += tat[i];   
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i],at[i],wt[i], tat[i]);
    }
    
    awt /= n;   
    atat /= n;  
    
    printf("Average Waiting Time = %.2f\n", awt);
    printf("Average Turnaround Time = %.2f\n", atat);
    
    return 0;
}

