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
 int k;
 string s;
 cin>>k;
 cin>>s;
 int ar[s.size()][2];
 ar[0][0] = 0;
 ar[0][1] = -1;
 fov(i,s){
 	if(s[i]=='1'){
 		if(i==0) ar[i][0] = 1;
 		else ar[i][0] = ar[i-1][0]+1;
 		ar[i][1] = i;
 	}else{
 		if(i!=0)ar[i][0] = ar[i-1][0];
 		ar[i][1] = ar[i-1][0];
 	}
 }
 int n = s.size()-1, p, c2,c1;
 while(n>=0){
 	c2 = ar[n]
 }
 cout<<ans;
 return 0;
}