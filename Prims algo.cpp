#include <stdio.h>

int a,b,u,v,i,j,n,ne=1;
int visited[10]={0},min,mincost=0,c[10][10];


int main()
{
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    
    printf("Enter the cost of matrix:\n");
    for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
        scanf("%d",&c[i][j]);
        if (c[i][j]==0)
        c[i][j]=999;
    }
    
    visited[1]=1;
    while (ne<n)
    {
        for (i=0,min=999;i<n;i++)
        for (j=0;j<n;j++)
        if (c[i][j]<min)
        if (visited[i]!=0)
        {
            
            min=c[i][j];
            a=u=i;
            b=v=j;
            
        }
        
        
        if (visited[u]==0 || visited[v]==0)
        {
            printf("%d minimum edge (%d %d) is : %d\n",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        c[a][b]=c[b][a]=999;
        
    }
    printf("Mincost is : %d\n",mincost);
    return 0;
}

/*int find(int i)
{
    while(parent[i])
    i=parent[i];
    return i;
}

int uni(int i,int j)
{
    if (i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}*/
