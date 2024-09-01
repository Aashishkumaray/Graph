#include<bits\stdc++.h>
using namespace std;
#define ll long long int

int find(vector<int>&parent,int a){

    return parent[a]=((parent[a]==a) ? a : find(parent,parent[a]));

}
void Union(vector<int>& par,vector<int>& rank,int a,int b){
    //steps to find [arenyt a,b
    a=find(par,a);
    b=find(par,b);
    if(a==b) return;
    if(rank[a]>= rank[b]){//The tree with a higher rank (greater depth) becomes the parent of the tree with a lower rank.
        rank[a]++;
        par[b]=a;//a is the parent of b
    }
    else{
        rank[b]++;
        par[a]=b;
    }
}
//to edge list we use srtuctutre
struct edge{
    int src;
    int dest;
    int wt;

};
//use for sort the edges on the basis of weight
bool cmp(edge e1,edge e2){
    return e1.wt<e2.wt;
}

ll krushal(vector<edge> &input,int n,int e){
    //input sort
    sort(input.begin(),input.end(),cmp);
    //create dsu
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    //initialize the parent
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int edgecount=0;//n-1
    int i=0;//to check edge is picket
    ll ans=0;
    while(edgecount<n-1 and i<input.size()){
        edge curr=input[i];
        int srcPar=find(parent,curr.src);//we find parent of source
        int desPar=find(parent,curr.dest);//we find parent of dest
        //if srcPar & desPar are different parent these edges with no cycle
        if(srcPar!=desPar){
            //include edge as this will not make cycel
            Union(parent,rank,srcPar,desPar);
            ans+=curr.wt;//ans me we add weight
            edgecount++;
        }
    
    i++;//does matter u picked the last edge or not ,we still need to go to  nect edge

}
return ans;
}
int main(){
int n,e;
cin>>n>>e;
vector<edge> v(e);
for(int i=0;i<e;i++){
    cin>>v[i].src>>v[i].dest>>v[i].wt;
}
cout<<krushal(v,n,e)<<"\n";
return 0;
}