//fcfs

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
//22222222222 (SRTF) 222222222222 (Shortest Remaining Time First) 222222222222222222222222222222222222222222222222222222////

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

//333333333333333333(LJF)33333333333333 (Longest Job First) 333333333333333333333333333333333333//


#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];

    for (int i = 0; i < n; i++)
    {
        completed[i] = 0;

        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int time = 0, done = 0;

    while (done < n)
    {
        int longest = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0)
            {
                if (longest == -1 || bt[i] > bt[longest])
                {
                    longest = i;
                }
            }
        }

        if (longest == -1)
        {
            time++;
            continue;
        }

        ct[longest] = time + bt[longest];
        time = ct[longest];
        completed[longest] = 1;
        done++;
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

//44444444(Priority)444444444444444444444444444444444444444444444444444444//

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

//555555555555 (Banker Algo) 5555555555555555555555555555555555555555555555555555555555555555555

#include <stdio.h>

int main()
{
    int p, r, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[p][r], max[p][r], need[p][r];
    int avail[r], finish[p], safe[p];

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < p; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while (count < p)
    {
        int found = 0;

        for (i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {

                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == r)
                {
                    for (k = 0; k < r; k++)
                    {
                        avail[k] += alloc[i][k];
                    }

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nSystem is NOT SAFE\n");
            return 0;
        }
    }

    printf("\nSystem is SAFE\nSafe sequence: ");
    for (i = 0; i < p; i++)
    {
        printf("P%d ", safe[i]);
    }

    return 0;
}





////////////////////////////////////////sjf//////////////////////////////////////////////////////

#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];

    for (int i = 0; i < n; i++)
    {
        completed[i] = 0;

        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int time = 0, done = 0;

    while (done < n)
    {
        int shortest = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0)
            {
                if (shortest == -1 || bt[i] < bt[shortest])
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

        ct[shortest] = time + bt[shortest];
        time = ct[shortest];
        completed[shortest] = 1;
        done++;
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

//////////////////////////////// lrtf///////////////////////////////////////////
#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

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
        int longest = -1;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (longest == -1 || rt[i] > rt[longest])
                {
                    longest = i;
                }
            }
        }

        if (longest == -1)
        {
            time++;
            continue;
        }

        rt[longest]--;
        time++;

        if (rt[longest] == 0)
        {
            done++;
            ct[longest] = time;
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

