#include <stdio.h>

void insertionsort(int a[20],int n);

int main()
{
    int i,n,a[20];
    printf("Enter the number of elements in array:\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (i=0;i<n ;i++)
    scanf("%d",&a[i]);
    
    insertionsort(a,n);
    
    return 0;
}

void insertionsort(int a[20],int n)
{
    int i,j,key,count=0;
    
    for (i=0;i<n;i++)
    {
        count++;
        key=a[i];
        j=i-1;
        
        while (a[j]>key && j>=0)
        {
            count++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        
    }
    
    printf("Elements after sort is : \n");
    for (i=0;i<n;i++)
    printf("%d ",a[i]);
    
    printf("\nTime complexity is : %d",count);
}
