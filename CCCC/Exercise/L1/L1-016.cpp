//#define LOCAL
#include <cstdio>

using namespace std;

const int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char ZM[11]={'1','0','X','9','8','7','6','5','4','3','2'};

int main(){
	#ifdef LOCAL
	freopen("data","r",stdin);
	#endif
	int n,allpass=1;
	scanf("%d",&n);
	char ID[20];
	while(n){
		scanf("%s",ID);
		int sum=0,i;
		for(i=0;i<17;i++){
			int num=ID[i]-'0';
			if(num>=0&&num<=9){
				sum+=num*weight[i];
//				printf("%d ",sum);
			}
//			else{allpass=0;printf("17位不对！  %s\n",ID);break;}	
				else{allpass=0;printf("%s\n",ID);break;}	
		}
//		printf("\n");
		if(i==17){
//			if(ID[17]!=ZM[sum%11])  {allpass=0;printf("验证位不对！ %s\n",ID);}
				if(ID[17]!=ZM[sum%11])  {allpass=0;printf("%s\n",ID);}
		}
		n--; 
	}
	if(allpass) printf("All passed\n");
}
