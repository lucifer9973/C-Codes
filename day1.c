//1.1>Write a program to read two numbers and compare the numbers using function call by address.
#include<stdio.h>

int main() 
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if (a > b) {
        printf("a is greater than b\n");
    }
    else if (a < b) {
        printf("a is smaller than b\n");
    }
    else {
        printf("a and b are equal\n");
    }
    return 0;
}