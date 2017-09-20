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
#define pb push_back

#define el cout<<endl

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
map<string, int> mp;
set<string> visited;
vector<string> graph[100000];
queue<string> ans;
void topsortUtil(string s){
	if(visited.count(s)!=0)return;
	visited.insert(s);
	int i = mp[s];
	fov(j,graph[i]){
		string d = graph[i][j];
		if(visited.count(d)==0)
		{ 
			topsortUtil(d);
		}
	}
	ans.push(s);
}
void topsort(){
	map<string,int>::iterator it;
	for(it = mp.begin();it!=mp.end();++it){
		string s = it->fs;
		if(visited.count(s)==0)topsortUtil(it->fs);
	}
	while(!ans.empty()){
		cout<<ans.front();
		ans.pop();
		if(ans.size()>=1)
		cout<<" -> ";
	}
}

int main(){
	
	int n,m;
	cin>>n>>m;
	int ind = 0;
	rep(i,m){
		string s1,d;
		cin>>s1>>d;
		if(mp.count(s1)==0){
			mp[s1] = ind;
			ind++;
		}
		int j = mp[s1];
		graph[j].pb(d);
	}
	topsort();
    return 0;
}
