#include<iostream>
#include<cstring>
using namespace std;
bool is[125001];                                                  //��¼˭��˫ƽ������bool����
int a[125001];                                                    //��������������250����������Ϊ250*250*2 
int main(){                                                      //n�Ǹ��ĵȲ����еĳ��ȣ�top����������ƽ�����������޵ļ�ֵ
	int n,top,k=0,tole,num=0;                                    //k��ʼ��Ϊ0�����Ϊ�Ĵ���˫ƽ����������ܳ��ȡ� 
	scanf("%d%d",&n,&top);                                       //toleΪ���� ��nu��¼��������������ĸ��� �������ж��Ƿ��ں����bool f=0ʱ 
	for(int i=0;i<=top;i++)                                      //�����е����Ƿ���˫ƽ������¼���� 
		for(int j=0;j<=top;j++)
			is[i*i+j*j]=1;                            
	for(int i=0;i<=top*top*2;i++)                               //�����޷�Χ�ڵ�˫ƽ������������ 
		if(is[i])
			a[k++]=i;                                          //һ����k���� 

	int maxt=(top*top*2-0)/(n-1);                              //�ȶ��幫��Ϊtole��maxtΪ��������Χ  numΪ��¼�Ȳ����еĸ���                     
	for (tole=1;tole<=maxt;tole++){                            //lΪ���� ��a[i]Ϊ���� 
		for(int i=0;a[i]+(n-1)*tole<=top*top*2&&i<k;i++){      //a[i]+��n-1��*lΪ��i�� 
			bool f=1;
			for(int j=1;j<n&&f;j++)                           //������ÿ���Ȳ����У�����ÿһ��Ԫ�ض���˫ƽ�������� 
				if(!is[a[i]+j*tole]){
					f=0;
				}
			if(f){                                           //�ھ����ԵȲ�����ÿһ�����f��Ϊ�棬���������� 
				printf("%d %d\n", a[i],tole);                //�������������У��������͹��� 
				num++;                                       //num��¼�������������еĸ��� 
			}
		}
	}
	if (!num)                                               //numΪ0�������NONE 
		printf("NONE");
	return 0;
}
