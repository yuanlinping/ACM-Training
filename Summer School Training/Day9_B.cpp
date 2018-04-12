#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
const int maxn=31;  
int n,k,mod;  
  
  
struct matrix  
{  
    int arr[maxn][maxn];  
    matrix()  
    {  
        memset(arr,0,sizeof(arr));  
    }  
};  
  
  
matrix multiply(matrix a,matrix b)   //定义矩阵乘法 
{  
    matrix ret;  
    for(int i=0;i<n;i++)  
        for(int k=0;k<n;k++)  
    {  
        if(a.arr[i][k])  
            for(int j=0;j<n;j++)  
        {  
            ret.arr[i][j]+=a.arr[i][k]*b.arr[k][j];  
            if(ret.arr[i][j]>=mod)  
                ret.arr[i][j]%=mod;  
        }  
    }  
    return ret;  
}  
  
matrix add(matrix a,matrix b)     //定义矩阵加法 
{  
    matrix an;  
    for(int i=0;i<n;i++)  
        for(int j=0;j<n;j++)  
        {  
            an.arr[i][j]=a.arr[i][j]+b.arr[i][j];  
            if(an.arr[i][j]>=mod)  
                an.arr[i][j]%=mod;  
        }  
    return an;  
}  
  
  
  
matrix power(matrix p,int k)  
{  
    if(k==1) return p;  
    matrix e;  
    for(int i=0;i<n;i++)  
        e.arr[i][i]=1;  
    if(k==0) return e;  
    while(k)  
    {  
        if(k&1)  
            e=multiply(p,e);  
        p=multiply(p,p);  
        k>>=1;  
    }  
    return e;  
}  
  
void output(matrix ans)  
{  
    for(int i=0;i<n;i++)  
        for(int j=0;j<n;j++)  
    {  
        if(j==n-1)  
            cout<<ans.arr[i][j]<<endl;  
        else  
            cout<<ans.arr[i][j]<<" ";  
    }  
}  
  
matrix  cal(matrix ori,int k)  
{  
    if(k==1) return ori;  
    if(k&1)  
        return add(cal(ori,k-1),power(ori,k));//当k为奇数时，减1变为偶数 S(K)=S(K-1)+ori^K  
    else  
        return multiply(add(power(ori,0),power(ori,k>>1)),cal(ori,k>>1));  
        //当K为偶数时,S(K)=(1+ori^(K/2))*S(K/2)  
}  
  
int main()  
{  
    scanf("%d%d%d",&n,&k,&mod);
    {  
        matrix ori,ans;  
        for(int i=0;i<n;i++)  
            for(int j=0;j<n;j++)  
        {  
            scanf("%d",&ori.arr[i][j]);  
            if(ori.arr[i][j]>=mod)  
                ori.arr[i][j]%=mod;  
        }  
        ans=cal(ori,k);  
        output(ans);  
    }  
    return 0;  
}  
