#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
class Comp{
 public:    
    bool operator()(pair<int,long long int> p1, pair<int,long long int> p2){
        return p1.second>p2.second;
    }
};
int main(){
        const long long int prime = 1000*1000*1000+7;
        int n,s;
        cin>>n>>s;
        vector<pair<int,long long int>> graph[n+1];
        while(true){
            long long int x,y,r;
            cin>>x;
            if(x==0)break;
            cin>>y>>r;
            graph[x].push_back(make_pair(y,r));
            graph[y].push_back(make_pair(x,r));
        }
        long long int cost[n+1];
        fill_n(cost,n+1,-1);
        priority_queue<pair<int,long long int>,vector<pair<int,long long int>>,Comp> q;
        q.push(make_pair(s,0));
        long long int total = 0;
        while(!q.empty()){
            pair<int,long long int> top = q.top();
           // cout<<top.sc<<endl;
            q.pop();
            long long int dist = top.sc;
            long long int p = top.fs;
            if(cost[p]==-1)
            {
                cost[p] = top.sc;
                total+=cost[p];
                cout<<p<<" ";
            }
            else continue;
            for(int i = 0; i<graph[p].size(); i++){
                top = graph[p][i];
                if(cost[top.fs]==-1){
                    q.push(make_pair(top.fs,dist+(long long int)top.sc));
                }
            }  
        }
      /*  for(int i = 1;i<=n;i++){
            if(i!=s)cout<<cost[i]<<" ";
        }*/
        cout<<endl; cout<<total%prime;
    return 0;
}