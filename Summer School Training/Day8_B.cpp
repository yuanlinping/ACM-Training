#include<cstdio>
#include<cstring>
char last[260]="",now[260]="";
int n,ans,len1=0,len2=0,len=0;

int main()
{
    scanf("%d",&n); 
    for(int i=0;i<n;i++)
    {
        strcpy(last,now);
        len1=len2;
        scanf("%s",&now);
        len2=strlen(now);
        len=0;
        for(int j=0;j<len1&&j<len2;j++)
        {
            if (now[j]!=last[j])
                break;
            len++;
        }
        ans+=len2-len+1;
    }
    printf("%d\n",ans-1);
    return 0;
} 
