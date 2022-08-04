#include <stdio.h>

void ranksort(int a[20],int n);

int main()
{
    int i,n,a[20];
    printf("Enter the number of elements in array:\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (i=0;i<n ;i++)
    scanf("%d",&a[i]);
    
    ranksort(a,n);
    
    return 0;
}

void ranksort(int a[20],int n)
{
    int r[20],b[20],i,j,count=0;
    for (i=0;i<n;i++)
    r[i]=0;
    
    for (i=1;i<n;i++)
    {
        for (j=i-1;j>=0;j--)
        {
            count++;
            
            if (a[i]>a[j])
            r[i]++;
            else 
            r[j]++;
            
        }
    }
    
    for(i=0;i<n;i++)
    b[r[i]]=a[i];
    
    printf("Elements after sort is : \n");
    for (i=0;i<n;i++)
    printf("%d ",b[i]);
    
    printf("\nTime complexity is : %d",count);
}