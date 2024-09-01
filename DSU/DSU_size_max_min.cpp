#include<iostream>
#include<vector>
using namespace std;

//T.C=O(LOG*n)
int find(vector<int> &parent,int x){
    //This method returns which group/cluster x belongs to
    //path compression is used union by Rank
    return parent[x]=(parent[x]==x) ? x : find(parent,parent[x]);//step of path compression
}

void Union(vector<int> &parent,vector<int> &sz,vector<int> &mx,vector<int>&mn,vector<int> &rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return;//both a and b are in same set
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
        sz[a]+=sz[b];
        mx[a]=max(mx[a],mx[b]);
        mn[a]=min(mn[a],mn[b]);
    }
    else{
        rank[b]++;
        parent[a]=b;
        mn[b]=max(mn[a],mn[b]);
        mn[b]=min(mn[a],mn[b]);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    //n is number of elements,m-> number of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    vector<int> sz(n+1,1);//is used to storethes ize
    vector<int> mx(n+1);//is used to store the maximum element
    vector<int>mn(n+1);//is used to store minimum element
    for(int i=0;i<=n;i++){
        parent[i]=mx[i]=mn[i]=i;
    }
    //loop will iteraye untill number of queries will be run
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,sz,mx,mn,x,y);
        }
        else{//we use find operation
            int x;
            cin>>x;
            x=find(parent,x);
            cout<<x<<"\n";
            cout<<mn[x]<<" "<<mx[x]<<" "<<sz[x];
        }
    }
     
}
