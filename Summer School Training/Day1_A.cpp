#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=15;
int order[maxn];
int o=0;
struct per{
	char name[15];
	int out;
	int in;
	int sum;
}person[maxn]; 


int main(){
	int NP;
	scanf("%d",&NP);
	for(int i=0;i<NP;i++) {             
	  scanf("%s",&person[i].name); 
	  person[i].in=0;
	  person[i].out=0;
	  person[i].sum=0;
}
	
	
for(int i=0;i<NP;i++)   {
	int NGi;
	char NAME[15];
	scanf("%s",NAME);
	for(int r=0;r<NP;r++){                                  //输入人名并判断 
		if(strcmp(person[r].name,NAME)==0){
			order[o]=r;
			o++;
			break;	
		}
	}
	
    scanf("%d %d",&person[order[o-1]].out,&NGi);
	char receiver[15];
	  if (NGi!=0)
	  {  int j=person[order[o-1]].out%NGi;
	     person[order[o-1]].out=(j==0)?person[order[o-1]].out:person[order[o-1]].out-j;
	    //printf("%d\n",person[order[o-1]].out);
	    
	    for(int l=0;l<NGi;l++)
	    {scanf("%s",receiver); 
	     for(int k=0;k<NP;k++)
	     {if(strcmp(person[k].name,receiver)==0)
		    {person[k].in+=person[order[o-1]].out/NGi;
		     //printf("%d\n",person[k].in);
		     break;
	        }
	     }
		}
	  }
	  //if(NGi!=0){
	  
	 
}
	 for(int i=0;i<NP;i++)
	 {person[i].sum=person[i].in-person[i].out;
	 }
	 sort(order,order+NP);
	 for(o=0;o<NP-1;o++){
	 	printf("%s %d\n",person[order[o]].name,person[order[o]].sum);
	 } 
	 	printf("%s %d",person[order[NP-1]].name,person[order[NP-1]].sum);
	return 0;
}
