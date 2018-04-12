#include<iostream>
#include<stack>
#include<cstdio> 

using namespace std;

const int maxn=1005;

int N;
stack<int>c;
int b[maxn];
bool judge(int t,int b[]){  
    int i,j; 
    for(i=1,j=1;j<=t;i++){  
        if(b[j]==i)  
            j++;  
        else if(!c.empty()&&c.top()==b[j]){  
            c.pop();  
            j++;  
            i--;  
        }
		else if(i<=t)  
            c.push(i);  
        else{  
            while(!c.empty()) c.pop();
            return 0;  
        }  
    }  
    while(!c.empty()) c.pop();
    return 1;  
}  
int main(){
    while(scanf("%d",&N)){
        if(!N) break;
    	while(scanf("%d",&b[1])){   //用于输入一个N下不同的出队序列 
    	    if(!b[1]) {
			break;
			}
    		for(int i=2;i<=N;i++){
    			scanf("%d",&b[i]); 
			}
			if(judge(N,b)) printf("Yes\n");
			   else printf("No\n");
    	}
    printf("\n");	
	}
	return 0; 
}
