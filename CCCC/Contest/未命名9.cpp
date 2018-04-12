#define rep(i,n) for(int i=0;i<n;i++)
const int maxn=

int Tree(int L1,int R1,int L2,int R2){
	if(L1>R1) return -1;
	int root=pre[L1];
	int lenl,lenr;
	for(int i=L2;i<=R2;i++)if(in[i]==root){lenl=i-L2;break;}
	lenr=R2-L2-lenl;
	le[L1]=Tree();
	ri[L1]=Tree();
	return L1;
}

set<int>::iterator it;
for(it=begin();it=end();++it)
printf("%n",*it);

map<int,string>::const_iterator it;
for(it=begin();it!=end();++it)
cout<<it->first>>" ">>it->second>>endl;

string::size_type p=e.find(a);
if(p==string::npos)

bool cmp(const ,const)
return >  //jiangxu
return <//shengxu



string line,str;
getline(cin,line);
stringstream ss(line);
while(line>>str){
	
}

int vis[maxn],fa[maxn],d[maxn];
const int INF=
memset(vis,0,sizeof(vis));
for(int i=0;i<n;i++) if(i==0) d[i]=0;else d[i]=INF;
for(int i=0;i<n;i++){
	int x=0,m=INF;
	for(int j=0;j<n;j++) if(d[j]<m&&vis[j]!=1) {
		m=d[j];
		x=j;
	}
	vis[x]=1;
	for(int j=0;j<n;j++) d[j]=d[j]>d[x]+edge[x][j];
}

//printf



