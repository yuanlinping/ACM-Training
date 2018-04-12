#include <cstdio>
#include <iostream>
#include <stack>
#include <cmath> 
using namespace std;

const int maxn=105;

struct agent{
	long long ele,dor;
}ag[maxn];

stack<agent>cal;

void reduce(long long& e,long long& d){   //约分 
	int e1=abs(e),d1=abs(d);
	int m=e1>d1?d1:e1;
//	cout<<e<<" "<<d<<" "<<m<<endl;
	for(int i=2;i<=m;i++){   //因子从正数2，因此要将原本是负数的考虑进去 
		if(abs(e)>=i&&d>=i){    //不能用e1 d1在这里替换 
			if(e1%i==0&&d1%i==0){
			e=e/i;d=d/i;
			reduce(e,d);
		    }
		}
		else break;
	
	}
}

void calculate(agent a1,agent a2){     //计算并进行约分 
	if(a2.ele==0) {cal.push(a1);return;}
	if(a1.ele==0) {cal.push(a2);return;}
	long long ele1=a1.ele*a2.dor+a1.dor*a2.ele;
	long long dor1=a1.dor*a2.dor;
	reduce(ele1,dor1);
	agent a3;
	a3.ele=ele1;a3.dor=dor1;
	cal.push(a3);
}

int main(){
	int n;
	char line;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		cin>>ag[i].ele>>line>>ag[i].dor;
		cal.push(ag[i]);
	}
	agent ag1,ag2;
 	while(!cal.empty()){
 		ag1=cal.top();
 		cal.pop();
 		if(!cal.empty()){
 	    	ag2=cal.top();
 		    cal.pop();
 	    	calculate(ag1,ag2);
		}
	 }
	 if(ag1.ele==0) cout<<0;
	 else if(ag1.dor==1) cout<<ag1.ele;
	 else cout<<ag1.ele<<"/"<<ag1.dor;
//	 cout<<abs(-3);
} 
