#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
//#include <map>
using namespace std;

int map[10];
int arr[10],visit[10];
int in[11];


int main(){
	string tel;
	cin>>tel;
	int cnt=0;
	memset(visit,0,sizeof(visit));
	for(int i=0;i<tel.length();i++){   //筛选不重复的 
		int k=tel[i]-'0';
		if(!visit[k]) {
			arr[cnt++]=k; visit[k]=1;
		}
	}
	sort(arr,arr+cnt,greater<int>());
	for(int i=0;i<cnt;i++){   //将数字所在位置与数字本身构成映射 
		map[arr[i]]=i;
	}
	
//	for(int i=0;i<10;i++) printf("%d ",map[i]);
//	printf("\n");
	for(int i=0;i<tel.length();i++){
		int k=tel[i]-'0';
		in[i]=map[k];
	}
	
	 
	
	printf("int[] arr = new int[]{");
	for(int i=0;i<cnt-1;i++) printf("%d,",arr[i]);
	printf("%d};\n",arr[cnt-1]);
	printf("int[] index = new int[]{");
	for(int i=0;i<10;i++) printf("%d,",in[i]);
	printf("%d};\n",in[10]);
}
