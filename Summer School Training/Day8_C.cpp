#include<iostream>
#include<cstdio>
#include<cstring>
char s[50];
int sum,ans;//以百万，千，负号作为 划分区间 


int change(char s[]){
		if(!strcmp(s,"zero")) return 0;
  		else if(!strcmp(s,"one"))  return 1;
  		else if(!strcmp(s,"two"))  return 2;
  		else if(!strcmp(s,"three"))return 3;
  		else if(!strcmp(s,"four")) return 4;
  		else if(!strcmp(s,"five")) return 5;
  		else if(!strcmp(s,"six"))  return 6;
  		else if(!strcmp(s,"seven"))return 7;
  		else if(!strcmp(s,"eight"))return 8;
  		else if(!strcmp(s,"nine"))return 9;
  		else if(!strcmp(s,"ten")) return 10;
  		else if(!strcmp(s,"eleven"))return 11;
  		else if(!strcmp(s,"twelve"))return 12;
  		else if(!strcmp(s,"thirteen"))return 13;
  		else if(!strcmp(s,"fourteen"))return 14;
  		else if(!strcmp(s,"fifteen"))return 15;
  		else if(!strcmp(s,"sixteen"))return 16;
  		else if(!strcmp(s,"seventeen"))return 17;
  		else if(!strcmp(s,"eighteen"))return 18;
  		else if(!strcmp(s,"nineteen"))return 19;
  		else if(!strcmp(s,"twenty"))return 20;
  		else if(!strcmp(s,"thirty"))return 30;
  		else if(!strcmp(s,"forty"))return 40;
  		else if(!strcmp(s,"fifty"))return 50;
  		else if(!strcmp(s,"sixty"))return 60;
  		else if(!strcmp(s,"seventy"))return 70;
  		else if(!strcmp(s,"eighty"))return 80;
  		else if(!strcmp(s,"ninety"))return 90;

  }

int main(){
 	while(scanf("%s",s)!=EOF){
  		if(!strcmp(s,"negative"))printf("-");
  		else if((strcmp(s,"hundred"))&&(strcmp(s,"thousand"))&&(strcmp(s,"thousand"))&&(strcmp(s,"million"))){
  		        sum+=change(s);
		  }
  		else if(!strcmp(s,"hundred")){
    		sum*=100;
  			}
  		else if(!strcmp(s,"thousand")){
   			ans+=sum*1000;
   			sum=0;
  			}
  		else if(!strcmp(s,"million")){
  			ans+=sum*1000000;
   			sum=0;
  			}
  		   // else {
  		     //	sum+=change(s);
		     //}
  				
  		char c=getchar();
  		if(c=='\n'){
   			printf("%d\n",ans+sum);
   			sum=0;
   			ans=0;
  			}
 	}
 	return 0;
}
