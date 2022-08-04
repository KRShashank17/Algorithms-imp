#include <stdio.h>
void selection(int a[20],int n);

int main()
{
    int n,a[20];
    printf("Enter the total number of elements in array\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for (int i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    selection(a,n);
    return 0;
    
}

void selection(int a[20],int n)
{
    int i,j,min,count=0;
    for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
        {
            count++;
            if (a[min]>a[j])
            min=j;
        }
        if (min!=i)
        {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            
        }
    }
    printf("Array after sorting:\n");
    for (i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\nTime complexity is %d\n",count);
    
    
}