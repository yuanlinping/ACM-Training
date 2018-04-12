#include <iostream>
using namespace std;

int a[20],visit[20];                       //a 记录使用的饲料序列，visit标记是否使用
int v[30],food[20][30],v2[30];
int bool1,bool2,t;
int V,G;


void DFS(int x,int k)
{
    int j;
    if(x==k)
    {
        bool1=1;
        for(t=1;t<=V;t++)
            if(v[t]>v2[t])
            {
                bool1=0;
                break;
            }

        if(bool1==1)
        {
            cout<<k;
            for(t=1;t<=k;t++)
            {
                cout<<" "<<a[t];
            }
            bool2=1;
        }
        return ;
    }
    x++;
    for(j=a[x-1]+1;j<=G;j++)
    {
        if(visit[j]==0)
        {
            visit[j]=1;
            a[x]=j;
            for(t=1;t<=V;t++)
            {
                v2[t]+=food[j][t];
            }
            DFS(x,k);
            if(bool2==1)
                break;
            visit[j]=0;
            for(t=1;t<=V;t++)
            {
                v2[t]-=food[j][t];
            }
        }
    }
}

int main()
{
    int i,j,k;
    //输入
    scanf("%d",&V);
    for(i=1;i<=V;i++)
        scanf("%d",&v[i]);
    scanf("%d",&G);
    for(i=1;i<=G;i++)
        for(j=1;j<=V;j++)
            scanf("%d",&food[i][j]);

    bool2=0;
    for(k=1;k<=G;k++)                        //k表示使用饲料的总数
    {
        for(i=1;i<=G;i++)                    //i表示从第一种饲料开始遍历
        {
            if(visit[i]==0)
            {
                visit[i]=1;
                a[1]=i;
                for(t=1;t<=V;t++)
                    v2[t]+=food[i][t];          //使用第i种饲料后，共组成的元素含量
                DFS(1,k);
                if(bool2==1)
                    break;
                visit[i]=0;
                for(t=1;t<=V;t++)
                {
                    v2[t]-=food[i][t];
                }
            }
        }
        if(bool2==1)
            break;
    }
    return 0;
}
