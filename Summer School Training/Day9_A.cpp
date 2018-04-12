#include<cstdio>
using namespace std;

long long gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long d=gcd(b,a%b,x,y);
	long long  xt=x;  
    x=y;  
    y=xt-a/b*y;  //系数x、y的取值是为满足等式d=ax+by  
    
    return d;  
}


int main(){
	long long A,B,C,k;
	scanf("%lld%lld%lld%lld",&A,&B,&C,&k);
	while(!(A==0&&B==0&&C==0&&k==0)){
	long long a=C;  
    long long b=B-A;  
    long long n=(long long)1<<k;  //2^k  
    long long x,y;  
    long long d=gcd(a,n,x,y); 
    
    if(b%d!=0)  //方程 ax=b(mod n) 无解  
        printf("FOREVER\n"); 
        else  
        {  
            x=(x*(b/d))%n;  //方程ax=b(mod n)的最小解  
            x=(x%(n/d)+n/d)%(n/d);  //方程ax=b(mod n)的最整数小解  
            printf("%lld\n",x);  
        }  	
        
	scanf("%lld%lld%lld%lld",&A,&B,&C,&k);	
	}
	
}
