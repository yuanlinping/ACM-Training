#include<cstdio>
#include<cstring>

const int maxn=21;

char par[2*maxn];
int right[maxn];
int rgl[maxn];
int res[maxn];

int main(){
	int t;
	scanf("%d",&t);               //�����
	 
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		
		memset(par,'(',sizeof(par));       //����ȫ��ʼΪ�� 
		memset(right,0,sizeof(right));     //���ڼ�¼ÿ����ǰ�ģ� ���� 
		memset(rgl,0,sizeof(rgl));         //���ڼ�¼�������λ�� 
	    memset(res,0,sizeof(res));         //ת��Ϊw���к�Ľ�� 
	    
		for(int j=1;j<=n;j++){           //���� ÿ����ǰ�ģ� ����
			scanf("%d",&right[j]);
		}
		
		int lp=0,rp=0;
		for(int j=1;j<=n;j++){
		    rgl[j]=right[j]+j;
			par[rgl[j]]=')';
			for(int k=rgl[j];k>=1;k--){
				if(par[k]==')') rp++;
				else if(par[k]=='(')lp++;
			    if(rp==lp) {res[j]=rp;break;} 
			}
			lp=0,rp=0;
		}
        bool f=true;
		for(int k=1;k<=n;k++){
			if(f){
				printf("%d",res[k]);
				f=false;
			}
			else printf(" %d",res[k]);
		}
		printf("\n");
	}
	return 0;
}
