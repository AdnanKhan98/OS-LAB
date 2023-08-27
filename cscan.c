#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform C-SCAN disk scheduling
void cScanDiskScheduling(int requestQueue[], int head, int size) {
    int seekTime = 0;

    // Sort the requestQueue
    bubbleSort(requestQueue, size);

    // Moving towards the right (higher tracks)
    for (int i = 0; i < size; i++) {
        if (requestQueue[i] >= head) {
            seekTime += abs(head - requestQueue[i]);
            head = requestQueue[i];
        }
    }

    // Jump to the beginning and continue moving to the right
    seekTime += abs(head - 0);
    head = 0;
    for (int i = 0; i < size; i++) {
        seekTime += abs(head - requestQueue[i]);
        head = requestQueue[i];
    }

    printf("Total seek time using C-SCAN: %d\n", seekTime);
}

int main() {
    int requestQueue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int size = sizeof(requestQueue) / sizeof(requestQueue[0]);
    int head = 53;

    printf("Request Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", requestQueue[i]);
    }
    printf("\n");

    cScanDiskScheduling(requestQueue, head, size);

    return 0;
}
