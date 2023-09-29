#include<stdio.h>
#include<iostream>
using namespace std;

struct rectnagle
{
    int length;
    int breadth;
};

int main()
{
    struct rectnagle r1;
    r1.length ;
    r1.breadth ;
    printf("enter the value of r1");
    scanf("%d",&r1.length);
    printf("enter the value of r2");
    scanf("%d",&r1.breadth);
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    return 0;
}