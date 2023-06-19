#include <stdio.h>
#include <stdlib.h>

void waitingtime(int proc[], int n, int burst_time[], int wait_time[])
{
    wait_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1];
    }
}

void turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = burst_time[i] + wait_time[i];
}

void avgtime(int proc[], int n, int burst_time[])
{
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    for (int i = 0; i < n; i++)
    {
        total_wt += wait_time[i];
        total_tat += tat[i];
        printf("\n Process :%d  Burst Time:%d Wait Time:%d  Turnaround time:%d", proc[i], burst_time[i], wait_time[i], tat[i]);
    }
    printf("\nAverage wait time:%d  Average turnaround time:%d \n", total_wt / n, total_tat / n);
}

void main()
{
    int proc[10], burst_time[10], n;
    printf("\n Enter the size of n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the processor number:");
        scanf("%d", &proc[i]);
        printf("Enter the burst time:");
        scanf("%d", &burst_time[i]);
    }

    printf("\n");
    avgtime(proc, n, burst_time);
}
