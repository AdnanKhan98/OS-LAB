#include <stdio.h>
int main() {
int n, m, all[10][10], req[10][10], ava[10], need[10][10];
int i, j, k, flag[10], prev[10], c, count = 0,array[10],z=0;
printf("Enter number of processes and number of resources required \n");
scanf("%d %d", &n, &m);
printf("Enter total number of required resources %d for each process\n", n);
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &req[i][j]);
printf("Enter number of allocated resources %d for each process\n", n);
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
scanf("%d", &all[i][j]);
printf("Enter number of available resources \n");
for (i = 0; i < m; i++)
scanf("%d", &ava[i]);
for (i = 0; i < n; i++)
for (j = 0; j < m; j++)
need[i][j] = req[i][j] - all[i][j];
for (i = 0; i < n; i++)
flag[i] = 1;
k = 1;
while (k) {
k = 0; // Reset the value of k for each iteration of the loop
for (i = 0; i < n; i++) {
if (flag[i]) {
c = 0;
for (j = 0; j < m; j++) {
if (need[i][j] <= ava[j]) {
c++;
}
}
if (c == m) {
array[z++]=i;
printf("Resouces can be allocated to Process:%d and available resources are: ", (i
+ 1));
for (j = 0; j < m; j++) {
printf("%d ", ava[j]);
}
printf("\n");
for (j = 0; j < m; j++) {
ava[j] += all[i][j];
all[i][j] = 0;
}
flag[i] = 0;
count++;
}
}
}
// Check if the current state is different from the previous state
for (i = 0; i < n; i++) {
if (flag[i] != prev[i]) {
k = 1;
break;
}
}
for (i = 0; i < n; i++) {
prev[i] = flag[i];
}
}
printf("\nNeed Matrix:\n");
for (i = 0; i < n; i++) //printing need matrix
{
for (j = 0; j < m; j++)
printf("%d ",need[i][j]);
printf("\n");
}
if (count == n) {
printf("\nSystem is in safe mode \n<");
for(i=0;i<n;i++)
printf("P%d ",(array[i]+1));
printf(">\n");
} else {
printf("\nSystem is not in safe mode deadlock occurred \n");
}
return 0;
}
