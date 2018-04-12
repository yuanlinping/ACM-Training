#include <iostream>   //这题看裘的代码，感觉他写的好简洁= =   然后正的偶数也要*2 
using namespace std;

const string even="02468"; 

void count(int &a,const string& num){
	for(int i=0;i<num.length();i++){
		if(num[i]-'0'==2) a++;
	}
}

int main(){
	string number;
	int cnt2=0;
	double deg,cntt;
	cin>>number;
	count(cnt2,number);
	cntt=number.length();
	if(number[0]=='-'){
		string::size_type p=even.find(number[cntt-1]);
		cntt=cntt-1;
		if(p==string::npos)  deg=cnt2/cntt*1.5*100;
		else deg=cnt2/cntt*1.5*2*100;
	}
	
	else if((number[cntt-1]-'0')%2==0) deg=cnt2/cntt*2*100;
	else deg=cnt2/cntt*100;
	printf("%.2f%c",deg,'%');
	return 0;
}



