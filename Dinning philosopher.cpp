#include <stdio.h>
#define NUM_PHILOSOPHERS 5
void think(int philosopher) {
    printf("Philosopher %d is thinking.\n", philosopher);
}

void eat(int philosopher) {
    printf("Philosopher %d is eating.\n", philosopher);
}

int main() {
    int state[NUM_PHILOSOPHERS] = {0}; 
    int i;

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
       
        think(i);
        
        
        if (state[(i + 4) % NUM_PHILOSOPHERS] != 1 && state[(i + 1) % NUM_PHILOSOPHERS] != 1) {
            state[i] = 1; 
            eat(i);
            state[i] = 0; 
        } else {
            printf("Philosopher %d is waiting for chopsticks.\n", i);
        }
    }

    return 0;
}
