#include <stdio.h>
#include <stdbool.h>

#define MAX_P 10
#define MAX_R 10

int main() {
    int NP, NR;
    int max[MAX_P][MAX_R];        
    int alloc[MAX_P][MAX_R];      
    int need[MAX_P][MAX_R];       
    int avl[MAX_R];              
    int safeSeq[MAX_P];           
    bool fin[MAX_P] = {false};    

   
    printf("Enter the number of processes: ");
    scanf("%d", &NP);
    printf("Enter the number of resources: ");
    scanf("%d", &NR);

    printf("Enter the Max matrix:\n");
    for (int i = 0; i < NP; i++) {
        for (int j = 0; j < NR; j++) {
            scanf("%d", &max[i][j]);
        }
    }

   
    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < NP; i++) {
        for (int j = 0; j < NR; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    
    printf("Enter the Available resources:\n");
    for (int i = 0; i < NR; i++) {
        scanf("%d", &avl[i]);
    }


    for (int i = 0; i < NP; i++) {
        for (int j = 0; j < NR; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

  
    int cnt = 0;
    while (cnt < NP) {
        bool found = false;
        for (int i = 0; i < NP; i++) {
            if (!fin[i]) {
                bool canAlloc = true;
                for (int j = 0; j < NR; j++) {
                    if (need[i][j] > avl[j]) {
                        canAlloc = false;
                        break;
                    }
                }

                if (canAlloc) {
                   
                    for (int k = 0; k < NR; k++) {
                        avl[k] += alloc[i][k];
                    }
                    safeSeq[cnt++] = i;
                    fin[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state, no safe sequence found.\n");
            return -1;
        }
    }

    
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < NP; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}

