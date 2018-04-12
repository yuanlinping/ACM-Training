#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	int AB[2]={0,0};
	string line,str;
	getline(cin,line);   //不能直接cin 
	stringstream ss(line);
	int i=0;
	while(ss>>str){
		for(int j=0;j<str.length();j++){
			int k=str[j]-'0';
			if(k>=0&&k<=9) continue;
			else {AB[i]=-1;break;}
		}
		if(AB[i]!=-1){
			int num=atoi(str.c_str());
			if(num<1||num>1000) AB[i]=-1;
			else AB[i]=num;
		}
		i++; 
	}
	if(AB[0]==-1) cout<<"?";else cout<<AB[0];
	cout<<" + ";
	if(AB[1]==-1) cout<<"?";else cout<<AB[1];
	cout<<" = ";
	if(AB[0]!=-1&&AB[1]!=-1)  cout<<AB[0]+AB[1]; else cout<<"?";
}




