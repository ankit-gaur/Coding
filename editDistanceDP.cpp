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

int cadd, creplace, cremove;
string str1, str2;
int answer[2001][2001];

//to convert str1 to str2
int editDistance( int l1, int l2)
{

 	//make table to remember subproblems 

	if(answer[l1][l2]!=-1) return answer[l1][l2];

    if(l1 == 0) return l2; //add all
    if(l2==0)  return l1; //remove all
    
    //l1, l2 are greater than zero now

    if(str1[l1-1] == str2[l2-1]){ // if last char are equal 
    	answer[l1][l2]  =  editDistance(l1-1, l2-1); 
    	return answer[l1][l2];
    }
    

    answer[l1][l2] =  min(cadd + editDistance(l1,l2-1),   min(cremove + editDistance(l1-1,l2) , creplace + editDistance(l1-1, l2-1)));
    return answer[l1][l2];

}

int main()
{  
	int t;
	cin>>t;
	cadd = 1; cremove = 1; creplace = 1;
	while(t--){

		cin>>str1>>str2;
        //cout<<str1.length()<<" "<<str2.length(); el;
		rep(i, 2001)rep(j, 2001) answer[i][j] = -1;

		cout<<editDistance(str1.length(), str2.length());	el;
	} 
	return 0;
}