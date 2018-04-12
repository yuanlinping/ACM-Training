#include<iostream>
#include <cstring>
using namespace std;
int a,b,c,d,e,f,g,h,i;   //记录每中移动的次数 
int dot,k,l,bol=0; 
int clocks[10],s[10];
//定义每种移动 
void first(){
	clocks[1]++,clocks[2]++,clocks[4]++,clocks[5]++;
	return;
}

void second(){
	clocks[1]++,clocks[2]++,clocks[3]++; 
	return;
}

void third(){
	clocks[2]++,clocks[3]++,clocks[5]++,clocks[6]++; 
	return;
}

void fourth(){
	clocks[1]++,clocks[4]++,clocks[7]++; 
	return;
}

void fifth(){
	clocks[2]++,clocks[4]++,clocks[5]++,clocks[6]++,clocks[8]++;
	return;
}

void sixth(){
	clocks[3]++,clocks[6]++,clocks[9]++; 
	return;
}


void seventh(){
	clocks[4]++,clocks[5]++,clocks[7]++,clocks[8]++; 
	return;
}

void eighth(){
	 clocks[7]++,clocks[8]++,clocks[9]++; 
	 return;
}


void ninth(){
	clocks[5]++,clocks[6]++,clocks[8]++,clocks[9]++; 
	return;
}

int main(){ 
	for(int z=1;z<10;z++){ //输入 
		scanf("%d",&dot);
		clocks[z]=dot/3;
	}
	
	for(a=1;a<5;a++){
		first();
		for(b=1;b<5;b++){
			second();
			for(c=1;c<5;c++){
				third();
				for(d=1;d<5;d++){
					fourth();
					for(e=1;e<5;e++){
						fifth();
						for(f=1;f<5;f++){
							sixth();
							for(g=1;g<5;g++){
								seventh();
								for(h=1;h<5;h++){
									eighth();
									for(i=1;i<5;i++){
										ninth();
										
										for(k=1;k<=9;k++){    //九种操作运行完后 是否全部变为12   否 进入下一次循环，然后返回上一层循环，依次 
											if(clocks[k]%4!=0) break;
										}
										
										if(k==10)                //全部变为12
                                        { 
                                            memset(s,0,sizeof(s)); 
                                            if(a!=4)s[1]=a; 
                                            if(b!=4)s[2]=b; 
                                            if(c!=4)s[3]=c; 
                                            if(d!=4)s[4]=d; 
                                            if(e!=4)s[5]=e; 
                                            if(f!=4)s[6]=f; 
                                            if(g!=4)s[7]=g; 
                                            if(h!=4)s[8]=h; 
                                            if(i!=4)s[9]=i; 
											
                                            for(l=1;l<=9;l++)
                                            { 
                                                for(k=1;k<=s[l]%4;k++) 
                                                { 
                                                    if(bol)cout<<" "; 
                                                    bol=1;
                                                    cout<<l; 
                                                } 
                                            }
                                        return 0; 
									    }	
								    }
						     	}
						    }
					   }
				   }
			    }
		    }
	    }
       }
    return 0;
}
