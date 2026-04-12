#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int wt[n], tat[n], ct[n];

    for (int i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    int time = 0, done = 0;

    while (done < n)
    {
        int shortest = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (shortest == -1 || rt[i] < rt[shortest])
                {
                    shortest = i;
                }
            }
        }

        if (shortest == -1)
        {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if (rt[shortest] == 0)
        {
            done++;
            ct[shortest] = time;
        }
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
