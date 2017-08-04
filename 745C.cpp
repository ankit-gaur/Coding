#include<bits/stdc++.h>
using namespace std;

#define V vector

typedef long long int LL;
typedef pair<int, int>  pii;
typedef pair<int, string> pis;

typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vl;
typedef V<double> vd;
typedef V<pii> vpii;
typedef V<vi> viv;  
typedef V<pis> vpis; //******************************************************************

#define forup(i,a,b) for(int i=(a); i<(b); ++i) 
#define fordn(i,a,b) for(int i=(a); i>(b); --i) 
#define rep(i,a) for(int i=0; i<(a); ++i) 
#define fov(i,a) rep(i,(a).size()) 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)  //???????????????????????????????

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

#define el cout<<endl 

#define all(x) (x).begin(), (x).end()  //***************************************************

const int inf = numeric_limits<int>::max(); 
const LL linf = numeric_limits<LL>::max(); 
const double EPS = 1e-7;  
const int MAXN = 10000001; 
const int LOGMAXN = log2(MAXN) + 3;

int main()
{  
	int n,m,k;
	cin>>n>>m>>k;
	bool isHome[n+1];
	fill_n(isHome,n+1,false);
	rep(i,k){
		int x; cin>>x;
		isHome[x] = true;
	}

	vi graph[n+1];
	rep(i,m){
		int a,b;
		cin>>a>>b;
		graph[a].pb(b); graph[b].pb(a);
	}

	int nongovcluster = 0;
	stack<int> s;
	bool isVisited[n+1];
	fill_n(isVisited,n+1,false);
	vi clustCount;
	for(int i = 1; i<n+1; i++){
		
		int clust = 0;

		bool isHomeCluster = false;
		
		if(!isVisited[i]){
			s.push(i);
		}else continue;


		while(!s.empty()){
			int top = s.top();
			if(isVisited[top]){s.pop(); continue;}
			isVisited[top] = true;
			s.pop();
			clust++;
			if(isHome[top]){
				isHomeCluster = true;
			}
			fov(j,graph[top]){
				if(!isVisited[graph[top][j]]){
					s.push(graph[top][j]);
				}
			}			
		}
	//	cout<<"No. of nodes "<<clust; el;
		if(isHomeCluster){
	//		cout<<"Home"; el;
			clustCount.pb(clust);
		}else{
	//		cout<<"not home";el;
			nongovcluster +=clust;
		}

	}

	sort(clustCount.begin(),clustCount.end());

	int ans = 0;
	//cout<<"Non gov cluster "<<nongovcluster;
	int  N = clustCount[k-1]+nongovcluster;
	//cout<<"Total Max "<<N;
	ans += (N*(N-1))/2;
	for(int i = 0; i<clustCount.size()-1; i++){
		ans+= ((clustCount[i]-1)*clustCount[i])/2;
	}
	ans = ans -  m;
	cout<<ans;

	return 0;
}