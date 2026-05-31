#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void fcfs() {
    int n, head, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n];
    printf("Enter requests: "); for(int i=0; i<n; i++) scanf("%d", &req[i]);
    printf("Enter head: "); scanf("%d", &head);
    for(int i=0; i<n; i++) { total += abs(req[i] - head); head = req[i]; }
    printf("Total Seek Time: %d\n", total);
}

void sstf() {
    int n, head, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n], visited[n];
    for(int i=0; i<n; i++) { scanf("%d", &req[i]); visited[i] = 0; }
    printf("Enter head: "); scanf("%d", &head);
    for(int i=0; i<n; i++) {
        int min = 9999, idx = -1;
        for(int j=0; j<n; j++) {
            if(!visited[j] && abs(req[j] - head) < min) { min = abs(req[j] - head); idx = j; }
        }
        visited[idx] = 1; total += min; head = req[idx];
    }
    printf("Total Seek Time: %d\n", total);
}

void scan() {
    int n, head, disk_size, dir, i, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n + 2];
    printf("Enter requests: "); for(i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter head, disk size, direction (0 for low, 1 for high): "); 
    scanf("%d %d %d", &head, &disk_size, &dir);
    req[n] = head; req[n + 1] = (dir == 1) ? disk_size - 1 : 0;
    sort(req, n + 2);
    int pos;
    for(i=0; i<n+2; i++) if(req[i] == head) pos = i;
    if(dir == 1) {
        for(i=pos; i<n+2; i++) { total += abs(req[i] - head); head = req[i]; }
        for(i=pos-1; i>=0; i--) { total += abs(req[i] - head); head = req[i]; }
    } else {
        for(i=pos; i>=0; i--) { total += abs(req[i] - head); head = req[i]; }
        for(i=pos+1; i<n+2; i++) { total += abs(req[i] - head); head = req[i]; }
    }
    printf("Total Seek Time: %d\n", total);
}

void clook() {
    int n, head, dir, i, total = 0;
    printf("Enter number of requests: "); scanf("%d", &n);
    int req[n + 1];
    printf("Enter requests: "); for(i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter head, direction (0 for low, 1 for high): "); scanf("%d %d", &head, &dir);
    req[n] = head; sort(req, n + 1);
    int pos;
    for(i=0; i<n+1; i++) if(req[i] == head) pos = i;
    if(dir == 1) {
        for(i=pos; i<n+1; i++) { total += abs(req[i] - head); head = req[i]; }
        for(i=0; i<pos; i++) { total += abs(req[i] - head); head = req[i]; }
    } else {
        for(i=pos; i>=0; i--) { total += abs(req[i] - head); head = req[i]; }
        for(i=n; i>pos; i--) { total += abs(req[i] - head); head = req[i]; }
    }
    printf("Total Seek Time: %d\n", total);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. FCFS\n2. SSTF\n3. SCAN\n4. C-LOOK\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: fcfs(); break;
            case 2: sstf(); break;
            case 3: scan(); break;
            case 4: clook(); break;
            default: exit(0);
        }
    }
    return 0;
}
