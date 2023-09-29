#include<stdio.h>
#include <stdlib.h>
int main()
{
 int i,flag,temp,size;
 printf("Enter number of elements in array\n");
 scanf("%d",&size);
 int a[size];
 printf("Enter Elements of Array for Odd Even Sort\n");
 for(i=0;i<size;i++)
 {
  scanf("%d",&a[i]);
 }
 do{
  flag=0;
  //For Even Sort
  for(i=0;i<size-1;i+=2)
  {
   //Swapping
   if(a[i]>a[i+1])
   {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
        flag=1;
   }
  }
  //For Odd Sort
  for(i=1;i<size-1;i+=2)
  {
   //Swapping
   if(a[i]>a[i+1])
   {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
        flag=1;
   }
  }
 }while(flag);

 printf("Array after Sorting\n");
 for(i=0;i<size;i++)
 {
  printf("%d ",a[i]);
 }
 printf("\n");
}