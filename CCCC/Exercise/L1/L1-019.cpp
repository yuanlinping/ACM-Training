#include <cstdio>

using namespace std;
const int maxn=105;
int record[maxn][4];

int main(){
//	freopen("data019","r",stdin);
	int mostA,mostB,turn;
	scanf("%d %d",&mostA,&mostB);
	scanf("%d",&turn);
	for(int i=0;i<turn;i++)
		for(int j=0;j<4;j++)
		scanf("%d",&record[i][j]);
	bool Afall=false,Bfall=false;
	int Adr=0,Bdr=0;
	for(int i=0;i<turn;i++){
		int sum=record[i][0]+record[i][2];
		if(record[i][1]==sum&&record[i][3]==sum) continue;
		else if(record[i][1]!=sum&&record[i][3]!=sum) continue;
		else if(record[i][1]==sum) Adr++;
		else if(record[i][3]==sum) Bdr++;
		if(Adr>mostA) {
			printf("%c\n",'A');
			printf("%d",Bdr);
			break;
		}
		else if(Bdr>mostB){
			printf("%c\n",'B');
			printf("%d",Adr);
			break;
		}		
	}
	return 0;
} 
