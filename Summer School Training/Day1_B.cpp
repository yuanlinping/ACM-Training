#include<iostream>
using namespace std;
int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int day[7] = { 0, 0, 0, 0, 0, 0, 0 };
int main(){
	int k = 5, n;                 
	cin >> n;
	n += 1900;
	for (int i = 1900; i<n; i++){
		if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0)
			mon[1] = 29;  
		for (int j = 0; j<12; j++){
			day[k]++;                  
			k += mon[j];
			k %= 7;                       

		}
		mon[1] = 28;                       

	}
	for (int i = 5; i<7; i++)
		printf("%d ", day[i]);
	for (int i = 0; i<4; i++)
		printf("%d ", day[i]);
	printf("%d",day[4]);

	return 0;
}
