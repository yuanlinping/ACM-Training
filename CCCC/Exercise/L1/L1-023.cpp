#include <iostream>
#include <string>
#include <algorithm>
//#include <ctype>
using namespace std;

struct ch{
  char a;
  int cnt;
}GPLT[4]={{'G',0},{'P',0},{'L',0},{'T',0}}; 

bool cmp(ch g1,ch g2){
	return g1.cnt<g2.cnt;
}
int main(){
	string str;
	cin>>str;
	int cnt[4],cnt1[4];
	for(int i=0;i<str.length();i++){
		char c=str[i];
		switch(c){    //记得单引号 
			case 'g':GPLT[0].cnt++;break;
			case 'p':GPLT[1].cnt++;break;
			case 'l':GPLT[2].cnt++;break;
			case 't':GPLT[3].cnt++;break;
			case 'G':GPLT[0].cnt++;break;
			case 'P':GPLT[1].cnt++;break;
			case 'L':GPLT[2].cnt++;break;
			case 'T':GPLT[3].cnt++;break;
			default:break;
		}
	}
	
//	sort(GPLT,GPLT+4,cmp);
    bool aaa=GPLT[0].cnt||GPLT[1].cnt||GPLT[2].cnt||GPLT[3].cnt;    //本题的输出不要想着计算出每种组合的个数在输出，也用生成测试方的思想，提供给他看是否符合要求 
	while(aaa) {
		for(int i=0;i<4;i++){
		if(GPLT[i].cnt){
			printf("%c",GPLT[i].a);
			GPLT[i].cnt--;
		}
	}
	aaa=GPLT[0].cnt||GPLT[1].cnt||GPLT[2].cnt||GPLT[3].cnt;
	}

	
}
