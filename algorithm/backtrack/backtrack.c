/**
 * backtrack.c 
 * 0/1 bag package problem
 * there are N stones (stones[N])to package in a bag with could only hold w (KG) stones at most
 * the problem is if pick from N stones above, how many KGs counld this bag hold
 **/
#include <stdio.h>
#include <limits.h>

static int maxW = INT_MIN;
static int maxHold = 5;

void f(int , int , int, int[], int);

void f(int cw, int w, int i, int* stones, int numOfStones) {
    if(cw == maxHold || i == numOfStones) {
        if(cw > maxW) {
            printf("f maxW = %d \n", maxW);
            maxW = cw;
        }
        return;
    }
    //do'not hold i(th) stone
    f(cw, w, i+1, stones, numOfStones);
    //hold i(th) stone
    if(cw + stones[i] <= maxHold) {
        f(cw + stones[i], stones[i], i+1, stones, numOfStones);
    }

}

int main(int argc, char** argv) {
    int stores[6]= {1,2,3,4,5,6};
    printf("maxW = %d \n", maxW);
    f(0, 0, 0, &stores, 6);
    printf("maxW = %d \n", maxW);
}