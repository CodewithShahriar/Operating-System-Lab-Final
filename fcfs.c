#include <stdio.h>  

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n];


    for(i = 0; i < n; i++) {
        printf("\nProcess %d Arrival Time: ", i+1);
        scanf("%d", &at[i]);

        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }


    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }


    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }


    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
