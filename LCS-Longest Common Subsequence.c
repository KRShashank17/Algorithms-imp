#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxx(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int i,j,n,m,lcs[20][20];
    char x[10],y[10];
    
    printf("Enter the first string: ");
    scanf("%s",x);
    printf("Enter the second string: ");
    scanf("%s",y);
    
    n=strlen(x);
    m=strlen(y);
    
    for (i=0;i<=n;i++)
    lcs[i][0]=0;
    
    for (j=0;j<=m;j++)
    lcs[0][j]=0;
    
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        if (x[i-1]==y[j-1])
        lcs[i][j]=1+lcs[i-1][j-1];
        else 
        lcs[i][j]=maxx(lcs[i-1][j], lcs[i][j-1]);
        
    }
    
    printf("Table is : \n");
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=m;j++)
        printf("%d ",lcs[i][j]);
    
    printf("\n");
    }
    
    
    int index=lcs[n][m];
    char L[10];
    L[index--]='\0';
    i=n;
    j=m;
    
    while (i!=0 && j!=0)
    {
        if (x[i-1]==y[j-1])
        {
            L[index--]=x[i-1];
            i--;
            j--;
        }
        else if (lcs[i-1][j]>=lcs[i][j-1])
        i--;
        else 
        j--;
    }
    
    printf("\nMax subsequence length is : %d",lcs[n][m]);
    printf("\nLongest Common subsequence is: %s\n",L);
    
    
    return 0;
    
}

