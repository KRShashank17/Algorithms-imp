#include <stdio.h>
int count=0;

void merge(int a[20],int b,int m,int e)
{
    int i,j,k;
    int n1=m-b+1;
    int n2=e-m;
    int L[n1],R[n2];
    
    for (i=0;i<n1;i++)
    L[i]=a[b+i];
    
    for (j=0;j<n2;j++)
    R[j]=a[m+1+j];
    
    //L[n1]=9999;
    //R[n2]=9999;
    
    i=0;
    j=0;
    k=b;
    
    while (i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else 
        {
            a[k]=R[j];
            j++;
        }
        k++;
    } count++;
    
    while (i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    
    while (j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
    
}

void mergesort(int a[20],int b,int e)
{
    if (b<e)
    {
        count++;
        
        int m=(b+e)/2;
        
        mergesort(a,b,m);
        mergesort(a,m+1,e);
        merge(a,b,m,e);
        
    }
}

int main()
{
    int i,a[20],n;
    
    printf("Enter total no of elements:\n");
    scanf("%d",&n);
    
    printf("Enter the elements:\n");
    for (i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    mergesort(a,0,n-1);
    
    printf("\nElements after sort:\n");
    for (i=0;i<n;i++)
    printf("%d ",a[i]);
    
    printf("\nTime complexity is : %d",count);
    return 0;
}