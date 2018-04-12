#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
const int maxn=3000;

struct query{
	int ID,P,rt;
}Q[maxn];

struct comp 
{  
    bool operator ()(const query &a,const query &b)  
    {  
         return a.rt==b.rt?(a.ID>b.ID):(a.rt>b.rt);
    }  
};  

priority_queue<query, vector<query>,comp> que; 

int main(){
	query now;
	now.rt=0;
	char c[9];
	while(scanf("%s",c)&&(c[0]!='#')){       // ‰»Î 
		//if break;
		scanf("%d%d",&now.ID,&now.P);
		now.rt=now.P;
		que.push(now);
		//i++;
	}
	
	int k;
	scanf("%d",&k);
	for(int j=0;j<k-1;j++){
		query temp=que.top();
		que.pop();
		printf("%d\n",temp.ID);
		temp.rt+=temp.P;
		que.push(temp);
	}
	query temp=que.top();
	que.pop();
	printf("%d",temp.ID);
	return 0;	
}
