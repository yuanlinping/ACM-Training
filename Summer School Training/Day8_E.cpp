#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <iomanip>

using namespace std;
map<string,int>hw;

int main(){
	int count=0;
	string c;
	while(getline(cin,c)){
		hw[c]++;
		count++;
	}
	map<string,int >::iterator i;  
    for(i=hw.begin();i!=hw.end();i++)  
    {  
        cout<<setiosflags(ios::fixed)<<setprecision(4)<<i->first;
		cout<<" ";
		cout<<100.0*(i->second)/count<<endl;  
    }  
    return 0;
}
