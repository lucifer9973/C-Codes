#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;


void addsub(int *a,int *b) {
    int c = *a + *b;
    int d = *a - *b;
    *a = c;
    if (d<0) d=-d;
    *b=d; {
    
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    printf("enter numbers to sub and add: \n");
    scanf("%d %d", &a, &b);
    addsub(pa, pb);
    printf("the added and subtracted numbers are : \n");
    printf("%d\n%d", a, b);

    return 0;
}
