#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std; 

const int maxn=100010;
int st[maxn];  

int change(char a){
switch (a){
               case 'A' :
               case 'B' :
               case 'C' :
               case '2' :
                     return 2;
                     break ;
               case 'D' :
               case 'E' :
               case 'F' :
               case '3' :
                      return 3;
                      break ;
               case 'G' :
               case 'H' :
               case 'I' :
               case '4' :
                      return 4;
                      break ;
               case 'J' :
               case 'K' :
               case 'L' :
               case '5' :
                      return 5;
                      break ;
               case 'M' :
               case 'N' :
               case 'O' :
               case '6' :
                      return 6;
                      break ;
               case 'P' :
               case 'R' :
               case 'S' :
               case '7' :
                      return 7;
                      break ;
               case 'T' :
               case 'U' :
               case 'V' :
               case '8' :
                      return 8;
                      break ;
               case 'W' :
               case 'X' :
               case 'Y' :
               case '9' :
                      return 9;
                      break ;
               case('1'):
			          return 1;
			          break;  
			   case('0'):
			         return 0;
			          break;       
               default :
                      break ;
              }

}


bool cmp(int a,int b){
	return  a<b;
} 

int main(){  
    int n;
	bool t=true; 
	char s[210]; 
	
    scanf("%d",&n);  
    
    for(int i=0;i<n;i++){  
        st[i]=0; 
        scanf("%s",s);  
        int len=strlen(s);  
        for(int j=0;j<len;j++){  
            if(s[j]=='-')continue;  
            else st[i]= change(s[j])+st[i]*10;  
        }  
    }  
    
    sort(st,st+n,cmp);  
    
    for(int i=0;i<n;i++){  
        int ans=1;  
        while(st[i]==st[i+1]&&i+1<n){ 
		    t=false;
			i++;  
            ans++;
	    }
        if(ans>=2){  
        printf("%03d-%04d %d\n",st[i]/10000,st[i]%10000,ans);
        }  
    }  
    if(t)printf("No duplicates.\n");  
    return 0;  
}  
