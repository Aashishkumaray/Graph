#include<iostream>
#include<vector>
using namespace std;

//T.C=O(LOG*n)
int find(vector<int> &parent,int x){
    //This method returns which group/cluster x belongs to
    //path compression is used union by Rank
    return parent[x]=(parent[x]==x) ? x : find(parent,parent[x]);//step of path compression
}

void Union(vector<int> &parent,vector<int> &rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return ;//if a and b are in the same set
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    //n is number of elements,m-> number of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    //loop will iteraye untill number of queries will be run
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }
        else{//we use find operation
            int x;
            cin>>x;
            cout<<find(parent,x)<<"\n";
        }
    }
     
}
