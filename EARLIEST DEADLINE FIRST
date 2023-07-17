#include &lt;stdio.h&gt;
#define arrival 0
#define execution 1
#define deadline 2
#define period 3
#define abs_arrival 4
#define execution_copy 5
#define abs_deadline 6

typedef struct
{
int T[7],instance,alive;

}task;

#define IDLE_TASK_ID 1023
#define ALL 1
#define CURRENT 0

void get_tasks(task *t1,int n);
int hyperperiod_calc(task *t1,int n);
float cpu_util(task *t1,int n);
int gcd(int a, int b);
int lcm(int *a, int n);
int sp_interrupt(task *t1,int tmr,int n);
int min(task *t1,int n,int p);
void update_abs_arrival(task *t1,int n,int k,int all);
void update_abs_deadline(task *t1,int n,int all);
void copy_execution_time(task *t1,int n,int all);

int timer = 0;

int main()
{
task *t;
int n, hyper_period, active_task_id;
float cpu_utilization;
printf(&quot;Enter number of tasks\n&quot;);

scanf(&quot;%d&quot;, &amp;n);
t = malloc(n * sizeof(task));
get_tasks(t, n);
cpu_utilization = cpu_util(t, n);
printf(&quot;CPU Utilization %f\n&quot;, cpu_utilization);

if (cpu_utilization &lt; 1)
printf(&quot;Tasks can be scheduled\n&quot;);
else
printf(&quot;Schedule is not feasible\n&quot;);

hyper_period = hyperperiod_calc(t, n);
copy_execution_time(t, n, ALL);
update_abs_arrival(t, n, 0, ALL);
update_abs_deadline(t, n, ALL);

while (timer &lt;= hyper_period)
{

if (sp_interrupt(t, timer, n))
{
active_task_id = min(t, n, abs_deadline);
}

if (active_task_id == IDLE_TASK_ID)
{

printf(&quot;%d Idle\n&quot;, timer);
}

if (active_task_id != IDLE_TASK_ID)
{

if (t[active_task_id].T[execution_copy] != 0)
{
t[active_task_id].T[execution_copy]--;
printf(&quot;%d Task %d\n&quot;, timer, active_task_id + 1);
}

if (t[active_task_id].T[execution_copy] == 0)
{
t[active_task_id].instance++;
t[active_task_id].alive = 0;
copy_execution_time(t, active_task_id, CURRENT);
update_abs_arrival(t, active_task_id,

t[active_task_id].instance, CURRENT);

update_abs_deadline(t, active_task_id, CURRENT);
active_task_id = min(t, n, abs_deadline);
}
}
++timer;
}
free(t);
return 0;

}
void get_tasks(task *t1, int n)
{
int i = 0;
while (i &lt; n)
{
printf(&quot;Enter Task %d parameters\n&quot;, i + 1);
printf(&quot;Arrival time: &quot;);
scanf(&quot;%d&quot;, &amp;t1-&gt;T[arrival]);
printf(&quot;Execution time: &quot;);
scanf(&quot;%d&quot;, &amp;t1-&gt;T[execution]);
printf(&quot;Deadline time: &quot;);
scanf(&quot;%d&quot;, &amp;t1-&gt;T[deadline]);
printf(&quot;Period: &quot;);
scanf(&quot;%d&quot;, &amp;t1-&gt;T[period]);
t1-&gt;T[abs_arrival] = 0;
t1-&gt;T[execution_copy] = 0;
t1-&gt;T[abs_deadline] = 0;
t1-&gt;instance = 0;
t1-&gt;alive = 0;
t1++;
i++;
}
}

int hyperperiod_calc(task *t1, int n)

{
int i = 0, ht, a[10];
while (i &lt; n)

{
a[i] = t1-&gt;T[period];
t1++;
i++;
}
ht = lcm(a, n);

return ht;
}

int gcd(int a, int b)
{
if (b == 0)
return a;
else
return gcd(b, a % b);

}

int lcm(int *a, int n)
{
int res = 1, i;
for (i = 0; i &lt; n; i++)

{
res = res * a[i] / gcd(res, a[i]);
}
return res;
}

int sp_interrupt(task *t1, int tmr, int n)
{
int i = 0, n1 = 0, a = 0;
task *t1_copy;
t1_copy = t1;
while (i &lt; n)
{
if (tmr == t1-&gt;T[abs_arrival])
{
t1-&gt;alive = 1;
a++;
}
t1++;
i++;
}

t1 = t1_copy;
i = 0;

while (i &lt; n)

{
if (t1-&gt;alive == 0)
n1++;
t1++;
i++;
}

if (n1 == n || a != 0)
{
return 1;
}

return 0;
}

void update_abs_deadline(task *t1, int n, int all)
{
int i = 0;
if (all)
{
while (i &lt; n)
{
t1-&gt;T[abs_deadline] = t1-&gt;T[deadline] + t1-&gt;T[abs_arrival];
t1++;
i++;
}

}
else
{
t1 += n;
t1-&gt;T[abs_deadline] = t1-&gt;T[deadline] + t1-&gt;T[abs_arrival];
}
}

void update_abs_arrival(task *t1, int n, int k, int all)
{
int i = 0;
if (all)
{
while (i &lt; n)
{
t1-&gt;T[abs_arrival] = t1-&gt;T[arrival] + k * (t1-&gt;T[period]);
t1++;
i++;
}
}
else
{
t1 += n;
t1-&gt;T[abs_arrival] = t1-&gt;T[arrival] + k * (t1-&gt;T[period]);
}
}

void copy_execution_time(task *t1, int n, int all)
{
int i = 0;
if (all)
{
while (i &lt; n)
{
t1-&gt;T[execution_copy] = t1-&gt;T[execution];
t1++;
i++;
}
}
else
{
t1 += n;
t1-&gt;T[execution_copy] = t1-&gt;T[execution];
}
}

int min(task *t1, int n, int p)
{
int i = 0, min = 0x7FFF, task_id = IDLE_TASK_ID;
while (i &lt; n)
{
if (min &gt; t1-&gt;T[p] &amp;&amp; t1-&gt;alive == 1)

{
min = t1-&gt;T[p];
task_id = i;
}
t1++;
i++;
}
return task_id;
}

float cpu_util(task *t1, int n)
{
int i = 0;
float cu = 0;
while (i &lt; n)
{
cu = cu + (float)t1-&gt;T[execution] / (float)t1-&gt;T[deadline];
t1++;
i++;
}
return cu;
}
