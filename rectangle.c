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
    r1.length = 10;
    r1.breadth = 20;
    cout << r1.length << endl;
    cout << r1.breadth << endl;
    return 0;
}