#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int n,c1,c2;
int H[maxn];

void swap(int i ,int j){
	int t = H[i];
	H[i] = H[j];
	H[j] = t;
}

void buildHeap(){    //���� 
	for(int i = 1;i <= n;i++){
		int p = i;
		while(p > 1){
			if(H[p] < H[p/2]){swap(p,p/2); p = p / 2;}
			else break; 
		}
	}
}

int find(int st, int k){   //��ĳ��Ԫ�ص��±� 
	int i = st;
	if( 2 * i > n) if(H[i] == k) return i;   //�ýڵ�ΪҶ�ڵ� 
	if( 2 * i == n) {if(H[i] == k) return i; else if(H[2 * i] == k) return 2 * i;}  //�ýڵ�ֻ�����ӽڵ� 
	while(2 * i < n){   //�ýڵ��������ӽڵ� 
		if(H[i] == k) return i; 
		if(H[2 * i] > k && H[2 * i + 1] <= k) return find(2 * i + 1, k);   //����һ�߶Ѷ�Ԫ�ش��ڣ������Ǵ��ڵ��ڣ�����ɽ���Χ��С��1/2 
		else if(H[2 * i] <= k && H[2 * i + 1] > k) return find(2 * i, k);
		else{   //�����ӶѵĶѶ���С�ڸ�Ԫ�� 
			int in = find(2 * i,k);
			if(in != -1) return in;
			else {return find(2 * i + 1,k);}
		}
	}
	return -1;
}

int main(){
	freopen("data012.txt","r",stdin);
	int m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&H[i]);
	buildHeap();
	string str0;
	getline(cin,str0);
	while(m){
		bool flag = false;
		string str,sub;
		getline(cin,str);
		stringstream ss(str);
		if(str[str.length()-1]=='t'){ss >> c1;if(c1 == H[1]) flag = true;}
		
		else if(str[str.length()-1] == 's') {
			ss >> c1;
			ss >> sub;
			ss >> c2;
			int in1,in2;
			in1 = find(1,c1); in2 = find(1,c2);
			if( in1/2 == in2/2) flag = true;
			}
			
		else {
			ss >> c1;
			bool isp = true;
			for(int i = 0; i < 4;i++){
				ss >> sub;
				if(i == 1 && sub[0] == 'a') isp = false;
			}
			ss >> c2;
			int in1,in2;
			in1 = find(1,c1); in2 = find(1,c2);
			
			if(isp){if(in1 == in2 / 2) flag = true;}  //֮ǰ�������� 
			else if(in2 == in1 / 2) flag = true;
		}
		
		 printf("%c\n",flag?'T':'F');
		m--;
	}
}
