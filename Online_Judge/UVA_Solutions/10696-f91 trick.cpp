/**
 * @author  Quickgrid ( Asif Ahmed )
 * @link    https://quickgrid.wordpress.com
 * Problem: UVA 10696 - f91
 * Type:    Trickery :)
 */

#include<stdio.h>

int main(){
    unsigned n;

    while(scanf("%u", &n) && n){
        if(n <= 100)
            printf("f91(%d) = 91\n", n);
        else
            printf("f91(%d) = %d\n", n, n - 10);
    }

    return 0;
}