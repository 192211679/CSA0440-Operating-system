#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i, initial, diskSize, THM = 0;
    int RQ[100], left[100], right[100];
    int l = 0, r = 0;

    printf("Enter the number of requests\n");
    scanf("%d", &n);

    printf("Enter the requests\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter the initial position\n");
    scanf("%d", &initial);

    printf("Enter total disk size\n");
    scanf("%d", &diskSize);

  
    for (i = 0; i < n; i++) {
        if (RQ[i] < initial) {
            left[l++] = RQ[i];
        } else {
            right[r++] = RQ[i];
        }
    }

    qsort(left, l, sizeof(int), compare);
    qsort(right, r, sizeof(int), compare);

    printf("Seek Sequence: %d", initial);

    for (i = 0; i < r; i++) {
        THM += abs(RQ[i] - initial); 
        initial = right[i];
        printf(" -> %d", right[i]);
    }

    
    if (diskSize - 1 > initial) {
        THM += abs(diskSize - 1 - initial);  
        initial = diskSize - 1;
        printf(" -> %d", diskSize - 1);
    }

    for (i = l - 1; i >= 0; i--) {
        THM += abs(left[i] - initial);  
        initial = left[i];
        printf(" -> %d", left[i]);
    }

    printf("\nTotal Head Movement: %d\n", THM);
    return 0;
}

