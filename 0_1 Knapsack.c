#include <stdio.h>

int maxx(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int i,j,n,max,w[10],p[10],k[10][10];
    
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the max capacity: ");
    scanf("%d",&max);
    for (i=1;i<=n;i++)
    {
        printf ("Enter weight and profit of item %d :",i);
        scanf("%d %d",&w[i],&p[i]);
    }
    
    for (i=0;i<=n;i++)
    k[i][0]=0;
    
    for (j=0;j<=max;j++)
    k[0][j]=0;
    
    for (i=1;i<=n;i++)
    for (j=1;j<=max;j++)
    {
        if (j<w[i])
        k[i][j]=k[i-1][j];
        else 
        k[i][j]=maxx(k[i-1][j], p[i]+k[i-1][j-w[i]]);
        
    }
    
    printf("Table is : \n");
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=max;j++)
        printf("%d ",k[i][j]);
    
    printf("\n");
    }
    
    
    int x[10];
    for (i=1;i<=n;i++)
    x[i]=0;
    
    i=n;
    j=max;
    while (i!=0 && j!=0)
    {
        if (k[i][j]!=k[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    
    printf("\nMax profit is : %d",k[n][max]);
    printf("\nSubset is { ");
    for (i=1;i<=n;i++)
    printf("%d ",x[i]);
    printf(" }\n");
    
    return 0;
    
}
