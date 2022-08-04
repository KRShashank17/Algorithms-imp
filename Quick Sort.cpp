#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int count=0;

int partition(int a[20],int b,int e)
{
    int i,j,x;
    i=b-1;
    x=a[e];
    
    for (j=b;j<e;j++)
    {
        count++;
        if (a[j]<x)
        {
            i++;
            swap(&a[i],&a[j]);
            
        }
    }
    swap(&a[i+1],&a[e]);
    return (i+1);
}

void quicksort(int a[20],int b,int e)
{
    if (b<e)
    {
        count++;
        int k=partition(a,b,e);
        quicksort(a,b,k-1);
        quicksort(a,k+1,e);
    }
}

int main()
{
    int i,n,a[20];
    printf("Enter total no of elemets: ");
    scanf("%d",&n);
    
    printf("Enter the elemets:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    quicksort(a,0,n-1);
    
    printf("elemets after sort:\n");
    for (i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\nTime complexity: count is %d \n",count);
    
    return 0;
}