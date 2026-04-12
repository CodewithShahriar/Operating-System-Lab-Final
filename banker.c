#include stdio.h

int main()
{
    int p, r, i, j, k;

    printf(Enter number of processes );
    scanf(%d, &p);

    printf(Enter number of resources );
    scanf(%d, &r);

    int alloc[p][r], max[p][r], need[p][r];
    int avail[r], finish[p], safe[p];

    printf(nEnter Allocation Matrixn);
    for (i = 0; i  p; i++)
    {
        for (j = 0; j  r; j++)
        {
            scanf(%d, &alloc[i][j]);
        }
    }

    printf(nEnter Max Matrixn);
    for (i = 0; i  p; i++)
    {
        for (j = 0; j  r; j++)
        {
            scanf(%d, &max[i][j]);
        }
    }

    printf(nEnter Available Resourcesn);
    for (j = 0; j  r; j++)
    {
        scanf(%d, &avail[j]);
    }

    for (i = 0; i  p; i++)
    {
        for (j = 0; j  r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i  p; i++)
    {
        finish[i] = 0;
    }

    int count = 0;

    while (count  p)
    {
        int found = 0;

        for (i = 0; i  p; i++)
        {
            if (finish[i] == 0)
            {

                for (j = 0; j  r; j++)
                {
                    if (need[i][j]  avail[j])
                        break;
                }

                if (j == r)
                {
                    for (k = 0; k  r; k++)
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
            printf(nSystem is NOT SAFEn);
            return 0;
        }
    }

    printf(nSystem is SAFEnSafe sequence );
    for (i = 0; i  p; i++)
    {
        printf(P%d , safe[i]);
    }

    return 0;
}
