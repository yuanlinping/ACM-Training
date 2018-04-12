#include <iostream>

using namespace std;

void read(char a){
	switch(a){
		case '-':cout<<"fu";break;
		case '0':cout<<"ling";break;
		case '1':cout<<"yi";break;
		case '2':cout<<"er";break;
		case '3':cout<<"san";break;
		case '4':cout<<"si";break;
		case '5':cout<<"wu";break;
		case '6':cout<<"liu";break;
		case '7':cout<<"qi";break;
		case '8':cout<<"ba";break;
		case '9':cout<<"jiu";break;
		default:break;
	}
} 

int main(){
	string num;
	cin>>num;
	for(int i=0;i<num.length()-1;i++) {
		read(num[i]);
		cout<<" ";
	}
	read(num[num.length()-1]);
}
