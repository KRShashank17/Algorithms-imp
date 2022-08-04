#include <stdio.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}

int binomial(int n,int k)
{
    int i,j,c[20][20];
    //i=n;
    //j=k;
    
    
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=min(n,k);j++)
        {
            if (j==0 || j==i)
            c[i][j]=1;
            else 
            c[i][j]= c[i-1][j]+c[i-1][j-1];
            
        }
    }
    return c[n][k];
}

int main()
{
    int i,n,k;
    printf("Enter values of n and k:\n");
    scanf("%d %d",&n,&k);
    
    printf("\nBinomial coefficient of C(%d,%d) is :%d",n,k,binomial(n,k));
    
    return 0;
    
}

