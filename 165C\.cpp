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
 int temp = 0,r = 0, l = 0, ans = 0;  
 for(int i = 0; i<s.size();i++){
 	if(s[i]='1')temp++;
 	if(temp==k){
 		r=i;
 		ans = 1;
 		break;
 	}
 }
 for(int i=r+1; i<s.size(); i++){
 	if(s[i]=='0')ans++;
 	else{
 		int l2 = l+1;
 		while(l2<v.size()&&s[l2]!='1'){
 			l2++;
 		}
 		ans = l2 - l;
 		l = l2;
 	}
 }
 cout<<ans;
 return 0;
}