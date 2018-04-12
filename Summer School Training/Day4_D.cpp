#include <iostream>
#include <stack>

using namespace std;

const int MAX = 505;

int fence[MAX][MAX];
int degree[MAX];
stack<int> trace;

int n;

int max(int a, int b){
    return a>b? a: b;
}

void Eular(int k){
    for(int i=1; i<=n; ++i)
        if(fence[k][i]){
            fence[k][i]--;
            fence[i][k]--;
            Eular(i);
        }
    trace.push(k);
}

int main(){
    int i,c,a,b;
    cin>>c;

    n = 0;
    for(i=0; i<c; ++i){
        cin>>a>>b;
        fence[a][b]++;
        fence[b][a]++;
        degree[a]++;
        degree[b]++;
        n = max(n, a);
        n = max(n ,b);
    }

    bool find = false;
    for(i=0; i<=n; ++i)
        if(degree[i]%2 == 1){
            find = true;
            Eular(i);
            break;
        }

    if(!find)
        Eular(1);

    //output
    while(!trace.empty()){
        cout<<trace.top()<<endl;
        trace.pop();
    }
    return 0;
}
