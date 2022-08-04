#include <stdio.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

int main()
{
    int i,j,k,n,c[20][20];
    
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    
    printf("Enter the cost matrix:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        scanf("%d",&c[i][j]);
        
    }
    
    for (k=0;k<n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                c[i][j]=min(c[i][j] ,(c[i][k]+c[k][j]));
                
        }
    
    }
    
    printf("Matrix after algo:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        printf("%d ",c[i][j]);
        printf("\n");
    }

    return 0;
}

