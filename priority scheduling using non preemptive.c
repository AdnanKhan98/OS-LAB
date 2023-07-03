#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int n, i, j;
   float sum_tat = 0, sum_wt = 0, min;
   int pos, swap, swap2, swap3, swap4, k, sum1 = 0, sum2 = 0, ind,r=0,count=1;
   printf("Enter the number of processes:\n");
   scanf("%d", &n);
   float at[n], bt[n], wt[n], tat[n],pr[n];
   int name[n];
   for (i = 0; i < n; i++)
   {
      printf("Enter the name of process %d:\n", (i + 1));
      scanf("%d", &name[i]);
   }
   for (i = 0; i < n; i++)
   {
      printf("Enter the arrival time of process %d:\n", (i + 1));
      scanf("%f", &at[i]);
   }
   for (i = 0; i < n; i++)
   {
      printf("Enter the burst time of process %d:\n", (i + 1));
      scanf("%f", &bt[i]);
   }

   for (i = 0; i < n; i++)
   {
      printf("Enter the priority of process %d:\n", (i + 1));
      scanf("%f", &pr[i]);
   }
   // memcpy(at2,at,sizeof(at));
   //memcpy(pr2, pr, sizeof(pr));
   //memcpy(name2, name, sizeof(name));

   // sorting based on priority
   for (i = 0; i < n - 1; i++)
   {
      pos = i;
      for (j = i + 1; j < n; j++)
      {
         if (pr[pos] < pr[j])
            pos = j;
      }
      if (pos != i)
      {
         swap = pr[i];
         pr[i] = pr[pos];
         pr[pos] = swap;

         swap2 = name[i];
         name[i] = name[pos];
         name[pos] = swap2;

         swap3 = bt[i];
         bt[i] = bt[pos];
         bt[pos] = swap3;

         swap4 = at[i];
         at[i] = at[pos];
         at[pos] = swap4;
      }
   }

   min = at[0];

   for (k = 1; k < n; k++)
   {
      if (at[k] < min)
      {
         min=at[k];
         ind=k;
      }
   }
   printf("min:%0.1f\n", min);
   printf("ind:%d\n",ind);

   tat[ind] = bt[ind] - at[ind];
   sum1 = tat[ind];
   i=0;
   while(count<n)
   {
      if(i==ind && i<n)
      {
         //r=(r+1)%n;
         i=(i+1)%n;
      }
      else if(at[i]>sum1 || i==ind)
      {
         //r=(r+1)%n;
         i=(i+1)%n;
      }
      else if(at[i]<sum1)
      {
         sum2 = sum1 + bt[i];
         tat[i] = sum2 - at[i];
         sum1 = sum2;
         //r=(r+1)%n;
         i=(i+1)%n;
         count++;
      }


   }
   for (i = 0; i < n; i++)
   {
      sum_tat += tat[i];
   }
   for (i = 0; i < n; i++)
   {
      wt[i] = tat[i] - bt[i];
      sum_wt += wt[i];
   }

   printf("Process Name\tPriority\tArrivalTime\tBurstTime\tTAT\tWaitingTime\n");
   for(int m=0;m<n;m++)
   {
      printf("%d\t\t%0.1lf\t\t%0.1f\t\t%0.1f\t\t%0.1f\t\t%0.1f\n", name[m],pr[m],at[m], bt[m], tat[m], wt[m]);
   }
   printf("Average waiting time:%0.1f\n", (sum_wt) / n);
   printf("Average turn around time:%0.1f\n", (sum_tat) / n);
   return 0;
}
