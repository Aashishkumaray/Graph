//Adjacecy list weighted graph
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<pair<int,int>> > graph;
int v;//no. of vertices

//now making connection
void add_edge(int src,int des,int wt,bool bi_dir=true){
    graph[src].push_back({des,wt});//source-to -destination
    if(bi_dir){
        graph[des].push_back({src,wt});//if grap is bidirectinal then destination to source connection
    }
}

//for printing
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<"("<<ele.first<<"  "<<ele.second<<"), ";
        }
        cout<<"\n";
    }
    
}
int main(){
    cout<<"ENter thenumber of vertex";
    cin>>v;
    // graph.size(v, list<int> ());
    graph.resize(v);
    int e;
    cout<<"eneter the edge";
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
}