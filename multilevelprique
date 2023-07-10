#include <stdio.h>

#define MAX_QUEUE_SIZE 100

// Process structure
typedef struct {
    int pid; // Process ID
    int priority; // Process priority (0 for system processes, 1 for user processes)
    int burst_time; // Burst time of the process
} Process;

// Queue structure
typedef struct {
    Process processes[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Function prototypes
void enqueue(Queue* queue, Process process);
Process dequeue(Queue* queue);
int is_empty(Queue* queue);

int main() {
    Queue system_queue, user_queue;
    system_queue.front = system_queue.rear = -1;
    user_queue.front = user_queue.rear = -1;

    int num_processes, i;
    Process p;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p.pid);
        printf("Priority (0 for system, 1 for user): ");
        scanf("%d", &p.priority);
        printf("Burst Time: ");
        scanf("%d", &p.burst_time);

        if (p.priority == 0) {
            enqueue(&system_queue, p);
        } else {
            enqueue(&user_queue, p);
        }
    }

    printf("\nSystem Queue:\n");
    while (!is_empty(&system_queue)) {
        p = dequeue(&system_queue);
        printf("Process ID: %d, Burst Time: %d\n", p.pid, p.burst_time);
    }

    printf("\nUser Queue:\n");
    while (!is_empty(&user_queue)) {
        p = dequeue(&user_queue);
        printf("Process ID: %d, Burst Time: %d\n", p.pid, p.burst_time);
    }

    return 0;
}

// Enqueue a process into the queue
void enqueue(Queue* queue, Process process) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full. Cannot enqueue more processes.\n");
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->processes[queue->rear] = process;
}

// Dequeue a process from the queue
Process dequeue(Queue* queue) {
    Process process;

    if (is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        process.pid = -1; // Invalid process ID to indicate an empty process
        return process;
    }

    process = queue->processes[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }

    return process;
}

// Check if the queue is empty
int is_empty(Queue* queue) {
    return queue->front == -1;
}
