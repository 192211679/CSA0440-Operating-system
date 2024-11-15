#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, i, THM = 0, initial, RQ[100];
    printf("Enter the number of requests\n");
    scanf("%d", &n);
    
    printf("Enter the requests\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }
    
    printf("Enter the initial position\n");
    scanf("%d", &initial);
    printf("Seeking order",initial);
    for(i = 0; i < n; i++)
    {
        THM = THM + abs(RQ[i] - initial);
        initial = RQ[i];
        printf("->%d",RQ[i]);
    }
    
    printf("\nTotal head movement: %d\n", THM);
    return 0;
}
 
