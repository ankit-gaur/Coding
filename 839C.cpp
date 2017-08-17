#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef long long int LL;
typedef V<int> vi;
typedef V<LL> vl;
typedef V<pair<int ,int>> vpii;

#define rep(i,a) for(int i = 0; i<a ; i++)
#define fov(i,v) rep(i,v.size())
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int main(){
	int n;
	cin>>n;
	vi graph[n+1];
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	bool isvisited[n+1];
	fill_n(isvisited,n+1,false);
	queue<pair<int,pair<int,long double>>> q;
	q.push(make_pair(1,make_pair(0,1.0000)));
	long double ans = 0.00000;0
	while(!q.empty()){
		pair<int,pair<int,long double>> t = q.front();
		q.pop();
		if(!isvisited[t.fs])
		isvisited[t.fs] = true;
		else continue;
		int parent = t.fs;
		int  dist  = t.sc.fs;
		long  double pr = t.sc.sc;
		int sz  = graph[parent].size();
		if(sz ==1&&parent!=1){
			//cout<<"node dist prob "<<parent<<" "<<dist<<" "<<pr<<endl;
			ans+=dist*pr;
			continue;
		}
		fov(i,graph[parent]){
			int temp = sz;
			 if(parent!=1)temp--;
			 // cout<<"size "<<sz<<endl;
			if(!isvisited[graph[parent][i]]){
				q.push(make_pair(graph[parent][i],make_pair(dist+1,pr/temp)));
			}
		}
	}	
	cout<<ans;
	return 0;
}
