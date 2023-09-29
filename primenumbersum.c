//1.2>Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of all the prime elements of the array using function and de-allocate the memory of the array after its use.
#include<stdio.h>

int main()
{
    int n,i,j,sum=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=2;j<arr[i];j++)
        {
            if(arr[i]==j)
            {
                break;
            }
            else
            {
                sum=sum+j;
            }
        }
    }
    printf("The sum of all the prime elements of the array is %d\n",sum);
    free(arr);
    return 0;
}
