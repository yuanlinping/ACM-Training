#include<iostream>
#include<cstring>
using namespace std;
bool is[125001];                                                  //记录谁是双平方数的bool数组
int a[125001];                                                    //由于所给上限是250，则最大的数为250*250*2 
int main(){                                                      //n是给的等差数列的长度，top是所给计算平方和数列上限的键值
	int n,top,k=0,tole,num=0;                                    //k初始化为0，最后为的储存双平方数数组的总长度。 
	scanf("%d%d",&n,&top);                                       //tole为公差 ，nu记录满足条件的数组的个数 ，用于判断是否在后面的bool f=0时 
	for(int i=0;i<=top;i++)                                      //把所有的数是否是双平方数记录下来 
		for(int j=0;j<=top;j++)
			is[i*i+j*j]=1;                            
	for(int i=0;i<=top*top*2;i++)                               //把上限范围内的双平方数储存起来 
		if(is[i])
			a[k++]=i;                                          //一共有k个数 

	int maxt=(top*top*2-0)/(n-1);                              //先定义公差为tole，maxt为公差的最大范围  num为记录等差数列的个数                     
	for (tole=1;tole<=maxt;tole++){                            //l为公差 ，a[i]为首项 
		for(int i=0;a[i]+(n-1)*tole<=top*top*2&&i<k;i++){      //a[i]+（n-1）*l为第i项 
			bool f=1;
			for(int j=1;j<n&&f;j++)                           //检查对于每个等差数列，它的每一项元素都在双平方数组中 
				if(!is[a[i]+j*tole]){
					f=0;
				}
			if(f){                                           //在经过对等差数列每一项检查后，f仍为真，则满足题意 
				printf("%d %d\n", a[i],tole);                //满足条件的数列，输出首项和公差 
				num++;                                       //num记录满足条件的数列的个数 
			}
		}
	}
	if (!num)                                               //num为0，则输出NONE 
		printf("NONE");
	return 0;
}
