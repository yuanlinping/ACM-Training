#include<cstdio>
#include<cstring>

const int maxn=1000005;

char s[maxn];
int next[maxn];

void get_next(char c[],int len)
   {
      int i=0,j=-1;
      next[0]=-1;
      while(i<len)
       {
           if(j==-1||c[i]==c[j]) {j++; i++; next[i]=j;}
           else j=next[j];
       }
}

int main(){
	while (scanf("%s",s)){
		if(s[0]=='.') break;
		int len=strlen(s);
	    get_next(s,len);
	    int n;
	    n=len/(len-next[len]);
	    if(len%(len-next[len])==0) printf("%d\n",n);
	    else printf("1\n");
	}
	return 0;
	
}
