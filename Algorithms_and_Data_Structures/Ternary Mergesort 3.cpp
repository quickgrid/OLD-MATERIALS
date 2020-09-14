#include<stdio.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define SIZE 1000
long A[SIZE];
/*
 * Divides The array to Sub arrays until only one element is left
 * Then calls Merge function on each sub arrays
 */

void Merge( long front,  long mid1,  long mid2,  long rear){
    /*
     * Get size of the left sub array
     */
     long n1 = mid1-front+1;

    /*
     * Get size of the right sub array
     */
     long n2 = mid2 - mid1;
     long n3 = rear - mid2;

    /*
     * Declare left and right sub array with 1 more than original size to store INFINITY
     */
    long *L = new long[n1 + 1];
    long *R = new long[n2 + 1];
    long *X = new long[n3 + 1];

    /*
     * Copy elements of given array to Left sub array
     */
    register  long i = 0;
    for(; i<n1; ++i){
        L[i] = A[front+i];
    }

    /*
     * Copy elements of given array to Right sub array
     */
    register  long j = 0;
    for(; j<n2; ++j){
        R[j] = A[mid1+1+j];
    }

    /*
     * Copy elements of given array to Right sub array
     */
    for(j=0; j<n3; ++j){
        X[j] = A[mid2+1+j];
    }

    /*
     * Set the last element in array to an infinitely big value
     */
    L[n1] = LONG_MAX;
    R[n2] = LONG_MAX;
    X[n3] = LONG_MAX;

    /*
     * Reset both sub array index
     */
    i = 0;
    j = 0;
    register  long p = 0;
    /*
     * Merge:
     * Compare left and right sub array
     * Merge the smaller element back to original array
     */
    register  long k = front;
    for(; k<=rear; ++k){
        if(L[i] <= R[j] && L[i] <= X[p]){
            A[k] = L[i];
            ++i;
        }else if(R[j] <= X[p]){
            A[k] = R[j];
            ++j;
        }else{
            A[k] = X[p];
            ++p;
        }
    }
}

void Mergesort( long front,  long rear){
    if(front < rear){
        /*
         * Calculate the mid point of the given array
         */
         long dist = (rear-front+1) / 3;
         long mid1 = front+dist;
         long mid2 = mid1+dist;
        //printf("%d %d\n", mid1, mid2);
        //Sleep(500);
        /*
         * Divide given array by recursive sending left half of original array
         */
        Mergesort(front, mid1);
        Mergesort(mid1+1, mid2);

        /*
         * Divide given array by recursive sending right half of original array
         */
        Mergesort(mid2+1, rear);

        /*
         * Merge the sub array
         */
        Merge(front, mid1, mid2, rear);
    }
}

int main(){
    register  long i=0, j=0;

    //variables needed to record time
    clock_t begin, end;

    double time_spent;

    srand(time(NULL));
    for(; i<SIZE; ++i){
        A[i] = rand() % SIZE;
    }

    begin = clock();

    Mergesort(0, SIZE-1);

    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

    for(i=0; i<SIZE; ++i){
        printf("%ld ", A[i]);
    }

    printf("\nTime elapsed: %lf\n", time_spent);

    return 0;
}