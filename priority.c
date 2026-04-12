#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], pr[n];
    int ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    int time = 0, done = 0;

    while (done < n)
    {
        int highest = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (highest == -1 || pr[i] < pr[highest])
                {
                    highest = i;
                }
            }
        }

        if (highest == -1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if (rt[highest] == 0)
        {
            done++;
            ct[highest] = time;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
