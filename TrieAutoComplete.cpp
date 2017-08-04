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

const int alphasize = 26;

#define indexof(c) ((int)c-(int)'a')

struct TrieNode{
	bool isLeaf = false;	
	TrieNode *children[alphasize];
	int maxWeight = 0;
	int maxInd = -1;
};

TrieNode* getNode(){
	TrieNode* temp = (TrieNode*)malloc(sizeof(TrieNode));
	for(int i =0;i<alphasize;i++){
		temp->children[i] = NULL;
	}
	return temp;
}

void insert(TrieNode *root, const string key, const int weight){

	TrieNode *crawler = root;
	for(int level =0;level<key.size(); level++){
		int ind = indexof(key[level]);
		if(crawler->children[ind]==NULL) crawler->children[ind] = getNode();

		if(crawler->maxWeight<weight){
			crawler->maxWeight = weight;
			crawler->maxInd = ind;
		}

		crawler = crawler->children[ind];
	}
	crawler->isLeaf = true;//last char is leaf;

}

bool search(TrieNode * root, const string key){
	TrieNode *crawler = root;
	for(int level = 0; level<key.size(); level++){
		int ind = indexof(key[level]);
		if(crawler->children[ind]==NULL)return false;

		crawler = crawler->children[ind];
	}
	return crawler->isLeaf;
}

int predictWeight(TrieNode *root, const string key){
	TrieNode * crawler = root;
	for(int level = 0; level<key.size(); level++){
		int ind = indexof(key[level]);
		if(crawler->children[ind]==NULL)return -1;
		crawler = crawler->children[ind];
	}

	return crawler->maxWeight;

}	

int main(){
	
	int n,q;
	cin>>n>>q;
	TrieNode *root = getNode();
	while(n--){
		string s; int w;cin>>s>>w;
		insert(root,s,w);
	}
	while(q--){
		string s; cin>>s;
		cout<<predictWeight(root,s)<<endl;
	}			
	return 0;
}
