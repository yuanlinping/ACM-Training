#include <iostream>
using namespace std;
const int maxn=1000;
int arr[maxn];
int main() {
	int N,a=0,b=0;                     //aΪ1�ĸ�����bΪ2�ĸ��� 
	scanf("%d",&N); 
	for(int i=0;i<N;i++)            //���� 
		scanf("%d",&arr[i]);
	for(int i=0;i<N;i++) {       //��1
		if(arr[i]==1)
			a++;
		}
	for(int i=0;i<N;i++) {    //��2
		if(arr[i]==2)
			b++;
		}
	int d[3]={0,0,0},e[3]={0,0,0},f[3]={0,0,0};   //�����з�Ϊ�����֣��ֱ���1 2 3��ÿ���е�i�����ⲿ�ַ�i�ĸ��� 
	for(int i=0;i<a;i++) {                   //��Ӧ��1�� 
		if(arr[i]==1)
			d[0]++;
		}
	for(int i=0;i<a;i++) {
		if(arr[i]==2)
			d[1]++;
		}
	for(int i=0;i<a;i++) {
		if(arr[i]==3)
			d[2]++;
		}
	for(int i=a;i<a+b;i++) {    //��Ӧ��2 
		if(arr[i]==1)
			e[0]++;
		}
	for(int i=a;i<a+b;i++) {
		if(arr[i]==2)
			e[1]++;
		}
	for(int i=a;i<a+b;i++) {
		if(arr[i]==3)
			e[2]++;
		}
	for(int i=a+b;i<N;i++) {   //��Ӧ��3 
		if(arr[i]==1)
			f[0]++;
		}
	for(int i=a+b;i<N;i++) {
		if(arr[i]==2)
			f[1]++;
		} 
	for(int i=a+b;i<N;i++) {
		if(arr[i]==3)
			f[2]++;
		}
	int c1=d[1]<e[0]?d[1]:e[0];
	int c2=d[2]<f[0]?d[2]:f[0];
	int c3=e[2]<f[1]?e[2]:f[1];
	int c4=d[1]+d[2]-c1-c2;
	printf("%d",c1+c2+c3+2*c4);
	return 0;
}
